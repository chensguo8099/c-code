/*************************************************************************
	> File Name: func.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 04:56:14 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

void AddOne(int x){
    x += 1;
}

void AddTwo(int *px){
    *px = *px + 2;
}

void AddThree(int &x){//引用行参
    x += 3;
}

int main(){
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
    cout << "加之前：" << a << endl;
    AddOne(a);
    cout << "加之后：" << a << endl;
    cout << "加之前：" << c << endl;
    //传的是真正的c，不是copy
    AddThree(c);
    cout << "加之后：" << c << endl;
    return 0;
}
