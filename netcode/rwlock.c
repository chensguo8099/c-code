/*************************************************************************
	> File Name: rwlock.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月15日 星期五 23时21分34秒
 ************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int res;
pthread_rwlock_t lock;
//3个线程不定时写同一全局资源，5个线程不定时读同一全局资源，若不加读写锁，打印虽为40条数据，但res至小于40（由于数据混乱）

void *readfunc(void *arg){
    int i;
    for(i = 0; i < 500000; i++){
        pthread_rwlock_rdlock(&lock);
        printf("RD:thread id:%lu res:%d\n", *(pthread_t *)arg, res);
        pthread_rwlock_unlock(&lock);
    usleep(10);
    }
}

void *writefunc(void *arg){
    int i;
    /*  usleep放在for外面的前提下：
     *  锁放for里面real:24.602s user:5.422s sys:19.346s
     *  锁放for外面real:19.981s user:2.911s sys:10.649s
    */
    for(i = 0; i < 500000; i++){
        //增加内存于CPU寄存器的切换 增加数据混乱 便于数据测试
        pthread_rwlock_wrlock(&lock);
        int number = res;
        number++;
        res = number;
        printf("WR:thread id:%lu res:%d\n", *(pthread_t *)arg, res);
        pthread_rwlock_unlock(&lock);
        usleep(10);
    }
    //usleep(10);
}

int main(){
    int i, j;
    //负责不定期写
    pthread_t pthread_w[3];
    //负责不定期读
    pthread_t pthread_r[5];

    pthread_rwlock_init(&lock, NULL);
    //也可以不向线程传threadid，直接在线程中调用pthread_self()函数打印当前线程id(unsigned long int)
    for(i = 0; i < 3; i++){
        pthread_create(&pthread_w[i], NULL, readfunc, &pthread_w[i]);
    }
    for(j = 0; j < 5; j++){
        pthread_create(&pthread_r[j], NULL, writefunc, &pthread_r[j]);
    }

    int k1, k2;
    for(k1 = 0; k1 < 3; k1++)
        pthread_join(pthread_w[k1], NULL);
    for(k2 = 0; k2 < 5; k2++)
        pthread_join(pthread_r[k2], NULL);
    pthread_rwlock_destroy(&lock);
    return 0;
}
