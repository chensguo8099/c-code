/*************************************************************************
	> File Name: string5.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Nov 2017 05:46:37 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    string a("张飞");
    string b("刘备");

    //b = a;//现在a和b都是张飞！

    if(a == b){
        cout << "张飞和刘备相等" << endl;
    }else{
        if(a > b){
            cout << "张飞比刘备大" << endl;//执行这条，因为z比l大
        }else{
            cout << "张飞比刘备小" << endl;
        }
    }

    string big = "big", small = "small";
    string s1 = big;

    if(big == small){
        cout << "big == small" << endl;
    }else{
        cout << "big != small" << endl;
    }
    if(big <= small){
        cout << "big <= s1" << endl;
    }
    return 0;
}
#if 0
    string类型比较大小的时候，根据字符串的首字母的ASCII码进行比较，如果是中文则转换成其拼音的首字母的ASCII进行比较，比如张飞就是z，刘备就是l
#endif
