/*
    > File Name: test10.cpp
    > Author: JerryChen
    > Created Time: 2019年02月23日 星期六 10时51分49秒
*/

#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout << "A()..." << endl;
    }
    A(int m){
        cout << "A(int)..." << endl;
        this->m = m;
    }
    void print(){
        cout << this->m << endl;
    }
    int m;
};

class B: virtual public A{
public:
    B(int m):A(m){
        cout << "B(int)..." << endl;
    }
    void print(){
        cout << this->m << endl;
    }
};

class C: virtual public A{
public:
    C(int m):A(m){
        cout << "C(int)..." << endl;
    }
    void print(){
        cout << this->m << endl;
    }
};
class D:public B, public C{
public:
    //虚继承此处不显示指定A的初始化参数列表，则会调用A的默认构造函数
    //如果不采用虚继承方式 此处无须显示指定A的初始化参数列表
    D(int m):B(m), C(m){
        cout << "D(int)..." << endl;
    }
    void print(){
        cout << this->m << endl;//这里的this访问的m成员变量直接继承于A类
        //cout << C::m << endl;
    }
};
int main(){
    D a3(10);
    a3.print();
    return 0;
}
