/******************************************************************************************
C++ PROJECT
ʹ���ļ�IO����������Բ�Ʒ������Ա���ͻ�����Ϣ����¼�롢�����ɾ����ʹ���˶���ָ��������
һ��ָ������������������ɾ������ղ���
*******************************************************************************************/
#include "rest.h"

int main()
{
    int choose = 0, flag = 1;
//��ʼ��server����
    SeqList *phead1 = NULL;
    SeqList *phead_staff = NULL;
    init_seqlist(&phead_staff);
    phead1 = phead_staff;
//��ʼ��client����
    ClientMessage *phead2 = NULL;
    ClientMessage *phead_client = NULL;
    init_clientmessage(&phead_client);
    phead2 = phead_client;
//����3������
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
    cout << "1:................�͹���Ϣ���................" << endl;
    cout << "2:............��ѯ/¼���Ʒ��Ϣ..............." << endl;
    cout << "3:............��ѯ/¼�����Ա��Ϣ............." << endl;
    cout << "4:............��ѯ/¼��˿͵���Ϣ............." << endl;
    cout << "5:.............ɾ������Ա����Ϣ..............." << endl;
    cout << "6:.............ɾ��ĳ�˿͵���Ϣ..............." << endl;
    cout << "7:..............������ݲ��˳�................" << endl;
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
}//��Ʒ��Ϣ¼��

void rest_info::read_dishes_info(){
    ifstream in("dishes_info.txt", ios::in);
    char buf;
    while((buf = in.get()) != EOF)
        cout << buf;
    cout << endl;
    in.close();
}//��Ʒ��Ϣ��ѯ

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
        tmp2 = tmp2->next;//ȷ��tmp2ָ��ʼ����tmpָ���ǰһ���ڵ�

    if(tmp->next == NULL){
        tmp2->next = NULL;
        free(tmp);//�����βָ�� ֱ��free
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
    cout << "1.��ѯ" << endl;
    cout << "2.¼��" << endl;
    cout << "��ѡ�� 1 or 2 :";
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
        tmp2 = tmp2->next;//ȷ��tmp2ָ��ʼ����tmpָ���ǰһ���ڵ�

    if(tmp->next == NULL){
        tmp2->next = NULL;
        free(tmp);//�����βָ�� ֱ��free
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
//������ݲ��˳�
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
