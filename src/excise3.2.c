#include "apue.h"
#include <unistd.h>
#include <limits.h>

int my_dup2(int filedes, int filedes2) {
    int fd;         // temp file descriptor
    int *fds;       // the list of file descriptor we open before we get filedes2
    int opc = 0;    // the number of file descriptor we open before we get filedes2
    
    if ((fd = dup(filedes)) < 0) { // if filedes is an incorrect descriptor that we can't dup;
        err_sys("filedes %d is incorrect\n", filedes);
        return -1;
    } else {
        close(fd);  // close temp file descriptor
    }
    
    if ((fd = dup(filedes2)) > 0) { // if filedes2 is opened, we should close it
        close(fd);
        close(filedes);
    }

    fds = (int *)malloc(filedes2 * sizeof(int)); //max number file descripotr we need open
    
    while ((fd = dup(filedes)) > 0) {
        if (fd == filedes2) {
            break;
        }else if (fd > filedes2) { // if the last file descriptor is larger than filedes2, must be sth. wrong.
            close(fd);
            filedes2 = -1;
            break;
        } else {
            fds[opc++] = fd;
        }
    }

    // here we close all file descriptor we opened except for filedesc2
    for (int i = 0; i < opc; i ++) {
        close(fds[i]);
    }

    free(fds);
   
    // return new file descriptor
    return filedes2;
}


int main(int argc, char const *argv[]){
    int fd;
    
    if (argc != 3) {
        err_quit("usage: a.out <desctriptor1> <desctriptor2>");
    }
   
    if ((fd = my_dup2(atoi(argv[1]), atoi(argv[2]))) != atoi(argv[2])) {
        err_msg("dup2 failed\n");
    } else {
        printf("dup2 success");
    }
  
    
    exit(0);
}
