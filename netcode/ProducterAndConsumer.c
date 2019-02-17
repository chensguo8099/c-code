/*************************************************************************
	> File Name: ProducterAndConsumer.c
	> Author: 
	> Mail: 
	> Created Time: 2019年02月16日 星期六 17时20分39秒
 ************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct LinkList{
    int data;
    struct LinkList *next;
}List;
int i = 1;
pthread_mutex_t mutex;
pthread_cond_t condition;
//定义头指针供Producter和Consumer使用
List *head = NULL;

//链表尾部创建node
void createList(){
    //链头空则创建node 并让head指向node
    if(head == NULL){
        List *tmp = (List *)malloc(sizeof(struct LinkList));
        tmp->data = i;
        tmp->next = NULL;
        i++;
        head = tmp;
    }else{//链头非空则将op移至链尾插入node
        List *op = head;
        List *tmp = (List *)malloc(sizeof(struct LinkList));
        tmp->data = i;
        tmp->next = NULL;
        i++;
        while(op->next != NULL)
            op = op->next;
        op->next = tmp;
    }
}
//删除链表头部node
void deleteList(){
    List *tmp = head;
    //链头空则直接返回头指针或NULL
    if(tmp != NULL){
        //链头非空 若链至少两个node 则删除头 否则删除tmp指向 返回NULL
        if(tmp->next != NULL){
            head = tmp->next;
            free(tmp);
            tmp = NULL;
        }
        else{
            free(tmp);
            tmp = NULL;
            head = NULL;
        }
    }
    else
        printf("LinkList is NULL\n");
}


//生产者消费者模型
//生产者线程回调
void *Producter(void *arg){
    while(1){
        //加锁
        pthread_mutex_lock(&mutex);
        printf("生产者加锁\n");
        printf("生产 thread id: %lu\n", pthread_self());
        createList();
        printf("生产者已生产\n");
        List *tmp = head;
        //tmp便利打印链表内容
        printf("链表为:");
        while(tmp->next != NULL){
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("%d\n", tmp->data);
        //解锁
        pthread_mutex_unlock(&mutex);
        printf("生产者解锁并发送条件信号解除阻塞\n");
        //解除条件变量阻塞
        pthread_cond_signal(&condition);
        printf("条件信号发送完毕\n");
        sleep(rand()%4);
    }
}

//消费者线程回调
void *Consumer(void *arg){
    while(1){
        //加锁
        pthread_mutex_lock(&mutex);
        printf("消费者加锁\n");
        if(head == NULL){
            //条件变量阻塞至链表用内容
            printf("条件变量阻塞\n");
            pthread_cond_wait(&condition, &mutex);
            printf("条件变量解除阻塞\n");
        }
        //删除链表节点（类似消费）
        printf("消费 thread id: %lu\n", pthread_self());
        deleteList();
        printf("消费者消费完毕\n");
        List *tmp = head;
        //考虑到若链表不为空 打印data 否则打印空行
        printf("链表为:");
        while(tmp != NULL){
            if(tmp->next != NULL){
                printf("%d ", tmp->data);
                tmp = tmp->next;
            }
            else{
                printf("%d\n", tmp->data);
                tmp = NULL;
                head = NULL;
            }
        }
        printf("\n");
        //解锁
        pthread_mutex_unlock(&mutex);
        printf("消费者已解锁\n");
        sleep(rand()%4);
    }
}

int main(){
    pthread_t pthreadProducter;
    pthread_t pthreadConsumer;

    //初始化
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);
    //生产者线程
    pthread_create(&pthreadProducter, NULL, Producter, NULL);
    //消费者线程
    pthread_create(&pthreadConsumer, NULL, Consumer, NULL);

    //生产者消费者回收
    pthread_join(pthreadProducter, NULL);
    pthread_join(pthreadConsumer, NULL);

    //线程回收
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);

    return 0;
}
