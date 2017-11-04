/*************************************************************************
	> File Name: vector2.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Nov 2017 10:48:57 PM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int a[100];//数组a里可以保存100个数

    vector<int> ivec;//ivec是空的，里面没有数据，大小为0
    cout << ivec.size() << endl;

/*
    for(vector<int>::size_type i=0; i!=10; ++i){
        cin >> ivec[i];
    }//起初创建的容器容量为0，所以无法用下标进行遍历，所以for循环的写法错误
*/

/*
    //解决方法1：
    vector<int> ivec1(10);//提前定义大小
    for(vector<int>::size_type j=0; j!=10; ++j){
        cin >> ivec1[j];
    }
*/

    //解决方法2：
    int k;
    for(vector<int>::size_type x=0; x!=5; ++x){
        cin >> k;
        ivec.push_back(k);
    }
    for(vector<int>::size_type y=0; y!=ivec.size(); ++y){
        cout << ivec[y] << endl;
    }


    cout << "请输入一些字符串：" << endl;
    string word;
    vector<string> text;

    //while(cin >> word){
    //   text.push_back(word);
    //}//有空格的串输入进去的话，空格后的串会被删除
    while(getline(cin, word)){
        text.push_back(word);
    }

    for(vector<string>::size_type c=0; c!=text.size(); ++c){
        cout << text[c] << endl;
    }

    return 0;
}
