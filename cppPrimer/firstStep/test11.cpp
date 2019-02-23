/*
    > File Name: test11.cpp
    > Author: JerryChen
    > Created Time: 2019年02月23日 星期六 11时26分37秒
*/

#include <iostream>
using namespace std;

class A{
public:
    A(){}
    A(int ax):a(ax){}
    void print(){
        cout<<"a:" << a <<endl;
    }
    void print2(){
        cout << "a" << a << endl;
    }
    int a;
private:
};

class B : virtual public A{
public:
    B(int ax,int bx):A(ax),b(bx){}
    //在构造B时会先构造A，所以一开始B的VPTR指针指向A类的虚表，当构造A完毕后VPTR再由A类指向B类！！
    void print(){
        cout<<"b:" << b <<endl;
    }
private:
    int b;
};

class C : virtual public A{
public:
    C(int ax,int cx):A(ax),c(cx){}
    void print(){
        cout<<"c:" << c <<endl;
    }
private:
    int c;
};

class D : public B, public C 
{
public:
    D(int ax,int bx,int cx, int dx):A(ax), B(ax,bx), C(ax,cx),d(dx){
        cout << this->B::a << endl;
    }
    void print(){
        cout<<"d:" << d <<endl;
    }
private:
    int d;
};

int main(int argc, char const *argv[])
{
    D d(1,2,3,4);
    A a(10);
    B b(15, 15);
    C c(20, 20);
    //非virtual继承
    //A *pa = (B*) &d;  //上行转换出现二义性,d中含有两个基类对象A，隐式转换不知道让pa指向哪个子对象
    //pa->print(); //print具有二义性，系统不知道是调用B类还是C类的print()
    /*virtaul继承 要注意修改D的构造函数，必须加上A的参数构造，否则默认调用A的无参构造*/
    d.print();//打印d:4
    A *ap = new D(6, 7, 8, 9);
    ap->print();//A类中的print不加virtual打印a:6
    //A类中print加virtual后为d:9
    A *ap2 = new D(5, 0, 0, 100);
    ap2->print2();//打印a0 
    ap2->print();//打印d:100
    A *ap3 = new B(50, 500);
    ap3->print();
    return 0;
}
