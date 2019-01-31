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
    cout << c << endl;//仅后面（右）16个1，前面（左）16位全0

    bitset<128> d(0xffff);
    cout << d << endl;//仅后面16个1，前面112个0

    bitset<32> e(156);
    cout << e << endl;//156的32位二进制形式

    string str("111110101000000011001101");
    bitset<32> f(str, 5, 4);//从字符串中第5个开始（起始为0）向后4位作为f的副本
    cout << f << endl;

    bitset<32> g(str, str.size() - 4);
    cout << g << endl;

    string s("1010110");
    bitset<10> h(s);
    h[6] = 0;//0000010110
    cout << s << endl;
    cout << h << endl;

    cout <<" -------------- "<< endl;
    string s1("101011001101");
    bitset<16> m(s1, 9);//起始为0，从第九位开始（包括第九位）作为副本
    bitset<16> o(s1, 3, 5);//s1起始为0，从第三位开始（包括第三位）向后5位作为副本
    cout << m << endl;//0000000000000101
    cout << o << endl;//0000000000001100
    return 0;
}
