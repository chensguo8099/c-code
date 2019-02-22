/*
    > File Name: autoptr.cpp
    > Author: JerryChen
    > Created Time: 2019年02月22日 星期五 10时32分41秒
*/

#include <iostream>
#include <memory>
using namespace std;
class A{
public:
    A(int a){
        cout << "A()..."  << endl;
        this->a = a;
    }
    void func(){
        cout << "func():" << this->a << endl;
    }
    ~A(){
        cout << "~A()..." << endl;
    }
private:
    int a;
};

void test1(){
    #if 0
    A* p = new A(10);
    p->func();
    (*p).func();
    #endif
    shared_ptr<A> ptr(new A(10));
    ptr->func();
    (*ptr).func();
}

int main(){
    test1();
    return 0;
}
