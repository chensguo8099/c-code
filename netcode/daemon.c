/*************************************************************************
	> File Name: daemon-ex1.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月10日 星期日 15时52分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

//守护进程每隔2s获取一次系统时间，将这个时间写入到磁盘文件
void catchSysTime(int no){
    //获取当前时间并将时间写入文件
    time_t currentTime;
    //得到当前系统时间
    time(&currentTime);
    //对time_t类型时间进行格式化
    char *str = ctime(&currentTime);
    
    //创建出的文件在守护进程改变后的目录下
    int fd =open("signalfile.txt", O_CREAT | O_WRONLY | O_APPEND, 0664);
    write(fd, str, strlen(str) + 1);
    close(fd);
    return;
}

int main(){
    pid_t pid = fork();
    //父进程直接结束，让子进程变成会话session
    if(pid > 0){
        exit(1);
        #if 0
        abort();
        kill(getpid(), SIGKILL);
        #endif
    }
    if(pid == 0){
        //变成会长脱离终端 成为daemon
        setsid();
        //改变进程工作目录
        chdir("/home/chenguo/");
        //重置文件掩码
        umask(0);
        //关闭文件描述符
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        struct itimerval new_val;
        //执行核心操作,保证该进程处于运行状态

        //注册信号捕捉
        struct sigaction act;
        act.sa_flags = 0;
        act.sa_handler = catchSysTime;
        sigemptyset(&act.sa_mask);
        //定时器定时发送SIGALRM
        sigaction(SIGALRM, &act, NULL);
        new_val.it_value.tv_sec = 2;
        new_val.it_value.tv_usec = 0;
        //周期触发
        new_val.it_interval.tv_sec = 2;
        new_val.it_interval.tv_usec = 0;
        setitimer(ITIMER_REAL, &new_val, NULL);
    }
    while(1);

    return 0;
}
