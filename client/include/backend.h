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

/** \file */

#ifndef BACKEND_H
#define BACKEND_H

/**
 * an fd that signals the main loop that it should exit.
 * The program shall terminate if data is available on this fd
 */
extern volatile int lauSim_req_close_fd;

/**
 * initializes the part of the backend, that is not dependent on the
 * methode used (like opening the fifo and stalling until the start
 * signal is received)
 */
int lauSim_init(int argc, char **argv);

/**
 * main loop of the backend dispatching the update state methodes
 */
int lauSim_main();

/**
 * cleanup of the backend
 */
void lauSim_backend_cleanup();

#endif