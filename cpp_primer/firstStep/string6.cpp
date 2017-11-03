/*************************************************************************
	> File Name: string6.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Nov 2017 06:02:26 PM PDT
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int main(){
    string s1("hello,");
    string s2("world\n");

    string s3 = s1 + s2;
    cout << s3 << endl;

    s1 += s2;
    cout << s1 << s1.size() << endl;

    //string s4 = "hello" + ",";//在其它语言合法（JAVA C#），但在C++不允许，hello和,必须有意个是字符串才行，如果均为字面值则不可以。

    string s5 = s1 + "hello";//相比与s4，这种写法是合法的
    cout << s5 << endl;

    //string s6 = "hello" + "," + s2;//字符串字面值之间连接是非法的，但是其他语言合法（JAVA C#等）
    return 0;
}
