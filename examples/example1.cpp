#include <iostream>

#include "../parser/parseIP.h" // function parseIP()
#include "../parser/IP.h" // class IP

using namespace std;

int main() {
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    IP ip1 = parseIP("192.168.2.123");
    cout << "Status : " << ip1.isLegal <<endl;
    cout << ip1.toString() <<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
}