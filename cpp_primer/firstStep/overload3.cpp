/*************************************************************************
	> File Name: overload3.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2017 05:43:04 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

#if 0
重载确定的三个步骤：
    1. 确定候选函数
    2. 选择可行函数
    3. 寻找最佳匹配（如果有的话）
含有多个行参的重载确定
#endif

void d(){cout << "d()" << endl;}
void f(){cout << "f()" << endl;}
void f(int a){cout << "f(int a)" << endl;}
void f(int a, int b){cout << "f(int a, int b)" << endl;}
//第二个参数是有缺省值，及若不传第二个参数，则默认b = 3.14
void f(double a, double b = 3.14){cout << "f(double a, double b)" << endl;}
void g(int a){cout << "g(int a)" << endl;}

int main(){
    f();
    f(8);//f(int a)
    f(5.6);//可行函数2个：f(int) f(double a, double b = 3.14),确定最佳匹配为后者，为了不转型丢失精度及double类型

    //f(42, 2.56);//具有二异性，两个可行函数 ，无最佳匹配
    f(static_cast<double>(42), 2.56);//f(double, double)
    f((double)42, 2.56);//C形式的转型

    f(1.2, 8.9);
    f(12, 89);

    f(42, static_cast<int>(2.56));
    return 0;
}
