/*************************************************************************
	> File Name: mmap_w_ipc.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月30日 星期三 19时59分52秒
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main(){
    int fd = open("mmapTest.txt", O_RDWR | O_CREAT, 0644);

    void *ptr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(ptr == MAP_FAILED){
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    while(1){
        char *p = (char *)ptr;
        p  = p + 1024;
        strcpy(p, "hello parent, i am your friend!!!\n");
    }

    //release
    int ret = munmap(ptr, 4096);
    if(ret == -1){
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
