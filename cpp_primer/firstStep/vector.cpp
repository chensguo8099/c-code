/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2017 10:13:16 PM PDT
 ************************************************************************/


//标准库vector类型
//vector是一个动态数组
#include<iostream>
#include <vector>
#include "dog.h"//该头文件包含dog类

using std::vector;
using std::string;


int main(){
    vector<int> ivec;//用来保存int类型数据的一个vector
    vector<double> dvec;
    vector<string> svec;
    vector<dog> dogvec;//保存dog类型数据的一个vector


    vector<int> a;//a是一个空的容器
    vector<int> b(10, 2);//b是一个容器，里面有10个2

    a.push_back(100);
    a.push_back(200);
    a.push_back(300);//向a容器里依次放3个数100，200，300，100的下标为0，200的下标为1，依次类推

    b.push_back(10);
    b.push_back(11);

    std::cout << a.size() << std::endl;//3
    std::cout << b.size() << std::endl;//12

    //不要用int类型的循环变量
    for(vector<int>::size_type i = 0; i != a.size(); ++i){
        std::cout << a[i] << std::endl;
    }//100 200 300
    for(vector<int>::size_type j = 0; j != b.size(); ++j){
        std::cout << b[j] << std::endl;
    }
    return 0;
}
