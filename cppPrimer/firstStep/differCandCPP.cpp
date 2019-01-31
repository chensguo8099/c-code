/*************************************************************************
	> File Name: differCandCPP.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2017 06:52:08 AM PST
 ************************************************************************/

#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string st("Hello World");
    st = st + "bill";
    
/***C风格字符串<-->string***/    //c_str()函数
    cout << st << endl;
    const char*str = st.c_str();//从string转化为C风格的字符串时要用c_str()函数，但是必须用指向常量的指针取指向
    cout << str << endl;



/***数组<-->vector***/
    const size_t arr_size = 6;
    int int_arr[arr_size] = {0, 1, 2, 3, 4, 5};
    //把数组转换为向量
    //               [             )
    //               包括     不包括
    vector<int> ivec(int_arr, int_arr + arr_size);//第一个参数是数组的名称（数组首地址），第二个参数是数组首地址+偏移量，向量能够取到int_arr到int_arr+arr_size-1中的值，即向量vector包括第一个参数，不包括第二个参数
    for(vector<int>::iterator itr=ivec.begin(); itr!=ivec.end(); ++itr){
        cout << *itr << endl;
    }
    vector<int> ivec2(int_arr+1, int_arr+4);//1 2 3
    for(vector<int>::iterator itr=ivec2.begin(); itr!=ivec2.end(); ++itr){
        cout << *itr << endl;
    }
    
    //把向量转换为数组
    vector<int> ivec3;
    int ival;
    cout << "Enter numbers:(ctrl+d to end):" << endl;
    while(cin >> ival){
        ivec.push_back(ival);
    }

    int *parr = new int[ivec.size()];
    size_t ix = 0;
    for(vector<int>::iterator iter = ivec.begin(); 
       iter != ivec.end(); ++iter, ++ix){
        parr[ix] = *iter;
    }
    for(ix=0; ix<ivec.size(); ++ix){
        cout << parr[ix] << endl;
    }
    return 0;
}
