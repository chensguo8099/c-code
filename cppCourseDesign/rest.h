#ifndef REST_H_INCLUDED
#define REST_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring> //memset function
using namespace std;

#include <stdlib.h>
#include <stdio.h>

typedef struct node_staff{
    char name[35];
    int num;
    struct node_staff* next;
}SeqList;

typedef struct node_client{
    char name[35];
    int table_num;
    int queue_num;
    struct node_client* next;
}ClientMessage;

class rest_info{
private:
    char dishes[50];
public:
    void write_dishes_info();
    void read_dishes_info();
    void dishes_info();
};//������ �����Ͳ�Ʒ

class staff_info{
public:
    void write_staff_info(SeqList **phead);//¼��Ա����Ϣ ���� Ա����
    void read_staff_info(SeqList **phead, SeqList **phead_still);//����Ա����Ϣ
    void info(SeqList **phead, SeqList **phead_still);
    void staff_delete(SeqList **phead, SeqList **phead_still);
};//Ա����

class client_info:private rest_info{
public:
    void write_client_info(ClientMessage **phead);
    void read_client_info(ClientMessage **phead, ClientMessage **phead_still);
    void info(ClientMessage **phead, ClientMessage **phead_still);
    void client_delete(ClientMessage **phead, ClientMessage **phead_still);
};

void init_seqlist(SeqList **pphead);
void init_clientmessage(ClientMessage **pphead);
void menu();
void restaurant_info();
void clean_data(SeqList **phead1, ClientMessage **phead2);


#endif // REST_H_INCLUDED
