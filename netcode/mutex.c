/*************************************************************************
	> File Name: mutex.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月15日 星期五 19时04分51秒
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

int number;
pthread_mutex_t mutex;

//两个线程对共享资源++操作
void *pthread1(void *arg){
    int i = 0;
    pthread_mutex_lock(&mutex);
    for(i; i < 500000; i++){
        int cnt = number;
        cnt++;
        number = cnt;
        printf("A:thread id: %lu and number: %d\n", *(pthread_t *)arg, number);
    }
    pthread_mutex_unlock(&mutex);
    usleep(10);
}

void *pthread2(void *arg){
    int i = 0;
    pthread_mutex_lock(&mutex);
    for(i; i < 500000; i++){
        int cnt = number;
        cnt++;
        number = cnt;
        printf("B:thread id: %lu and number: %d\n", *(pthread_t *)arg, number);
    }
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t pthreadId1, pthreadId2;

    pthread_mutex_init(&mutex, NULL);
    //创建线程1,2
    pthread_create(&pthreadId1, NULL, pthread1, &pthreadId1);
    pthread_create(&pthreadId2, NULL, pthread2, &pthreadId2);

    //销毁线程1,2
    pthread_join(pthreadId1, NULL);
    pthread_join(pthreadId2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
