/*
   Copyright 2018 Clemens Jonischkeit

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

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <pthread.h>
#include "backend_if.h"
#include "backend.h"

int lauSim_caps = SUBSYS_NET;
unsigned long lauSim_net_status = 0;
pthread_t lauSim_thr;

struct {
    int (*socket) (int domain, int type, int protocol);
    int (*close) (int fd);
} lauSim_hooks;

int lauSim_switch_net(unsigned long severity) {
    if (lauSim_net_status == 0 && severity != 0) {
        // TODO disable network
        lauSim_net_status = 1;
        return 0;
    }

    if (lauSim_net_status != 0 && severity == 0) {
        // TODO enable network
        lauSim_net_status = 0;
        return 0;
    }

    // nothing to do
    return 0;
}

void lauSim_cleanup_net() {
    lauSim_switch_net(0);
}

void lauSim_cleanup() {
    lauSim_cleanup_net();
    // TODO cleanup mem and pwr
}

int lauSim_set_state(enum en_subsys sys, unsigned long severity) {
    int res;
    switch (sys) {
    case SUBSYS_NET:
        res = lauSim_switch_net(severity);
        break;
    case SUBSYS_PWR:
    case SUBSYS_MEM:
        // TODO implement
        res = 0;
        break;
    default:
        res = 1;
        break;
    }
    return res;
}

void *lauSim_resolve(const char *fun) {
    void *sym;

    sym = dlsym(RTLD_NEXT, fun);
    if (sym == NULL) {
        fprintf(stderr, "[FATAL] [lauSim] Error while resolving %s: %s\n", fun, dlerror());
        exit(1);
    }

    return sym;
}

void *lauSim_run_main(void *ign) {
    exit(lauSim_main(0, NULL));
    return NULL;
}

int __attribute__((constructor)) init_hooks() {
    lauSim_hooks.socket = lauSim_resolve("socket");
    lauSim_hooks.close = lauSim_resolve("close");
    pthread_create(&lauSim_thr, NULL, lauSim_run_main, NULL);
    return 0;
}

int __attribute__((destructor)) lauSim_hook_cleanup() {
    lauSim_req_close = 1;
    pthread_join(lauSim_thr, NULL);
    return 0;
}