# IPParser
C++ library for parsing IPv4, IPv6 and CIDR addresses.

## Table of contents

- [Parsing IP addresses](#parsing-ip-addresses)
- [Parsing CIDR addresses](#parsing-ip-addresses)
- [Equality of IP addresses](#equality-of-ip-addresses)
- [CIDR contains IP](#cidr-contains-ip)

## Parsing IP addresses

```
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
```

## Parsing CIDR addresses

```
#include <iostream>

#include "../parser/parseCIDR.h" // function parseCIDR()
#include "../parser/CIDR.h" // class CIDR

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
```

## Equality of IP addresses

```
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
```

## CIDR contains IP

```
#include <iostream>

#include "../parser/IP.h" // class IP
#include "../parser/CIDR.h" // class CIDR
#include "../parser/parseIP.h" // function parseIP()
#include "../parser/parseCIDR.h" // function parseCIDR()

using namespace std;

int main() {
    IP ip = parseIP("192.168.2.123");
    CIDR cidr1 = parseCIDR("192.168.2.123/24");
    CIDR cidr2 = parseCIDR("192.168.3.123/24");
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    cout<< "Does given CIDR1 contains IP => " << cidr1.net.contains(ip) <<endl;
    cout<< "Does given CIDR2 contains IP => " << cidr2.net.contains(ip) <<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
}
```

## License

This project is licensed under the [Apache 2.0 license](LICENSE).

## Contact

If you have any issues or feature requests, please contact me. PR is welcomed.
- https://github.com/divy9881/IPParser/issues
