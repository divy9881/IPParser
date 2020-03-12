#include <iostream>

#include "../parser/parseIP.h" // function parseIP()
#include "../parser/IP.h" // class IP

using namespace std;

int main() {
    IP ip1 = parseIP("192.168.2.123");
    IP ip2 = parseIP("192.168.2.123");
    IP ip3 = parseIP("192.168.2.12");
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    cout << "IP1 == IP2 => " << ip1.Equal(ip2) <<endl;
    cout << "IP1 == IP3 => " << ip1.Equal(ip3) <<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
}