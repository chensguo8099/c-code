/*************************************************************************
	> File Name: string3.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2017 07:04:10 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    string name;
    cout << "请输入你的姓名" << endl;

/*
    cin >> name; //Bill Gates
    cout << name << endl;//Bill
*/

    getline(cin, name);//Bill Gates
    cout << name << endl;//Bill Gates
    return 0;
}

