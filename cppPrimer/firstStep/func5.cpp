/*************************************************************************
	> File Name: func5.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 08:57:32 PM PST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;

#if 0
//非引用行参
void print(vector<double> v){
    vector<double>::iterator start = v.begin();
    while(start != v.end()){
        cout << *start << endl;
        start++;
    }
}
#endif

//引用行参
void print_2(vector<double> &v){
    vector<double>::iterator start = v.begin();
    while(start != v.end()){
        cout << *start++ << endl;
    }
}

void print(vector<double>::const_iterator beg,
           vector<double>::const_iterator end){
    while(beg != end){
        cout << *beg++ << endl;
    }
}

double vectorSum(vector<double>::iterator begin,
                 vector<double>::iterator end){
    double sum = 0.0;
    while(begin != end){
        sum += *begin++;
    }
    return sum;
}

int main(){
    vector<double> dvec;
/*
    dvec.push_back(1.1);
    dvec.push_back(2.2);
    dvec.push_back(3.3);
*/
    cout << "Enter double type elements for vector:(ctrl+d to end)" << endl;
    double dval;
    while(cin >> dval)
        dvec.push_back(dval);
    cout << "你输入的数是："<< endl;

    //非引用行参使用时，当数据非常多时还需多次copy
    //print(dvec);
    //引用传参比上一种方法要好，但是对于vector也不是C++程序员习惯的传参
    //print_2(dvec);
    //事实上，C++程序员更喜欢传递vector的迭代器
    print(dvec.begin(), dvec.end());

    cout << "向量中的数据元素之和是：" << vectorSum(dvec.begin(), dvec.end()) << endl;
    return 0;
}
