//
//  fig1.6.c
//  lib
//
//  Created by sake on 14/11/8.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include "apue.h"
#include <errno.h>

int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}