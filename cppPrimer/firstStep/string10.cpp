/*************************************************************************
 编写程序输入带标点符号的string，输出无标点符号的string
 ************************************************************************/

#include<iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string s, result_str;
    char ch;
    bool has_punct = false;
    cout << "Enter a string:" << endl;//不用cin>>s 因为接收到空格就结束了
    getline(cin, s);

    for(string::size_type index = 0; index != s.size(); ++index){
        ch = s[index];
        if(ispunct(ch))
            has_punct = true;
        else
            result_str += ch;
    }
    if(has_punct)
        cout << "结果" << endl << result_str << endl;
    else
        cout << "在输入的字符串中没有发现标点符号" << endl;

    return 0;
}
