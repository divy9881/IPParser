#include <iostream>

#include "../parser/parseCIDR.h"
#include "../parser/CIDR.h"

using namespace std;

int main() {
    CIDR cidr = parseCIDR("192.168.2.123/24");
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    cout << "Host IP : " << cidr.ip.toString() <<endl;
    cout << "Network IP : " << cidr.net.NETIP_toString() <<endl;
    cout << "Network Mask : " << cidr.net.IPMask_toString() <<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
}