/*************************************************************************
	> File Name: string.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2017 06:21:49 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){
    char name[10] = "zhangfei";//C语言做法
    string s("liubei");//C++做法

    cout << name << endl;
    cout << s << endl;

    //4中初始化方法
    string s1;//调用string的默认构造函数
    string s2("hello");//小括号就是调用string对象构造函数
    string s3(s2);
    string s4(10, 'a');

    //string s5 = "hello";//这是一种不好的方法，先做初始化调用string默认构造函数，又做了赋值操作，在JAVA和C#中有这样的写法，但是在C++这样写效率低。


    cout << s1 << endl;//空字符串
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;//10个字符a

    cout << s2 << endl;//这是C++分割的字符串，后无'\0'
    cout << "hello" << endl;//C语言风格的字符数组类型，后有空字符'\0',字符串字面值
    return 0;
}
