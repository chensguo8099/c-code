/*************************************************************************
	> File Name: classType.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Oct 2017 07:11:51 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

struct Cat{
    double weight;
    double height;
};

class Dog{
    //类中未写范围则默认为private
    double weight;//体重
    double height;//身高
};//注意分号!!
//struct和class是有区别的 c语言的struct功能简单，但是C++的struct和class是几乎一样的，只是默认访问级别不一样，struct的默认访问级别是public，C++的struct功能比C语言的struct要强大



class student{
    //类成员 ： 1. 数据成员 2. 成员函数
    //public private;
};

class Sale_item{
    public:
    //类的操作: 成员函数
    private://无法初始化，需要使用构造函数进行初始化
    std::string isbn;//书号
    unsigned units_sold;//销售数量
    double revenue;//金额
};

int main(){
    double d = 0.0;//普通变量定义
    int a;//a是一个变量，int类型
    Dog b;//b是一个变量，Dog类型
    student c;
    cout << "hello class!" << endl;

    return 0;
}
/*
 *c++中有了类类型，我们就有了设计类型的能力
 * */
