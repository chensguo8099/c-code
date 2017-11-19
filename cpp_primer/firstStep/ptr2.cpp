/*************************************************************************
	> File Name: ptr2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Nov 2017 09:50:53 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int ival = 1024, ival2 = 2048;
    //指针声明时可以无初始化，之后赋值进行初始化也是可以的
    //引用不能没有初始化
    int *pi = &ival, *pi2 = &ival2;
    int &ri = ival, &ri2 = ival2;

    //指针可以后续修改指向的对象，但是引用引用了一个对象后就无法改变


    cout << ival << "," << *pi << "," << ri << endl;//1024,1024,1024
    cout << ival2 << "," << *pi2 << "," << ri2 << endl;//2048,2048,2048
    return 0;
}
