ifdef OS
	RM = del
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
	endif
endif

CC = g++
CFLAGS = -std=c++11

all: exception/ParserException.cpp parser/allFF.cpp parser/CIDRMask.cpp parser/dtoi.cpp parser/equal.cpp parser/IP.cpp parser/IPNet.cpp parser/IPv4.cpp parser/parseCIDR.cpp parser/parseIP.cpp parser/parseIPv4.cpp parser/parseIPv6.cpp parser/Print.cpp parser/xtoi.cpp
	$(CC) $(CFLAGS) $(file) $?

clean:
	$(RM) examples\*.exe examples\*.out exceptions\*.gch parser\*.gch