#ifndef COM_MOSQUITTO_H
#define COM_MOSQUITTO_H

#include "../com.h"
#include "../node.h"
#include "../component.h"
#include <mosquittopp.h>

namespace lauSim {

class ComMosquitto : public com {
public:
    static int init_mosquitto();
    static int cleanup_mosquitto();
    ComMosquitto();
    int init(const char * client_id, const char * address = "localhost", int port = 1883, unsigned keep_alive = 60);
    virtual bool send_fail(Node *target, Component *cmp, failure_type *type, unsigned severity);
private:
    mosqpp::mosquittopp con;
    std::string hostname;
    bool is_init;
};

}

#endif