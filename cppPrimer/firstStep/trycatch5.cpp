/*************************************************************************
	> File Name: trycatch5.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 04:24:29 PM PST
 ************************************************************************/

#include<iostream>
#include <bitset>
#include <string>
#include <stdexcept>
using namespace std;

int main(){
    try {
        //string s("1010110010");//正确
        string s("10ab110010");//异常
        bitset<10> b(s);
    }
    catch(invalid_argument err){//invalid_argument（非法的参数）在stdexcept中
        cout << "bitset error:" << err.what() << endl;//what返回字符串，看到异常信息
    }
    return 0;
}
