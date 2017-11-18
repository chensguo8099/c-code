/*************************************************************************
	> File Name: bitset3.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 16 Nov 2017 04:32:38 AM PST
 ************************************************************************/

#include<iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
/*
    bitset<4> fourBits;
    cout << fourBits << endl;

    bitset<5> fiveBits(string("10101"));
    cout << fiveBits << endl;//10101

    bitset<8> eightBits(255);
    cout << eightBits << endl;//1111 1111
*/
    //通过键盘输入 进行初始化
    bitset<8> eightBits;
    cout << "Enter a 8-bit sequence:";
    cin >> eightBits;//输入二进制数，若位数不足8个则未填充的左侧均为0
    cout << endl << eightBits << endl;

    //count()方法计算1的个数
    cout << "有" << eightBits.count() << "个1！" << endl;
    cout << "有" << eightBits.size() - eightBits.count() << "个0！" << endl;

    bitset<8> flipInput(eightBits);
    flipInput.flip();
    cout << flipInput << endl;

    bitset<8> eightMoreBits;
    cout << "Enter another 8-bit sequence:";
    cin >> eightMoreBits;
    cout << endl;

//位操作优先级较低 所以不加括号会报错
    cout << (eightBits & eightMoreBits) << endl;//位与运算
    cout << (eightBits | eightMoreBits) << endl;//位或运算
    cout << (eightBits ^ eightMoreBits) << endl;//位异或运算 两者相同为0 不同为1

    return 0;
}
