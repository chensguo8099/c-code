/*************************************************************************
	> File Name: bitset.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Nov 2017 04:13:31 AM PST
 ************************************************************************/

#include<iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
    //bitset也在std空间中
    bitset<32> a;//a的大小是32位二进制，全部是0
    cout << a << endl;

    bitset<16> b(0xffff);//1111 1111 1111 1111
    cout << b << endl;

    bitset<32> c(0xffff);
    cout << c << endl;//仅后面（右）16个1，前面（左）16位全1

    bitset<128> d(0xffff);
    cout << d << endl;

    bitset<32> e(156);
    cout << e << endl;

    string str("11111110000000011001101");
    bitset<32> f(str, 5, 4);
    cout << f << endl;

    bitset<32> g(str, str.size() - 4);
    cout << g << endl;
    return 0;
}
