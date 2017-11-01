/*************************************************************************
	> File Name: string2.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2017 06:55:56 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    string s1, s2;
    string s;

    cin >> s;
    cout << s << endl;//若s输入一个前面为空格的字符串则会清除前面的字符串

/*
    //当s1为含有空格的字符串时会遇到一个问题就是字符串在空格处截断
    cin >> s1;
    cin >> s2;
    cout << s1 << " " << s2 << endl;
*/
    return 0;
}

#if 0
cin的特点有：
1. 读取并忽略开头所有的空白字符，如空格/换行/制表符
2. 读取字符直到再次遇到空白字符，读取终止

getline与cin的区别是它不会像cin一样忽略前面的空格
#endif

