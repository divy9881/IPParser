#include <iostream>

#include "../parser/IP.h" // class IP
#include "../parser/CIDR.h" // class CIDR
#include "../parser/parseIP.h" // function parseIP()
#include "../parser/parseCIDR.h" // function parseCIDR()

using namespace std;

int main() {
    IP ip = parseIP("192.168.2.123");
    CIDR cidr1 = parseCIDR("192.168.2.0/24");
    CIDR cidr2 = parseCIDR("192.168.3.0/24");
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    cout<< "Does given CIDR1 contains IP => " << cidr1.net.contains(ip) <<endl;
    cout<< "Does given CIDR2 contains IP => " << cidr2.net.contains(ip) <<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
}