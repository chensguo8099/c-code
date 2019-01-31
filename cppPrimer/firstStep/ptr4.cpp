/*************************************************************************
	> File Name: ptr4.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Nov 2017 09:08:35 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int ia[3][4] = {
        {0, 12, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int (*ip)[4];
    ip = ia;//ip指向第一行
    cout << **(ip + 1) << endl;//4
    cout << *(*ip + 1) << endl;//12
    cout << (*ip)[2] << endl;//2
    cout << *ip[2] << endl;//8
    cout << *ip[3] << endl;//越界了
    ip = &ia[2];//ip指向第三行
    return 0;
}
