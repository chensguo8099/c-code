/*************************************************************************
 编写一个程序读入两个string对象，测试他们是否相等。若不相等，则指出两个中
 哪个较大，接着改写程序，测试他们的长度是否相等，若不相等，则指出两个中哪
 个较长。
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;

    cout << "Enter two strings:" << endl;
    cin >> s1 >> s2;

    //直接判断两个string类型对象是否一样
    if(s1 == s2)
        cout << "they are equal" << endl;
    else if(s1 > s2)
        cout << "\"" << s1 << "\" is begger than"
            << "\"" << s2 << "\"" << endl;
    else
        cout << "\"" << s2 << "\" is begger than"
            << "\"" << s1 << "\"" << endl;


    //比较两个string类型对象的长度是否相等
    string s3, s4;
    string::size_type len3, len4;//不要用int
    cout << "输入两个string:" << endl;
    cin >> s3 >> s4;
    len3 = s3.size();//大小就是长度，就是字符的个数
    len4 = s4.size();

    if(len3 == len4)
        cout << "they are the same" << endl;
    else if(len3 > len4)
        cout << "\"" << len3 << "\" is longer than"
            << "\"" << len4 << "\"" << endl;
    else
        cout << "\"" << len4 << "\" is longer than"
            << "\"" << len3 << "\"" << endl;
    return 0;
}
