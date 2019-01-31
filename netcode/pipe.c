/*************************************************************************
	> File Name: pipe.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月17日 星期四 18时18分39秒
 ************************************************************************/

//功能：两个子进程实现 ps aux | grep "bash" 命令，父进程回收子进程
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pfd[2], i;
    if(pipe(pfd) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid_t pid;
    //创建两个子进程
    for(i = 0; i < 2; i++){
        pid = fork();
        /*if(pid < 0){
            perror("fork");
            exit(EXIT_FAILURE);
        }*/
        if(pid == 0)
            break;
    }

    //子进程1写数据
    if(i == 0){
        close(pfd[0]);
        if(dup2(pfd[1], STDOUT_FILENO) == -1){
            perror("child process_1 dup2");
            exit(EXIT_FAILURE);
        }
        printf("child1 : parent pid:%d child1 pid:%d\n", getppid(), getpid());
        execlp("ps", "ps", "aux", NULL);
        perror("execlp");
        exit(1);
    }

    //子进程2读数据
    if(i == 1){
        close(pfd[1]);
        if(dup2(pfd[0], STDIN_FILENO) == -1){
            perror("child process_2 dup2");
            exit(EXIT_FAILURE);
        }
        printf("child2 : parent pid:%d child2 pid:%d\n", getppid(), getpid());
        execlp("grep", "grep", "--color=auto", "bash", NULL);
        perror("execlp");
        exit(1);
    }

    //父进程回收子进程
    if(i == 2){
        int j, status;
        pid_t wret;
        for(j = 0; j < 2; j++){
            if(waitpid(-1, &status, WNOHANG) == -1){
                perror("waitpid"); 
                exit(EXIT_FAILURE);
            }
            if(WIFEXITED(status))
                printf("process exit value:%d\n", WEXITSTATUS(status));
            if(WIFSIGNALED(status))
                printf("process exit value:%d\n", WTERMSIG(status));
        }
        printf("parent : parent pid:%d his pid:%d\n", getppid(), getpid());
    }
    close(pfd[0]);
    close(pfd[1]);
    return 0;
}

