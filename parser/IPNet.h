#ifndef IP_PARSER_PARSER_IP_NET
#define IP_PARSER_PARSER_IP_NET

#include "./IP.h"
#include "./IPMask.h"

class IPNet {
    public:
        IP net_ip;
        IPMask mask;
};

#endif