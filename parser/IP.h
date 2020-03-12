#ifndef IP_PARSER_PARSER_IP
#define IP_PARSER_PARSER_IP

#include <vector>

#include "./allFF.h"
#include "./IPMask.h"
#include "./equal.h"
#include "./byte.h"

using namespace std;

class IP {
    public:
        vector <byte> ip;
        bool isLegal;
        static byte IPv4len;
        static byte IPv6len;
        static IPMask v4InV6Prefix;

        IP Mask(IPMask mask) {
            IPMask mask_2(mask.begin(), mask.begin()+12);
            if(mask.size() == IPv6len && ip.size() == IPv4len && allFF(mask_2)) {
                IPMask mask_3(mask.begin()+12, mask.begin() + mask.size() - 12);
                mask = mask_3;
            }
            IPMask ip_2(ip.begin(), ip.begin() + 12);
            if(mask.size() == IPv4len && ip.size() == IPv6len && equal(ip_2, v4InV6Prefix)) {
                IPMask ip_3(ip.begin()+12, ip.begin() + mask.size() - 12);
                ip = ip_3;
            }
            unsigned int n = ip.size();
            if(n != mask.size()) {
                IP ip_mask;
                ip_mask.isLegal = false;
                return ip_mask;
            }
            IP out;
            out.isLegal = true;
            for(int i = 0; i < n; i++) {
                out.ip[i] = ip[i] & mask[i];
            }
            return out;
        }
};

byte IP :: IPv4len = 4;
byte IP :: IPv6len = 16;
IPMask IP :: v4InV6Prefix{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xff, 0xff};

#endif