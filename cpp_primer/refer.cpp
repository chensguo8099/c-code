/*************************************************************************
	> File Name: refer.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 30 Oct 2017 06:38:25 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
#if 0
    int zhangfei = 1024;
    int &zhangyide = zhangfei;

    cout << zhangfei << endl;
    cout << zhangyide << endl;

    int ival = 1024;
    int &refVal = ival;//此处引用不能引用常量，只能引用变量名 int &refVal = 1024;为错误写法
    int refVal2 = ival;
    int refVal3 = ival;

    int i = 1024, i2 = 2048;
    int &r = i, &r2 = i2;//这里r2前也要写上&符号才表示一个引用
    int i3 = 1024, &ri = i3;
#endif

    const int ival = 1024;//常量
    const int &refVal = ival;//const引用可引用const常量,const引用也叫指向const对象的引用
    //int &ref2 = ival; 错误 非const引用不能引用一个const对象

    int ival2 = 2048;
    const int &refVal2 = 1024;
    const int &refVal3 = ival2;//const引用可以引用一个非const变量，也可以引用一个字面常量

    const int &refVal4 = ival2 + 45;
    //int &refVal5 = ival2 + 45;普通引用引用一个变量与常量45，内部包含常量，所以无法引用

    double ival3 = 3.14;
    const int &refVal6 = ival3;
    cout << refVal6 << endl;//3

    return 0;
}
    #if 0
    1. 普通引用只能引用同类型变量，不能引用字面值(常量)或const常量。
    2. const引用可以引用不同类型普通(非const)变量或const常量或字面值(常量)。
    引用主要是用来在使用函数的时候传递函数的参数，可以把函数的参数定义为引用，调用函数的时候传引用，学习函数时会再次讲解
    const引用可以初始化为不同类型的对象，或者初始化为右值；非const引用就只能够指向以引用同类型的对象
    #endif
