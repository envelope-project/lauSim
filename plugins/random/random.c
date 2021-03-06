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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <lausim/logger.h>
#include "random.h"

int num = -1;
mynode **nodes;

int num_fault;
fault **faults;

logger *logg;
size_t id;

int get_nodes(size_t *num_nodes, node ***lau_nodes) {
    if (num <= 0)
        return -1;
    *num_nodes = num;
    *lau_nodes = (node **) nodes;
    return 0;
}

void free_faults() {
    int i;
    for (i = 0; i < num_fault; i++) {
        free(faults[i]);
    }
    free(faults);
}

void tic(){
    int i;

    // free previous faults
    free_faults();
    faults = NULL;
    num_fault = 0;   
    
    for (i = 0; i < num; i++) {
        if (nodes[i]->healthy && rand() < prob) {
            nodes[i]->healthy = 0;
            // make room for an additional fault
            faults = realloc(faults, (num_fault + 1) * sizeof(fault*));
            if (faults == NULL) {
                num_fault = 0;
                return;
            }
            // allocate and zero the structure
            faults[num_fault] = calloc(1, sizeof(fault));
            // fill in all the values
            faults[num_fault]->id = nodes[i]->p.id;
            faults[num_fault]->name = "node-failed";
            faults[num_fault]->component = NULL;
            faults[num_fault]->node = nodes[i]->p.name;
            faults[num_fault]->severity = 100;
            num_fault++;
        }
    }
}

int get_fail(fault ***failed){
    *failed = faults;
    return num_fault;
}

int inject_fail(fault* f) {
    puts("[ERROR] Fault injection is not supportet");
    return 1;
}

fault_manager fm = {
    1,          // version
    get_nodes,
    tic,
    get_fail,
    inject_fail
};

fault_manager *get_fm() {
    return &fm;
}

int init(const plugin_manager_interface *inter, int argc, char **argv) {
    int i;
    char buf[512];
    logg = inter->get_logger();

    if (inter->version != PL_INTF_VERSION) {
        logg->log_fun(LL_Error, "[RANDOM] Plugin interface version missmatch");
        return 1;
    }

    for (int n = 0; n < argc; n++) {
        snprintf(buf, sizeof(buf), "[RANDOM] Arg #%d: %s", n, argv[n]);
        logg->log_fun(LL_Debug, buf);
    }

    if (argc < 1) {
        logg->log_fun(LL_Error, "[RANDOM] No node number is specifyed");
        return -1;
    }

    num = strtol(argv[0], NULL, 0);

    if (num < 0) {
        logg->log_fun(LL_Error, "[RANDOM] invalid number of nodes");
        return -1;
    }

    snprintf(buf, sizeof(buf), "[RANDOM] creating %d nodes", num);
    logg->log_fun(LL_Debug, buf);

    nodes = calloc(num, sizeof(node*));
    for (i = 0; i < num; i++) {
        nodes[i] = calloc(1, sizeof(mynode));
        if (nodes[i] == NULL)
            return -1;
        nodes[i]->p.name = malloc(0x40);
        if (nodes[i]->p.name == NULL)
            return -1;
        snprintf(nodes[i]->p.name, 0x40, "node%d", i);
        nodes[i]->p.type = uniform_node;
        nodes[i]->p.num_components = 0;
        nodes[i]->p.components = NULL;
        nodes[i]->healthy = 1;
    }

    inter->register_plugin(&random_plugin);

    return 0;
}

int cleanup() {
    int i;
    free_faults();
    for (i = 0; i < num; i++){
        free(nodes[i]->p.name);
        free(nodes[i]);
    }
    free(nodes);
    return 0;
}