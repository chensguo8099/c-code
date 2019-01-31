/*变量屏蔽（变量隐藏）
 *函数屏蔽（函数隐藏） 而不是函数重载
 *每一个版本的函数重载都应该在同一个作用域中声明
 *注意：局部地声明函数是一种不明智的方法
 *--函数的声明应该放在头文件中
 * */

#include<iostream>
#include <string>
using namespace std;

void print(const string &);
void print(double);
void print(int);

void fooBar(int ival){
    //发生函数隐藏
    void print(int);//这是一个局部函数的声明

    //将同名的全局的函数重载进行隐藏，所以下面第一个重载函数就错误了，这叫函数隐藏,并且print(3.14);这条语句也执行局部函数中的print，打印出3
    //print("hello");
    print(ival);
    print(3.14);
}

int main(){
    fooBar(6);
    return 0;
}


void print(const string &s){
    cout << "string:" << s << endl;
}

void print(double d){
    cout << "double:" << d << endl;
}

void print(int i){
    cout << "int:" << i << endl;
}
