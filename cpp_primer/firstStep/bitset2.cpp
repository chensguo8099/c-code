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

    a[5] = 1;
    cout << a << endl;

    for(int index=0; index != 32; index+=2){
        a.set(index);
        //a[index] = 1;
        cout << a << endl;

        a.set();
        cout << a << endl;

        a.reset(5);
        cout << a << endl;

        a.flip();
        cout << a << endl;
    }
    return 0;
}
