/*
    > File Name: test13.cpp
    > Author: JerryChen
    > Created Time: 2019年02月23日 星期六 22时00分15秒
*/

#include <iostream>
using namespace std;
class A{
public:
    A(int a){
        this->a = a;
        print();
    }
    virtual void print(){
        cout << "A(int)..." << endl;
    }
private:
    int a;
};
class B:public A{
public:
    B(int a, int b):A(a){
        print();
        this->b = b;
    }
    virtual void print(){
        cout << "B(int, int)..." << endl;
    }
private:
    int b;
};
int main(){
    A *ap = new B(10, 20);
    return 0;
}
