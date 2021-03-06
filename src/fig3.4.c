//
// fig1.1.c
//  lib
//
//  Created by sake on 14/11/7.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include <fcntl.h>
#include "apue.h"

int main(int argc, char const *argv[])
{
    int val;
    
    if (argc != 2){
        printf("%d\n", argc);
        err_quit("usage: a.out < descriptor#>");
    }
    
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        err_sys("fcntl error for fd %d", atoi(argv[1]));
    }
    
    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        default:
            err_dump("unknow access mode");
    }
    
    if (val & O_APPEND) {
        printf(", append");
    }
    
    if (val & O_NONBLOCK) {
        printf(", nonblocking");
    }
    
#if defined(O_SYNC)
    if (val &O_SYNC){
        printf(", synchronous writes");
    }
#endif
    
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)
    if (val & O_FSYNC) {
        printf(", synchronous writes");
    }
#endif
    putchar('\n');
    exit(0);
}
