/*************************************************************************
	> File Name: ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Nov 2017 07:16:24 AM PST
 ************************************************************************/
//C++中不建议使用指针,仅必要时候再使用，C++提供了替代指针的结构，比如向量和迭代器取代数组，使用String类型取代C中字符串，指针在C中是重点

#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s("hello world!");
    string *sp = &s;
    //string *ps1, ps2; //ps1是指针 ps2是String
    string *ps1, *ps2;

    cout << s << endl;
    cout << *sp << endl;
    cout << sp << endl;


    vector<int> *pvec;
    int *ip1, *ip2;
    double dp, *dp2;

    int ival = 1024;
    int *pi=0;
    int *pi2 = &ival;

    int ival2;
    int zero = 0;
    const int c_ival = 0;
    int *pi4 = c_ival;
    cout << *pi4 << endl;

    double obj = 3.14;
    void *pv = &obj;

    int k;
    pv = &k;
    //pv 俗称万能指针，不能用这个指针操作对象，仅用来传参等

    int a = 1;
    int *pa = &a;

    a = a + 2;
    *pa = *pa + 2;

    cout << a << endl;//5
    cout << *pa << endl;//5

    return 0;
}
