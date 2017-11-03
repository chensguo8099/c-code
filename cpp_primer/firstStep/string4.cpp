/*************************************************************************
	> File Name: string4.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Nov 2017 05:31:22 PM PDT
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int main(){
    //第一种方法查看字符串大小
    string st("hello");
    cout << "字符串的大小：（字符的个数）" << st.size() << endl;

    //第二种方法查看字符串大小
    string::size_type size = st.size();//size_type类型是一个unsigned long类型，如果像下面的代码误认为st.size()返回的是是int类型，那么当数据过大的时候可能会发生不必要的隐含错误，所以尽量用size_type类型更为标准一些
    cout << size << endl;
/*
    int size = st.size();
    cout << size << endl;
*/

    string s;

    if(s.size() == 0){
        cout << "这是一个空字符串" << endl;
    }

    //使用C++的话还是尽量脱离上述的写法
    if(s.empty()){
        cout << "这是一个空字符串" << endl;
    }
    return 0;
}
