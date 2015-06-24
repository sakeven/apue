//
//  fig1.2.c
//  lib
//
//  Created by sake on 14/11/7.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include "apue.h"

#define BUFFSIZE 4096

int
main(void)
{
    ssize_t n;
    char buf[BUFFSIZE];
    
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            err_sys("write error");
        }
    }
    
    if (n < 0) {
        err_sys("read error");
    }
    exit(0);
}