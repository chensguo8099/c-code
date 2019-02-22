/*
    > File Name: test7.cpp
    > Author: JerryChen
    > Created Time: 2019年02月22日 星期五 17时52分01秒
*/

#include <iostream>
using namespace std;

class A{
private:
    int a;
protected:
    int b;
public:
    int c;
    A(){
        a = 0; b = 0; c = 0;
    }
    void set(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

class B:public A{
public:
    void print(){
        //cout << "a = " << a; //private无法访问
        cout << "b = " << b;//protect仅在B类内部可访问
        cout << "c = " << c;//可在B类内外均访问
    }
};

class C:protected A{
public:
    void print(){
        //cout << a; //private无法访问
        cout << b;//仅C类内可访问
        cout << c;//仅C类内可访问
    }
};

class D:private A{
public:
    void print(){
        //cout << a;//父类私有无法访问
        cout << b;//b为D私有
        cout << c;//c为D私有
    }
};

class E:protected C{

};
int main(){
    A aa;
    B bb;
    C cc;
    D dd;
    aa.c = 1;
    bb.c = 1;//public继承 c仍public
    //cc.c = 1;//protected继承 且c为父类public 继承后为protected 仅在C内访问
    //cc.c = 1; //c为protected属性
    //dd.c = 1; //c为private属性
    bb.print();
    cc.print();
    dd.print();
    return 0;
}
