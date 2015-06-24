//
//  fig1.3.c
//  lib
//
//  Created by sake on 14/11/7.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include "apue.h"

int
main(void)
{
    int c;
    
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            err_sys("output error");
        }
    }
    
    if (ferror(stdin)) {
        err_sys("input error");
    }
    
    exit(0);
}