//
//  fig1.5.c
//  lib
//
//  Created by sake on 14/11/8.
//  Copyright (c) 2014年 sake. All rights reserved.
//

#include "apue.h"
#include <sys/wait.h>

int
main(void)
{
    char	buf[MAXLINE];	/* from apue.h */
    pid_t	pid;
    int		status;
    
    printf("%% ");	/* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */
        
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {		/* child */
            execlp(buf, buf, (char *)0);
            sleep(2);
            err_ret("couldn't execute: %s", buf);
           
            exit(0);
        }
        
        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }
    exit(0);
}
