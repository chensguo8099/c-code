/*************************************************************************
	> File Name: namespace.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2017 06:05:19 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;//std命名空间
//就像文件放在文件夹里：名称放在名称空间里
//在外部头文件里不要写using namespace 无法与调用头文件的文件进行关联
//：：是作用域操作符，前面是名称空间
//cout名称 endl名称

//using std::cin;
//using std::string;
//using std::cout;
//using std::endl;

int main(){
    //std::string s;
    string s;
    //std::cout << "hello 命名空间" << std::endl;
    cout << "hello 命名空间" << endl;
    cout << "请输入一个字符串";
    cin >> s;//输入的字符串不能有空格 否则会被截断
    cout << "你输入的是：" << s << endl;

    return 0;
}
