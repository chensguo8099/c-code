/*************************************************************************
	> File Name: string9.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Nov 2017 07:38:19 PM PDT
 ************************************************************************/

#include<iostream>
#include <string>
//#include <ctype.h>//C语言原来的头文件 但不建议用着个
#include  <cctype>//建议用这样的写法，及C语言头文件前加c，后面去掉.h
using namespace std;

int main(){
    string str("hello");

    cout << str[0] << endl;
    cout << str[4] << endl;

    for(string::size_type x = 0; x != str.size(); ++x){
        cout << str[x];
    }
    cout << endl;

    for(string::size_type y = 2; y != str.size(); ++y){
        str[y] = '*';
    }
    cout << str << endl;



    string s("hello*\"world!!");
    string::size_type count = 0;//标点符号的个数
    for(string::size_type index = 0; index != s.size(); ++index){
        if(ispunct(s[index]))//ispunct是C的标准库函数，用来检查某个字符是不是标点符号
        ++count;
    }
    //C语言库函数：
    //isalnum(c) 用来检查字符是不是字母或数字
    //isalpha(c) 用来检查字符是不是字母
    //iscntrl(c) 用来检查字符是不是控制字符
    //isdigit(c) 用来检查字符是不是数字
    //islower(c) 用来检查字符是不是小写字母
    //ispunct(c) 用来检查字符是不是标点符号
    //isspace(c) 用来检查字符是不是空格
    //isupper(c) 用来检查字符是不是大写字母
    //isxdigit(c) 用来检查字符是不是16进制数
    //tolower(c) 用来把每个字符变成小写
    //toupper(c) 用来把每个字符变成大写

    cout << "这个字符串里有" << count 
        << "个标点符号" 
        << endl;//输出4个，分别是* " ! !
    
    for(string::size_type z = 0; z != s.size(); ++z){
        s[z] = tolower(s[z]);//只将字母变为小写，标点符号不做改动
    }
    cout << s << endl;
    for(string::size_type z = 0; z != s.size(); ++z){
        s[z] = toupper(s[z]);//只将字母变为小写，标点符号不做改动
    }
    cout << s << endl;
    return 0;
}
