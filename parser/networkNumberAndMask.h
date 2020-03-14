#ifndef IP_PARSER_PARSER_NETWORK_NUMBER_AND_MASK
#define IP_PARSER_PARSER_NETWORK_NUMBER_AND_MASK

#include <utility>

#include "./IPNet.h"
#include "./byte.h"
#include "./IP.h"
#include "./IPMask.h"

pair<IP, IPMask> networkNumberAndMask(IPNet n) {
    IP newIp;
    pair <IP, IPMask> p;
    newIp = n.net_ip.To4();
	if(newIp.isLegal == false) {
		newIp = n.net_ip;
		if(newIp.ip.size() != IP :: IPv6len) {
            p.first.isLegal = false;
			return p;
		}
	}

	IPMask m = n.mask;
    const byte ipv4len = IP :: IPv4len;
    const byte ipv6len = IP :: IPv6len;

    if(m.size() == ipv4len){
        if(newIp.ip.size() != IP :: IPv4len) {
            p.first.isLegal = false;
		    return p;
        }
    } else if(m.size() == ipv6len){
        if(newIp.ip.size() == IP :: IPv4len) {
            IPMask newM(m.begin() + 12, m.end());
            m = newM;
            p.second = m;
            return p;
        }
    } else {
        p.first.isLegal = false;
		return p;
    }

}

#endif