/*
   Copyright 2017 Clemens Jonischkeit

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <mutex>
#include <string>
#include <unistd.h>

#include "com_mosquitto.h"

#define HOST_NAME_MAX 255
#define LAST_WILL_TOPIC "last_will"
#define back_topic "envelope/master/#"

namespace lauSim {
static bool init_state = false;
ComMosquitto *instance = nullptr;
logger *log;

int notify_fail (const char *, const char *, unsigned);
int notify_extern (const char *, unsigned);
msg_callback set_callback(msg_callback);
plugin_manager_interface* pi;

com com_interface{
    COM_ASYNC,
    notify_fail,   // notify_fail
    notify_extern,  // notify_extern
    nullptr,
    set_callback,
    nullptr
};

int
ComMosquitto::init_mosquitto() {
    int ret = 0;
    if (!init_state) {
        ret = mosqpp::lib_init();
        if (!ret)
            init_state = true;
        
    }
    log->log_fun(LL_Debug, "[MQTT] lib initialized");
    return ret;
}

int
ComMosquitto::cleanup_mosquitto() {
    int ret = 0;
    if (init_state) {
        ret = mosqpp::lib_cleanup();
    }
    log->log_fun(LL_Debug, "[MQTT] lib cleanup");
    return ret;
}

int ComMosquitto::init(const char * addr, int port, unsigned keep_alive) {
    int msqerr;

    if (is_init || !init_state)
        return -1;
    log->log_fun(LL_Debug, "[MQTT] connecting");
    if ((msqerr = connect(addr, port, keep_alive))) {
        log->log_fun(LL_Error, mosqpp::strerror(msqerr));
        return -1;
    }
    log->log_fun(LL_Debug, "[MQTT] connected");
    if ((msqerr = subscribe(nullptr, back_topic, 0)) != MOSQ_ERR_SUCCESS) {
        log->log_fun(LL_Warning, mosqpp::strerror(msqerr));
    }
    will_set(LAST_WILL_TOPIC, id.length(), id.c_str());
    is_init = true;
    return 0;
}

int ComMosquitto::notify_fail(const char *target, const char *cmp, unsigned severity){
    std::stringstream topic;
    std::stringstream msg_buf;
    std::string msg;
    int msqerr;

    if (!is_init)
        return false;
    topic << "envelope/" << target;
    if (cmp != nullptr)
        topic << "/" << cmp;
    msg_buf << "0x" << std::hex << severity;
    msg = msg_buf.str();
    log->log_fun(LL_Debug, "sending msg");
    if ((msqerr = publish(NULL, topic.str().c_str(), msg.length(), msg.c_str()))) {
        log->log_fun(LL_Error, mosqpp::strerror(msqerr));
        return -1;
    }
    return 0;
}

int ComMosquitto::notify_extern(const char *msg, unsigned length) {
    if (!is_init)
        return 1;
    publish(NULL, "envelope/lausim", length, msg);
    return 0;
}

ComMosquitto::ComMosquitto(const char *id) : mosquittopp(id), is_init(false), lausim_callback(nullptr){
    this->id = std::string(id);
}

ComMosquitto::~ComMosquitto() {
    this->~mosquittopp();
}

extern "C" int init (const plugin_manager_interface* pli, int argc, char **argv) {
    pi = (plugin_manager_interface*) pli;
    int sc;

    if (argc == 0) {
        log->log_fun(LL_Error, "[MQTT] id required");
        return 1;
    }

    if (pli->version != PL_INTF_VERSION) {
        std::cerr << "[MQTT] Plugin Interface Version Missmatch" << std::endl;
        return 1;
    }

    log = pli->get_logger();
    
    ComMosquitto::init_mosquitto();

    instance = new ComMosquitto(argv[0]);

    switch (argc) {
        case 1:
            sc = instance->init();
            break;
        case 2:
            sc = instance->init(argv[1]);
            break;
        case 3:
            sc = instance->init(argv[1], strtoul(argv[2], nullptr, 0));
            break;
        default:
            sc = instance->init(argv[1], strtoul(argv[2], nullptr, 0), strtoul(argv[3], nullptr, 0));
            break;
    }

    if (sc) {
        log->log_fun(LL_Error, "[MQTT] initialization failed");
        return sc;
    }

    log->log_fun(LL_Debug, "[MQTT] init finished");

    if (pli->register_plugin(&mosquitto_plugin)){
        ComMosquitto::cleanup_mosquitto();
        return 1;
    }

    return 0;
}

void ComMosquitto::cleanup(){
    if (is_init) {
        disconnect();
        loop_stop();
    }
}

int post_init() {
    log = pi->get_logger();
    instance->loop_start();
    return 0;
}

int cleanup() {
    instance->cleanup();
    delete instance;
    ComMosquitto::cleanup_mosquitto();
    return 0;
}

com *get_com() {
    return &com_interface;
}

int notify_fail(const char *node, const char *component, unsigned severity) {
    return instance->notify_fail(node, component, severity);
}

int notify_extern(const char *node, unsigned length) {
    return instance->notify_extern(node, length);
}

msg_callback set_callback(msg_callback cb) {
    return instance->set_callback(cb);
}

msg_callback ComMosquitto::set_callback(msg_callback cb) {
    msg_callback old;
    std::lock_guard<std::mutex> guard(backchannel_mutex);
    old = lausim_callback;
    lausim_callback = cb;
    return old;
}

/*
void ComMosquitto::on_connect(int rc) {
    log->log_fun(LL_Debug, "[MQTT] connected");
}

void ComMosquitto::on_subscribe(int lmid, int, const int*) {
    log->log_fun(LL_Debug, "[MQTT] subscribed to channel");
}
*/

void ComMosquitto::on_message(const struct mosquitto_message *msg) {
    size_t len;
    uint8_t *msg_fwd;
    log->log_fun(LL_Debug, "[MQTT] message received");
    if (msg->payloadlen <= 0 || lausim_callback == nullptr)
        return;
    len = msg->payloadlen;
    msg_fwd = new uint8_t[len];
    memcpy(msg_fwd, msg->payload, len);
    std::unique_lock<std::mutex> lock(backchannel_mutex);
    lausim_callback(msg_fwd, len);
    lock.unlock();
    delete[] msg_fwd;
}
}