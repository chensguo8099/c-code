/*************************************************************************
	> File Name: sigfunc.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月10日 星期日 17时15分02秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int i;
    //自定义信号集
    sigset_t myset;
    //清空标志位
    sigemptyset(&myset);

    sigaddset(&myset, SIGINT);
    sigaddset(&myset, SIGQUIT);
    sigaddset(&myset, SIGKILL);//9号信号SIGKILL和19号信号SIGSTOP不能被捕捉、阻塞和忽略

    //自定义集合数据设置给内核的阻塞信号集
    sigprocmask(SIG_BLOCK, &myset, NULL);

    //每隔1s读一次内核未决信号集
    while(1){
        sigset_t pendset;
        //将内核未决信号集读出至自定义信号集
        sigpending(&pendset);
        //读取前31个信号的标志位
        for(i = 1; i < 32; i++){
            if(sigismember(&pendset, i)){
                printf("1");
            }
            else
                printf("0");
        }
        printf("\n");
        sleep(1);
    }

    return 0;
}
