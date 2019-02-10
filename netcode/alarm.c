/*************************************************************************
	> File Name: alarm.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月10日 星期日 16时45分29秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int ret = alarm(5);//从此开始倒计时5s 系统原本ret为0
    printf("ret = %d\n", ret);//ret = 0

    sleep(1);
    ret = alarm(2);//ret = 4 因为睡了1s后还剩4s,alarm中的参数是从此开始倒计时2s
    printf("ret = %d\n", ret);

    while(1){
        printf("hello world!\n");
        sleep(1);
    }//最终输出2次printf后结束代码
    return 0;
}
