#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//个人信息结构体
typedef struct people {
    char myName[64];        //用户姓名
    char myAddress[64];     //用户籍贯
    char myTelOne[64];      //用户电话1
    char myTelTwo[64];      //用户电话2
    char myMail[64];        //用户邮箱
}People;

//链表结构体
typedef struct linklist{
    struct people *info;
    struct linklist *next;
}Link;

//链头指针 链尾指针 定义
Link *peopleInfoHead = NULL;
Link *peopleInfoTail = NULL;
int flag = 1;

void inputInformation(){
    printf("请输入：姓名 籍贯 电话1 电话2 邮箱\n");
    printf(" ---------------------------------\n");
    //创建一个节点内存
    Link *ptr = (Link *)malloc(sizeof(Link));

    //创建一个结构体对象内存
    People *obj = (People *)malloc(sizeof(People));
    scanf("%s%s%s%s%s", obj->myName, obj->myAddress, obj->myTelOne, obj->myTelTwo, obj->myMail);
    ptr->info = obj;
    ptr->next = NULL;

    //信息插入链中
    Link *tmp = peopleInfoHead;
    if(peopleInfoHead != NULL){
        while(tmp != peopleInfoTail){
            tmp = tmp->next;
        }
        tmp->next = ptr;
        peopleInfoTail = peopleInfoTail->next;
        ptr = NULL;
    }else{
        peopleInfoHead = ptr;
        peopleInfoTail = ptr;
        ptr = NULL;
    }
}

//打印所有用户信息
void lookInformation(){
    if(peopleInfoHead == NULL){
        printf("[WARNING] 您还没有录入任何数据，无查询结果\n\n");
    }else{//打印用户所有信息
        Link *tmp = peopleInfoHead;
        int cnt = 1;
        while(tmp != NULL){
            if(tmp != peopleInfoTail){
                printf("[用户%d] 姓名：%s 籍贯：%s 电话一：%s 电话二：%s 邮箱：%s\n",
                    cnt, tmp->info->myName, tmp->info->myAddress,
                    tmp->info->myTelOne,tmp->info->myTelTwo,tmp->info->myMail);
                tmp = tmp->next;
                cnt++;
            }else{
                printf("[用户%d] 姓名：%s 籍贯：%s 电话一：%s 电话二：%s 邮箱：%s\n",
                    cnt, tmp->info->myName, tmp->info->myAddress,
                    tmp->info->myTelOne,tmp->info->myTelTwo,tmp->info->myMail);
                tmp = tmp->next;
            }
        }
    }
}

//提供按姓名查询用户信息功能
void searchInformation(){
    if(peopleInfoHead == NULL){
        printf("[WARNING] 您还没有录入任何数据，无查询结果\n\n");
    }else{
        printf("请输入姓名来查询某人对应信息\n");
        printf(" ---------------------------------\n");
        char tmpName[64];
        int cnt = 1;
        scanf("%s", tmpName);
        Link *tmp = peopleInfoHead;
        while(tmp != NULL){
            if(!strcmp(tmpName, tmp->info->myName)){
                printf("[用户%d] 姓名：%s 籍贯：%s 电话一：%s 电话二：%s 邮箱：%s\n",
                    cnt, tmp->info->myName, tmp->info->myAddress,
                    tmp->info->myTelOne,tmp->info->myTelTwo,tmp->info->myMail);
                cnt++;
            }
            tmp = tmp->next;

        }
        if(cnt == 1)
            printf("未查寻到您输入的[姓名]对应的用户信息\n\n");
    }
}

//修改用户信息
void modifyInformation(){
    int cnt, i = 1;
    if(peopleInfoHead == NULL){
        printf("[WARNING] 无数据可修改，请先录入用户数据\n\n");
    }else{
        printf("用户数据如下，请选择你要修改数据的用户编号数字：\n");
        lookInformation();
        printf(" ---------------------------------\n");
        scanf("%d", &cnt);
    }
    Link *tmp = peopleInfoHead;
    while(tmp != NULL && i != cnt){
        tmp = tmp->next;
        i++;
    }
    if(tmp == NULL){
        printf("[ERROR_INPUT] 您输入的用户编号数字超出范围\n\n");
    }else{
        printf("该用户信息为：\n姓名：%s 籍贯：%s 电话一：%s 电话二：%s 邮箱：%s\n",
            tmp->info->myName, tmp->info->myAddress,
            tmp->info->myTelOne, tmp->info->myTelTwo, tmp->info->myMail);

        printf("请输入 姓名 籍贯 电话一 电话二 邮箱 修改以上信息：\n");
        scanf("%s%s%s%s%s",
            tmp->info->myName, tmp->info->myAddress, tmp->info->myTelOne,
            tmp->info->myTelTwo, tmp->info->myMail);
        printf("修改完毕!!\n\n");
    }
}

//删除用户信息
void deleteInformation(){
    int cnt, i = 1;
    if(peopleInfoHead == NULL){
        printf("[WARNING] 无数据可删除，请先录入用户数据\n\n");
    }else{
        printf("用户数据如下，请选择你要删除数据的用户编号数字\n");
        lookInformation();
        printf(" ---------------------------------\n");
        scanf("%d", &cnt);
    }
    Link *tmp = peopleInfoHead;
    while(tmp != NULL && i != cnt){
        tmp = tmp->next;
        i++;
    }
    char decision[10];
    if(tmp == NULL){
        printf("[ERROR_INPUT] 您输入的用户编号数字超出范围\n\n");
    }else{
        printf("该用户信息为：\n姓名：%s 籍贯：%s 电话一：%s 电话二：%s 邮箱：%s，您却定要删除吗？\n",
            tmp->info->myName, tmp->info->myAddress,
            tmp->info->myTelOne, tmp->info->myTelTwo, tmp->info->myMail);
        ret : printf("请输入yes/no：\n");
        scanf("%s", decision);
        if(!strcmp("yes", decision)){
            if(cnt > 1){
                i = 1;
                Link *prePtr = peopleInfoHead;
                while(i < cnt - 1){
                    prePtr = prePtr->next;
                    i++;
                }
                prePtr->next = tmp->next;
                free(tmp);
                tmp = NULL;
            }else{
                free(tmp);
                peopleInfoHead = NULL;
                peopleInfoTail = NULL;
                tmp = NULL;
            }
        }else if(!strcmp("no", decision)){
            //return
        }else{
            printf("输入有误，请输入yes or no!\n");
            goto ret;
        }
    }
}

void exitFunction(){
    flag = 0;
}

void menu(){
    printf(" ----------------------------------\n");
    printf("|        1:  信息录入功能          |\n");
    printf("|        2:  信息浏览功能          |\n");
    printf("|        3:  姓名查询功能          |\n");
    printf("|        4:  信息修改功能          |\n");
    printf("|        5:  信息删除功能          |\n");
    printf("|        6:  信息系统退出          |\n");
    printf(" ----------------------------------\n");
}

int main(){
    int choose;
    while(flag == 1)
    {
        menu();
        printf("选择你需要的功能的编号数字 [1~6]：\n");
        scanf("%d", &choose);
        switch (choose){
            case 1: inputInformation(); break;
            case 2: lookInformation(); break;
            case 3: searchInformation(); break;
            case 4: modifyInformation(); break;
            case 5: deleteInformation(); break;
            case 6: exitFunction(); break;
            default: printf("[ ERROR_INPUT ] 抱歉，您未输入编号范围为 [1~6] 的数字..\n"); break;
        }
        fflush(stdout);
    }
    return 0;
}
