/*************************************************************************
	> File Name: raise.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月10日 星期日 17时09分51秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    pid_t pid = fork();
    if(pid > 0){
        int s;
        pid_t wpid = wait(&s);
        printf("child died pid = %d\n", wpid);
        if(WIFSIGNALED(s)){
            printf("died by signal : %d\n", WTERMSIG(s));
        }
    }

    else if(pid == 0){
        raise(SIGINT);//raise实现自己给自己发信号
        //类似于kill(getpid(), SIGINT);
    }
    return 0;
}
