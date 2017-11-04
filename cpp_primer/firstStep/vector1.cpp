/*************************************************************************
	> File Name: vector1.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2017 10:32:30 PM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);

    vector<int> v2(v1);//v1的值传给v2
    //vector<string> v3(v1);//错误 v3是string类型向量但是v1是int类型，这种写法除非v3和v1的类型是一样的

    vector<int> v4(10, -1);
    vector<int> v6(10);//默认10个0
    vector<string> v5(10, "hi!");
    vector<string> v7(10);//10个空串

    cout << v1[0] << endl;//10
    cout << v2[0] << endl;//10
    cout << v4[0] << endl;//-1
    cout << v5[0] << endl;//hi!
    cout << v6[0] << endl;//0
    cout << v7[0] << endl;
    
    v1[0] = 100;
    cout << v1[0] << endl;
    v7[0] = "Hello!";
    cout << v7[0] << endl;//Hello!
    return 0;
}
