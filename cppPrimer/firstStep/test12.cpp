/*
    > File Name: test12.cpp
    > Author: JerryChen
    > Created Time: 2019年02月23日 星期六 15时20分51秒
*/

#include <iostream>
#include <cstring>
using namespace std;

class Father{
public:
    Father(){
        cout << "Father()" << endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "Father string...");
    }
    //实现多态
    virtual void print(){
        cout << "A:" << this->p << endl;
    }
    virtual ~Father(){
        cout << "~Father()" << endl;
        if(this->p != NULL){
            delete []this->p;
            this->p = NULL;
        }
    }
private:
    char *p;
};

class Son:public Father{
public:
    Son(){
        cout << "Son()" << endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "Son String...");
    }
    virtual void print(){
        cout << "B:" << this->p << endl;
    }
    ~Son(){
        cout << "~Son()" << endl;
        if(this->p != NULL){
            delete []this->p;
            this->p = NULL;
        }
    }
private:
    char *p;
};

void func(Father *fatherp){
    fatherp->print();
    delete fatherp;
    //此时必须将Father类的析构函数改为虚析构，否则：
    //即使fatherp接收Son类仍调用父类析构，却不执行子类析构
    //若父类析构改为虚构，当fatherp接受子类时会调用子类析构。
}

void test(){
    //Son obj;
    Son *bp = new Son;//传指针不是delete对象的话是不会打印该类析构的
    func(bp);
}

int main(){
    test();
    return 0;
}
