/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Nov 2017 03:04:23 AM PST
 ************************************************************************/
//多用迭代器 少用下标操作 这样的操作是非常现代的C++操作
#include<iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v(10, 8);
    //begin()操作返回一个迭代器
    //指向向量里第一个数据元素
    vector<int>::iterator iter = v.begin();
    //error: vector<int>::const_iterator iter = v.begin();
    vector<int>::iterator end = v.end();

    while(iter != end){
        //迭代器实际上是一个指针
        *iter = *iter * 2; //通过迭代器修改数据,此处无法用常迭代器
        ++iter;
    }
/*
    iter++;
    *iter = 10;

    for(vector<int>::size_type i=0; i!=v.size(); ++i){
        cout << v[i] << endl;
    }
*/
    iter = v.begin();
    iter = iter + 3;
    *iter = 10;

    vector<int>::iterator mid = v.begin() + v.size()/2;
    *mid = 88;


    //begin是指向元素首位的迭代器，end则是指向末尾元素的下一个位置的迭代器，通常把此迭代器称为超出末端迭代器
    for(vector<int>::iterator j=v.begin(); j!=v.end(); ++j){
        cout << "迭代器" << *j << endl;
    }


    //常迭代器
    for(vector<int>::const_iterator j=v.begin(); j!=v.end(); ++j){
        cout << "迭代器" << *j << endl;//不同过迭代器修改数据，仅读数据
    }

    return 0;
}
