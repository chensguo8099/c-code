/*************************************************************************
	> File Name: overload1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2017 05:23:36 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

string init(){
    return "Hello";
}

void fcn(){
    //变量名屏蔽函数名
    //int init = 0;//pay attention ! 变量名init和上面的函数名重名
    string s = init();
    cout << s << endl;
}

int main(){
    fcn();
    return 0;
}
