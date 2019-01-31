/*************************************************************************
	> File Name: func3.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 05:23:10 PM PST
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

void swap(int &v1, int &v2){
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

//引用行参避免复制，当对象非常大时如果复制则会浪费很多的内存空间和时间

/*
使用引用行参的两种原因：
1.方便传参并对参数修改
2.避免复制所需的时间空间
*/
bool isShorter(string &s1, string &s2){
    return s1.size() < s2.size();
}
//将不许要修改的引用行参定义为const类型
//因为非const引用行参在使用时并不灵活，不能用const对象初始化，也不能用字面值、或产生右值的表达式实参进行初始化
string::size_type find_char(const string &s, char c){
    string::size_type i = 0;
    while(i != s.size() && s[i] != c){
        ++i;
    }
    return i;
}
int main(){
    int i = 1, j = 2;
    swap(i, j);
    cout << i << j << endl;

    string s1("oneoneoneoneoneoneoneoneoneoneoneoneoneoneone");
    string s2("hellohellohellohellohellohellohellohellohellohello");

    //把s1和s2复制，传进去，浪费时间空间
    if(isShorter(s1, s2)){
        cout << "s1短" << endl;
    }
    cout << "s2短" << endl;

    string s("abcod");
    string::size_type x = find_char(s, 'o');
    cout << x << endl;//3
    return 0;
}
