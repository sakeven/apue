//
//  fig1.4.c
//  lib
//
//  Created by sake on 14/11/7.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    printf("hello world from process ID %d\n",getpid());
    exit(0);
}
