#ifndef IP_PARSER_PARSER_IS_ZEROES
#define IP_PARSER_PARSER_IS_ZEROES

#include "./IP.h"

// Is p all zeros?
bool isZeros(IP p) {
	for(int i = 0 ; i < p.ip.size() ; i++ ) {
		if(p.ip[i] != 0) {
			return false;
		}
	}
	return true;
}

#endif