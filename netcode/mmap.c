/*************************************************************************
	> File Name: named_mmap.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月24日 星期四 21时08分42秒
 ************************************************************************/
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


int main(){
    int i;
    //创建有名内存映射区
    int fd = open("mmapTest.txt", O_RDWR);
    int len = lseek(fd, 0, SEEK_END);

    void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(ptr == "MAP_FAILED"){
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    
    for(i = 0; i < 2; i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(pid == 0)
            break;
    }
    //子进程1
    if(i == 0){
        strcpy((char *)ptr, "SunGou,I'm your father!!");
    }

    //子进程2
    if(i == 1){
        printf("%s\n", (char *)ptr);
    }

    //父进程
    if(i == 2){
        for(int j = 0; j < 2; j++){
            wait(NULL);
        }
    }
    close(fd);
    return 0;
}
