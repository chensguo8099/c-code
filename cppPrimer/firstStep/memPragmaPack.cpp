/*
    > File Name: test22.cpp
    > Author: JerryChen
    > Created Time: 2019年02月21日 星期四 23时50分12秒
*/
#include <iostream>
#include <cstdio>
#pragma pack(8)
class T{
    char c1;//1
    int a;//4
    short int c2;//2
    int b;//4
    //static int c;//不占用类对象空间 存储于全局数据区
};

struct T1{
    char c1;//1
    long int c2;//8
    char c3;//1
    long int c4;//8
    float b;//4
    int a;//4
    //static int c;
};
int main(){
    //结果为12
    printf("%lu\n", sizeof(T));//16
    printf("%lu\n", sizeof(T1));//40
    return 0;
}
