/*************************************************************************
	> File Name: func1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 05:11:01 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

void func(){

}
void func(int i){

}//第一个和第二个是函数的重载

#if 0 //这个函数与第二个函数不能实现重载，为同一个函数，因为是为了兼容C
void func(int const i){

}
#endif
