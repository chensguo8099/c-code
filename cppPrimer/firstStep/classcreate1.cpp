/*************************************************************************
	> File Name: classcreate1.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Nov 2017 04:12:02 AM PST
 ************************************************************************/
#if 0
注意：
通常我们把类的定义放在头文件（class.h）中写
把类外部定义的成员函数放在类的源文件中（class.cpp）
#endif


#include<iostream>
#include <string>
using namespace std;

class Dog{
    public:
    int num;
    string name;
};
//Dog a;
//如果创建对象为全局对象或静态对象（C++会把静态对象等同与全局对象），则C++会对类数据类型进行合理的初始化，但如下中的局部对象类中的基本数据类型则不会被初始化
//最好不要依赖C++创建的默认构造函数，要自己写构造函数
int main(){
    cout << "Hello,构造函数！" << endl;

    Dog a;//调用Dog类的默认构造函数取创建对象a
    //如果每写构造函数，C++会创建默认构造函数 帮助我们把类初始化
    
    cout << a.name << endl;//空串
    cout << a.num << endl;//C++默认构造函数不会对基本数据类型（int）初始化
    return 0;
}
