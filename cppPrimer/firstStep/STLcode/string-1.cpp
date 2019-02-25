/*
    > File Name: string-1.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 13时56分13秒
*/

#include <iostream>
#include <string>
using namespace std;

//string替换
void test(){
	string s = "abc12345ff";
	s.replace(0, 5, "zzz");//zzz12345ff
	cout << s << endl;
}
//string比较
void test1(){
	string s1 = "A2345";
	string s2 = "a9999";
	cout << s1.compare(s2) << endl;
}
//字符串截取
void test2(){
	string s = "abcdefg";
	string mysubstr = s.substr(1, 3);
	cout << mysubstr << endl;
}
//插入删除
void test3(){
	string s = "abcdefg";
	s.insert(4, "222");
	s.erase(0, 2);
	cout << s << endl;
}
int main(){
	//test();
	//test1();
	//test2();
	test3();
    return 0;
}
