/*************************************************************************
	> File Name: classcreate.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Nov 2017 04:01:00 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

class Person{
    public:
    #if 0//这种写法没有下面的写法好
    Person(){
        money = 0;
    }
    #endif
    //无参构造函数就是默认构造函数
    Person():money(99999){//构造函数的初始化列表方法比上面的好
    
    }
    public:
    int money;
};

int main(){
    //a,me 都是对象，原来没有这两个对象，创建a,me时，通过调用Person的构造函数创建
    Person a, me;

    cout << a.money << " " << me.money << endl;
    return 0;
}
