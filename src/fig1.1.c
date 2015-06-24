//
// fig1.1.c
//  lib
//
//  Created by sake on 14/11/7.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include <dirent.h>
#include "apue.h"

int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2){
        err_quit("usage: ls direcotry_name");
    }
    if((dp = opendir(argv[1])) == NULL){    //打开目录
        err_sys("can't open %s", argv[1]);
    }
    
    while( (dirp = readdir(dp)) != NULL){   // 读取目录
        printf("%s\n", dirp->d_name);
    }
    
    closedir(dp);
    return 0;
}
