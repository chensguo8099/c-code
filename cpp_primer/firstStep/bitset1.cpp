/*************************************************************************
	> File Name: bitset1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Nov 2017 05:16:00 AM PST
 ************************************************************************/

#include <iostream>
#include <bitset> 
using namespace std;

int main(){
    bitset<32> a(156);
    cout << a << endl;

    //any()函数返回真(返回1)如果有位被设置为1，否则返回假(返回0)。
    //none()函数返回真(返回1)如果没有位被设为1，否则返回假(返回0)。
    bool is_set = a.any();
    if(is_set)
        cout << "a里至少有一个1！" << endl;

    cout << "a.any()函数的返回值是：" << is_set << endl;//1

    bool is_not_set = a.none();
    if(is_not_set)
        cout << "a里不是一个1都没有" << endl;

    cout << "a.none()函数的返回值是：" << is_not_set << endl;//0

    size_t bits_set = a.count();
    cout << "a里一共有" << bits_set << "个1！" << endl;

    cout << "a的大小：" << a.size() << endl;//32
    cout << "a里有" << a.size() - a.count() << "个0！" << endl;//28
    return 0;
}
