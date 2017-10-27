/*
 * @Author: C. Jonischkeit 
 * @Date: 2017-07-17 13:00:25
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstring>
#include <vector>
#include <utility>

#include "config.h"
using namespace lauSim;

#define config_id 0x0
#define libs_id 0x1
#define none_id 0xFFFF
#define decl_id 0x100

std::vector<std::pair<std::string,int>> tokenids =
    {
        {"[library]", libs_id},
        {"[lib]", libs_id},
        {"[libs]", libs_id},
        {"[config]", config_id},
        {"com-actor", com_actor_id},
        {"com_actor", com_actor_id},
        {"actor", com_actor_id},
        {"com-notify", com_notify_id},
        {"com_notify", com_notify_id},
        {"notify", com_notify_id},
        {"com", com_all_id},
        {"logger", logger_id},
        {"log", logger_id},
        {"fault-manager", manager_id},
        {"fault_manager", manager_id},
        {"fault", manager_id},
        {"manager", manager_id},
        {"tic", tic_id},
        {"tik", tic_id}
    };

int get_token_identifyer(const std::string &tk) {
    for (std::pair<std::string, int> &item: tokenids) {
        if (0 == strcasecmp(tk.c_str(), item.first.c_str()))
            return item.second;
    }
    return none_id;
}

int config::set_config(int id, std::stringstream &stream, plugin_manager *manager){
    std::string value;
    plugin *plugin;

    if (!(stream >> value) || value != "="){
        manager->logger_used->log_fun(LL_Error, "'=' expected in assignment");
        return -1;
    }

    if (!(stream >> value)) {
        manager->logger_used->log_fun(LL_Error, "expected assignment before end of line");
        return -1;
    }

    if (id != tic_id)
        plugin = manager->get_by_name(value.c_str());

    if (id != tic_id && plugin == nullptr) {
        manager->logger_used->log_fun(LL_Error, (std::string("plugin \"") + value + std::string("\" is not loaded")).c_str());
        return -1;
    }

    switch(id){
    case com_all_id:
    case com_actor_id:
        if (com_actor != nullptr)
            manager->logger_used->log_fun(LL_Warning, "com actor is reassigned");
        if (HAS_PL_TYPE(*plugin, PL_COM_ACTOR))
            com_actor = plugin;
        else {
            manager->logger_used->log_fun(LL_Error, (std::string("plugin \"") + std::string(plugin->name) + std::string("\" is not a com plugin")).c_str());
            return -1;
        }
        if (id == com_actor_id)
            break;
        /* fall through */
    case com_notify_id:
        if (com_notify != nullptr)
            manager->logger_used->log_fun(LL_Warning, "com notify is reassigned");
        if (HAS_PL_TYPE(*plugin, PL_COM_EXTERN))
            com_notify = plugin;
        else {
            manager->logger_used->log_fun(LL_Error, (std::string("plugin \"") + std::string(plugin->name) + std::string("\" is not a com plugin")).c_str());
            return -1;
        }
        break;
    case logger_id:
        if (logger != nullptr)
            manager->logger_used->log_fun(LL_Warning, "logger is reassigned");
        if (HAS_PL_TYPE(*plugin, PL_LOGGER))
            logger = plugin;
        else {
            manager->logger_used->log_fun(LL_Error, (std::string("plugin \"") + std::string(plugin->name) + std::string("\" is not a logger plugin")).c_str());
            return -1;
        }
        break;
    case manager_id:
        if (this->manager != nullptr)
            manager->logger_used->log_fun(LL_Warning, "fault manager is reassigned");
        if (HAS_PL_TYPE(*plugin, PL_FAULT_MANAGER))
            this->manager = plugin;
        else {
            manager->logger_used->log_fun(LL_Error, (std::string("plugin \"") + std::string(plugin->name) + std::string("\" is not a fault manager plugin")).c_str());
            return -1;
        }
        break;
    case tic_id:
        if (tic_length != 0)
            manager->logger_used->log_fun(LL_Warning, "tic length is reassigned");
        tic_length = std::stoul(value);
    }
    return 0;
}

int config::load_lib(const std::string &name, std::stringstream &args, plugin_manager *manager) {
    std::vector<std::string> argv;
    char **cargs;
    int retv;
    std::copy(std::istream_iterator<std::string>(args),
              std::istream_iterator<std::string>(),
              std::back_inserter(argv));
    
    cargs = new char*[argv.size()];
    for (unsigned int i = 0; i < argv.size(); i++) {
        cargs[i] = (char*) argv[i].c_str();
    }

    retv = manager->load_library((char *) name.c_str(), argv.size(), cargs);
    delete[] cargs;
    return retv;
}

int config::load_config(char *filename, plugin_manager *manager) {
    uint8_t state = 0;
    std::string line;
    std::ifstream conf_file;
    
    conf_file.open(filename, std::ios::in);

    if (!conf_file.is_open()) {
        manager->logger_used->log_fun(LL_Error, "unable to open configuration file!");
        return -1;
    }

    while (std::getline(conf_file, line)) {
        std::stringstream linestr(line);
        std::string token;
        int id;

        manager->logger_used->log_fun(LL_Debug, (std::string("Line: ") + line).c_str());
        // skip empty lines
        if (line.empty())
            continue;

        linestr >> token;
        if (token.empty() || token.at(0) == '#')
            continue;
        id = get_token_identifyer(token);

        // if it is not a declaration or none
        if ((id & decl_id) == 0) {
            // update the state
            state = (1 << id);
            continue;
        }

        // if we are in loading lib state
        if (state == (1 << libs_id)) {
            // loab the lib
            if(load_lib(token, linestr, manager))
                return -1;
            continue;
        }

        // else update the config accordingly
        if(set_config(id, linestr, manager))
            return -1;
    }
    return 0;
}
