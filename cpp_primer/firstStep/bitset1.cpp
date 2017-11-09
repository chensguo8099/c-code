/*************************************************************************
	> File Name: bitset1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Nov 2017 05:16:00 AM PST
 ************************************************************************/

#include<iostream>
#include <iostream>
#include <bitset> 
using namespace std;

int main(){
    bitset<32> a(156);
    cout << a << endl;

    //any()函数返回真如果有位被设置为1，否则返回假。
    //none()函数返回真如果没有位被设为1，否则返回假。
    bool is_set = a.any();
    if(is_set)
        cout << "a里至少有一个1！" << endl;

    bool is_not_set = a.none();//一个1都没有！
    if(is_not_set)
        cout << "a里不是一个1都没有" << endl;

    size_t bits_set = a.count();
    cout << "a里一共有" << bits_set << "个1！" << endl;

    cout << "a的大小：" << a.size() << endl;
    cout << "a里有" << a.size() - a.count() << "个0！" << endl;
    return 0;
}
