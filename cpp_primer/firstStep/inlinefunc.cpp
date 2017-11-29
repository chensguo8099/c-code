/*************************************************************************
	> File Name: inlinefunc.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Nov 2017 01:29:52 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
#if 1 
//习惯将内联函数的声明和定义均放入头文件中
//带有inline的函数：内联函数
inline int sum(int a, int b){
    return a + b;
}

inline const string &shortString(const string &s1, const string &s2){
    return s1.size() < s2.size() ? s1 : s2;
}//返回一个const string & 引用类型的常字符串

inline bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}
#endif

int main(){
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int y[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(size_t i=0; i<9; ++i){
        cout << sum(x[i], y[i]) << endl;
        //cout << x[i] + y[i] << endl;//内联函数编译的时候就变成这个样子了
    }

    cout << shortString("hello", "bill") << endl;
    return 0;
}
