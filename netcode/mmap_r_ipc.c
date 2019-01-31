/*************************************************************************
	> File Name: mmap_r_ipc.c
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

int main(){
    //0644 & ~umask
    int fd = open("mmapTest.txt", O_RDWR | O_CREAT, 0644);
    ftruncate(fd, 4096);
    int len = lseek(fd, 0, SEEK_END);

    void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(ptr == MAP_FAILED){
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    while(1){
        sleep(1);
        printf("%s\n", (char *)ptr + 1024);
    }

    //release
    int ret = munmap(ptr, len);
    if(ret == -1){
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}
