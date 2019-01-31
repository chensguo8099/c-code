/*************************************************************************
	> File Name: ptr4.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 20 Nov 2017 08:46:51 PM PST
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

void doA(const int *p){
//常指针无法对指向做修改，所以经常被用来作传参数。
}

typedef string *pstring;//pstring是string*类型

int main(){
    double a = 1.2;
    double *p = &a;

    const double pi = 3.14;
    //p = &pi;错误，常指针才能指向常变量
    const double *cptr;
    cptr = &pi;

    cptr = &a;
    //*cptr = 1.5;//常指针无法修改值

    int err = 0;
    //int *const curErr;//定义时必须初始化
    int *const curErr = &err;

    const int err3 = 0;
    //int *const curErr3 = &err3;//无法指向const常变量err3

    int err2 = 0;
    const int* curErr2;//定义时无需初始化
    //*curErr2 = 3;无法修改指针指向空间的值，但可以修改指针指向
    //const int* curErr2 = &err2;

    //指向常对象的常指针
    const int* const pnor = &err2;
    int const* const pnor2 = &err2;

    //const写在string前面或后面均可
    const string s1;
    string const s2;
    return 0;
}

#if 0
1. 指向常对象的指针（不是常指针）const TYPE* p; TYPE const* p;可以指向普通变量也可指向常变量。
2. const TYPE* p; TYPE const* p;当const在*左侧时（指向常对象的指针），const修饰的指针可以更改指针指向，不能通过指针修改其指向的内存空间所存放的值。定义指针时无需初始化。
3. TYPE* const p;当const在*右侧时（常指针），const修饰的指针指向的地址不可改变（定义指针时必须初始化），但是可以修改指向的值，并且不能指向const常变量。
4. const TYPE* const p; TYPE const* const p;指向常对象的常指针定义指针时必须初始化，并且无法修改指针指向，无法修改指针指向内存空间所存放的值。
#endif
