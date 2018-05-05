#include <cstdio>
#include <iostream>
using namespace std;

#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "hello/hello.h"

using namespace std;

namespace hellons {

typedef int int128 __attribute__((mode(TI)));

void hello()
{
    cout << "Hello world!\n";
    cout << "\n";
    cout << "sizeof(char) = " << sizeof(char) << "\n";
    cout << "sizeof(short) = " << sizeof(short) << "\n";
    cout << "sizeof(int) = " << sizeof(int) << "\n";
    cout << "sizeof(long) = " << sizeof(long) << "\n";
    cout << "sizeof(long long) = " << sizeof(long long) << "\n";
    cout << "sizeof(int128) = " << sizeof(int128) << "\n";
    cout << "sizeof(intmax_t) = " << sizeof(intmax_t) << "\n";
    cout << "sizeof(uintptr_t) = " << sizeof(uintptr_t) << "\n";
    cout << "\n";
    cout << "sizeof(float) = " << sizeof(float) << "\n";
    cout << "sizeof(double) = " << sizeof(double) << "\n";
    cout << "\n";
    cout << "sizeof(uint_fast8_t) = " << sizeof(uint_fast8_t) << "\n";
    cout << "sizeof(uint_fast16_t) = " << sizeof(uint_fast16_t) << "\n";
    cout << "sizeof(uint_fast32_t) = " << sizeof(uint_fast32_t) << "\n";
    cout << "sizeof(uint_fast64_t) = " << sizeof(uint_fast64_t) << "\n";
    cout << "\n";
    cout << "sizeof(addrinfo) = " << sizeof(addrinfo) << "\n";
    cout << "sizeof(sockaddr) = " << sizeof(sockaddr) << "\n";
    cout << "sizeof(sockaddr_in) = " << sizeof(sockaddr_in) << "\n";
    cout << "sizeof(in_addr) = " << sizeof(in_addr) << "\n";
    cout << "sizeof(sockaddr_in6) = " << sizeof(sockaddr_in6) << "\n";
    cout << "sizeof(in6_addr) = " << sizeof(in6_addr) << "\n";
    cout << "sizeof(sockaddr_storage) = " << sizeof(sockaddr_storage) << "\n";
    cout << "INET_ADDRSTRLEN = " << INET_ADDRSTRLEN << "\n";
    cout << "INET6_ADDRSTRLEN = " << INET6_ADDRSTRLEN << "\n";
    cout << "\n";
}

/*
 * ofiles.c - Displays the number of open files for its own process
 * Copyright (C) 2005 Michael Cutler <m@cotdp.com>
 *
 */
void printLimits()
{
    int i = 0;
    int fd_counter = 0;
    int max_fd_number = 0;
    struct stat stats;
    struct rlimit rlimits;
    max_fd_number = getdtablesize();
    getrlimit(RLIMIT_NOFILE, &rlimits);
    cout << "max_fd_number: " << max_fd_number << "\n";
    cout << "     rlim_cur: " << rlimits.rlim_cur << "\n";
    cout << "     rlim_max: " << rlimits.rlim_max << "\n";
    for (i = 0; i <= max_fd_number; i++)
    {
        fstat(i, &stats);
        if ( errno != EBADF)
        {
            fd_counter++;
        }
    }
    cout << "   open files: " << fd_counter << "\n";
}

}
