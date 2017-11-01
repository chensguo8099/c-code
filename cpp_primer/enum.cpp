/*************************************************************************
	> File Name: enum.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Oct 2017 06:34:59 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int m;//这是变量

const int n = 8;//这是const常量

//多定义使用常量时,可用枚举
#if 0
const int input = 0;//输入
const int output = 1;//输出
const int append = 2;//追加
#endif
enum openmodes { 
    input, 
    output, 
    append 
};//自动变为input = 0, output = 1, append = 2

enum Forms {
    shape ,//0
    sphere = 3,//3
    cylinder,//4
    polygon//5
};
/*
枚举类型中的值均为整数，枚举类型中的成员未赋值则从0自增，若赋值则赋值前还是从0自增，赋值处之后由赋值的值向后自增，枚举成员均为常量
*/

/*
enum test {
    a,
    b = 3.14;
    c
} //错误
*/
int main(){
    double d;
    openmodes a;//a是枚举openmodes类型

    a = input;//a只能赋值为openmodes中的值
    cout << a << endl;

    Forms b, c;
    c = shape;
    b = cylinder;
    cout << c << " " << b << endl;
 
    return 0;
}
