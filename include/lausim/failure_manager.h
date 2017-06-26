/*
 * @Author: C. Jonischkeit 
 * @Date: 2017-06-26 14:20:59 
 * @Last Modified by:   D. Yang 
 * @Last Modified time: 2017-06-26 14:20:59 
 */
#ifndef FAILURE_MANAGER_H
#define FAILURE_MANAGER_H

#include "node.h"
#include "types.h"

#ifdef __cpluplus
namespace lauSim {
extern "C" {
#endif  //__cplusplus

typedef struct tag_failure{
    int id;
    char *name;
    char *component;
    char *node;
    unsigned severity;
    unsigned char degree; /* currently unused, assume always 100 */
} failure;


/**
    Graph structure for storing the corresponding node
    failure transition graph. 
    A node fail affects all other nodes with a connection 
    by a specific fault propagation probability. 
*/
typedef struct tag_topology{
    int dimension;
    rate_t ** propagation_matrix;
} topology;

typedef struct tag_failure_manager{
	/**
	  For storing the current failure manager version
	*/
	int version;

    /**
     *  Nodes are configured and handeled in the failure manager, but to
     *  notify the end points the nodes also have to be known to the simultor
     *  this function asks for all nodes and their components
     *  ownership is shared by the failure manager and the lausim core
     *  The memory is assumed to stay valid until the cleanup function of the module
     *  is called, when this memory should be freed by the failure manager
     *  (the ownership is still subject to be changed)
     *  param num_nodes output: the number of nodes
     *  param nodes output: the nodes
     *  return 0 on success
     */
    int (*get_nodes)(size_t *num_nodes, node *nodes[]);

    /**
     *  Advances the time by one tic. It is caled in regular intervals
     *  however no implication is made on the simulated timespan
     */
    void (*tic) ();

    /**
     *  this functions asks the manager if and which nodes have failed
     *  param failed the node and component that failed (output)
     *  result 0 if a node failed, anything else if no node failed
     */
    int (*get_fail)(failure *failed);


    int (*inject_fail)(failure* f);
} failure_manager;

#ifdef __cpluplus
}
}
#endif

#endif
