/******************************************************************************************
C++ PROJECT
使用文件IO及单向链表对菜品、服务员、客户的信息进行录入、输出、删除。使用了二级指针来控制
一级指针进而对链表进行增添、删除、清空操作
*******************************************************************************************/
#include "rest.h"

int main()
{
    int choose = 0, flag = 1;
//初始化server链表
    SeqList *phead1 = NULL;
    SeqList *phead_staff = NULL;
    init_seqlist(&phead_staff);
    phead1 = phead_staff;
//初始化client链表
    ClientMessage *phead2 = NULL;
    ClientMessage *phead_client = NULL;
    init_clientmessage(&phead_client);
    phead2 = phead_client;
//定义3个对象
    rest_info obj;
    staff_info staff;
    client_info client;

    system("color f3");
    while(flag == 1)
    {
        menu();
        cout << "select a function num :" << endl;
        cin >> choose;
        switch (choose){
            case 1: restaurant_info(); break;
            case 2: obj.dishes_info(); break;
            case 3: staff.info(&phead_staff, &phead1); break;
            case 4: client.info(&phead_client, &phead2); break;
            case 5: staff.staff_delete(&phead_staff, &phead1); break;
            case 6: client.client_delete(&phead_client, &phead2); break;
            case 7: clean_data(&phead1, &phead2); exit(0); break;
            default:cout << "sorry, error input" << endl; break;
        }
        system("cls");
    }
    return 0;
}

void init_seqlist(SeqList **pphead){
    (*pphead) = (SeqList *)malloc(sizeof(SeqList));
    memset((*pphead)->name, 0, sizeof((*pphead)->name));
    (*pphead)->num = 0;
    (*pphead)->next = NULL;
}

void init_clientmessage(ClientMessage **pphead){
    (*pphead) = (ClientMessage *)malloc(sizeof(ClientMessage));
    memset((*pphead)->name, 0, sizeof((*pphead)->name));
    (*pphead)->table_num = 0;
    (*pphead)->queue_num = 0;
    (*pphead)->next = NULL;
}

void menu(){
    cout << "1:................餐馆信息简介................" << endl;
    cout << "2:............查询/录入菜品信息..............." << endl;
    cout << "3:............查询/录入服务员信息............." << endl;
    cout << "4:............查询/录入顾客的信息............." << endl;
    cout << "5:.............删除服务员行信息..............." << endl;
    cout << "6:.............删除某顾客的信息..............." << endl;
    cout << "7:..............清除数据并退出................" << endl;
}

void restaurant_info(){
    ifstream in("restaurant_info.txt",ios::in);
    char buf;
    while((buf = in.get()) != EOF)
        cout << buf;
    cout << "\n";
    in.close();
    system("pause");
    return;
}

void rest_info::write_dishes_info(){
    cout << "please input what dishes you wanna add:" << endl;
    cin >> dishes;
    ofstream out("dishes_info.txt", ios::app);
    out << dishes << endl;
    out.close();
}//菜品信息录入

void rest_info::read_dishes_info(){
    ifstream in("dishes_info.txt", ios::in);
    char buf;
    while((buf = in.get()) != EOF)
        cout << buf;
    cout << endl;
    in.close();
}//菜品信息查询

void rest_info::dishes_info(){
    unsigned int rest_info_choose = 0;
    cout << "1.search" << endl;
    cout << "2.input" << endl;
    cout << "please select 1 or 2 :";
    cin >> rest_info_choose;
    switch(rest_info_choose){
        case 1: read_dishes_info(); system("pause"); break;
        case 2: write_dishes_info(); system("pause"); break;
        default:cout << "sorry, error input" << endl; system("pause"); break;
    }
}

void staff_info::write_staff_info(SeqList **phead){
    SeqList *p = (SeqList *)malloc(sizeof(SeqList));
    cout << "please input name and num" << endl;
    cin >> p->name >> p->num;
    p->next = NULL;
    (*phead)->next = p;
    (*phead) = (*phead)->next;
}

void staff_info::read_staff_info(SeqList **phead, SeqList **phead_still){
    if((*phead_still)->next == NULL){
        cout << "eorror, no data" << endl;
        return;
    }
    int line = 1;
    SeqList *pmove = NULL;
    pmove = (*phead_still)->next;
    while(pmove->next != NULL){
        cout << line << " : " << pmove->name << " " << pmove->num << endl;
        pmove = pmove->next;
        line++;
    }
    cout << line << " : " << pmove->name << " " << pmove->num << endl;
    return;
}

void staff_info::info(SeqList **phead, SeqList **phead_still){
    unsigned int staff_info_choose = 0;
    cout << "1.search" << endl;
    cout << "2.input" << endl;
    cout << "please select 1 or 2 :";
    cin >> staff_info_choose;
    switch(staff_info_choose){
        case 1: read_staff_info(phead,phead_still); system("pause"); break;
        case 2: write_staff_info(phead); system("pause"); break;
        default:cout << "error input" << endl; system("pause"); break;
    }
}

void staff_info::staff_delete(SeqList **phead, SeqList **phead_still){
    int line = 0, cnt = 1;
    read_staff_info(phead, phead_still);
    /*if((*phead)->next == NULL){
        system("pause");
        return;
    }*/

    cout << "which line would you want to delete?" << endl;
    cin >> line;
    if(line < 1)
        cout << "sorry, please input right line num (>=1) " << endl;
    SeqList *tmp = NULL;
    tmp = (*phead_still)->next;
    while(cnt != line){
        tmp = tmp->next;
        cnt++;
    }
    SeqList *tmp2 = NULL;
    tmp2 = *phead_still;
    while(tmp2->next != tmp)
        tmp2 = tmp2->next;//确定tmp2指针始终在tmp指针的前一个节点

    if(tmp->next == NULL){
        tmp2->next = NULL;
        free(tmp);//如果是尾指针 直接free
        *phead = tmp2;
    }
    else{
        tmp2->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    read_staff_info(phead, phead_still);
    system("pause");
}

void client_info::write_client_info(ClientMessage **phead){
    ClientMessage *p = (ClientMessage *)malloc(sizeof(ClientMessage));
    cout << "please input client informations you wanna add: name, table number and queue number:" << endl;
    cin >> p->name >> p->table_num >> p->queue_num;
    p->next = NULL;
    (*phead)->next = p;
    (*phead) = (*phead)->next;
    return;
}

void client_info::read_client_info(ClientMessage **phead, ClientMessage **phead_still){
    if((*phead_still)->next == NULL){
        cout << "error, no data\n" << endl;
        return;
    }
    unsigned int line = 1;
    ClientMessage *pmove = NULL;
    pmove = (*phead_still)->next;
    while(pmove->next != NULL){
        cout << line << " : " << pmove->name << " " << pmove->table_num << " " << pmove->queue_num <<endl;
        pmove = pmove->next;
        line++;
    }
    cout << line << " : " << pmove->name << " " << pmove->table_num << " " << pmove->queue_num << endl;
    return;
}

void client_info::info(ClientMessage **phead, ClientMessage **phead_still){
    unsigned int client_info_choose = 0;
    cout << "1.查询" << endl;
    cout << "2.录入" << endl;
    cout << "请选择 1 or 2 :";
    cin >> client_info_choose;
    switch(client_info_choose){
        case 1: read_client_info(phead, phead_still); system("pause"); break;
        case 2: write_client_info(phead); system("pause"); break;
        default:cout << "error input !" << endl; system("pause"); break;
    }
}

void client_info::client_delete(ClientMessage **phead, ClientMessage **phead_still){
    int line = 0, cnt = 1;
    read_client_info(phead, phead_still);
    /*if((*phead)->next == NULL){
        system("pause");
        return;
    }*/
    cout << "which line would you want to delete?" << endl;
    cin >> line;
    if(line < 1)
        cout << "sorry, please input right line num (>=1) " << endl;
    ClientMessage *tmp = NULL;
    tmp = (*phead_still)->next;
    while(cnt != line){
        tmp = tmp->next;
        cnt++;
    }
    ClientMessage *tmp2 = NULL;
    tmp2 = *phead_still;
    while(tmp2->next != tmp)
        tmp2 = tmp2->next;//确定tmp2指针始终在tmp指针的前一个节点

    if(tmp->next == NULL){
        tmp2->next = NULL;
        free(tmp);//如果是尾指针 直接free
        *phead = tmp2;
    }
    else{
        tmp2->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    read_client_info(phead, phead_still);
    system("pause");
}
//清除数据并退出
void clean_data(SeqList **phead1, ClientMessage **phead2){
    SeqList *tmp1_pre = NULL;
    SeqList *tmp1_next = NULL;
    ClientMessage *tmp2_pre = NULL;
    ClientMessage *tmp2_next = NULL;
    if((*phead1)->next == NULL)
        free(*phead1);
    else{
        tmp1_pre = *phead1;
        tmp1_next = (*phead1)->next;
        while(tmp1_next->next != NULL){
            free(tmp1_pre);
            tmp1_pre = tmp1_next;
            tmp1_next = tmp1_next->next;
        }
        free(tmp1_pre);
        free(tmp1_next);
    }
    if((*phead2)->next == NULL)
        free(*phead2);
    else{
        tmp2_pre = *phead2;
        tmp2_next = (*phead2)->next;
        while(tmp2_next->next != NULL){
            free(tmp2_pre);
            tmp2_pre = tmp2_next;
            tmp2_next = tmp2_next->next;
        }
        free(tmp2_pre);
        free(tmp2_next);
    }
    cout << "clean finished , press any type to continue..." << endl;
    system("pause");
}
