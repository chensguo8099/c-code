/*************************************************************************
	> File Name: bitset2.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Nov 2017 07:07:48 AM PST
 ************************************************************************/

#include<iostream>
#include <bitset>
using namespace std;

int main(){
    bitset<32> a;
    cout << a << endl;

    //bitset可以用下标对位进行操作
    a[5] = 1;
    cout << a << endl;
/*
 * 所有这些方法操作的时候起始0在最右侧
    set(index)方法就是把index位置1
    set()方法把所有位置1
    reset(index)方法就是把index位置0
    reset()方法把所有位置0
    flip(index)方法把index处的位反转
    flip()方法把所有位反转
*/
    for(int index=0; index != 32; index+=2){
        //a[index] = 1;
        a.set(index);
        cout << a << endl;

        a.set();
        cout << a << endl;

        a.reset(5);
        cout << a << endl;

        a.flip();
        cout << a << endl;

        a.flip(8);
        cout << a << endl;

        unsigned long b = a.to_ulong();//将b显示为十进制数
        cout << b << endl;
    }
    cout << a << endl;
    return 0;
}
