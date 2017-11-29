/*************************************************************************
	> File Name: trycatchstack.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 04:47:00 PM PST
 ************************************************************************/

#include<iostream>
#include "stack.h"
using namespace std;

int main(){
    try{
        Stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        cout << st.pop() << endl;//3
        cout << st.top() << endl;//看栈顶元素
        cout << st.pop() << endl;//2
        cout << st.pop() << endl;//1
        cout << st.top() << endl;//异常
        //cout << st.pop() << endl;//异常
    }
    catch(const exception& e){
        cerr << "发生异常" << e.what() << endl;
    }
    cout << "Hello stack" << endl;
    return 0;
}
