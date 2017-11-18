/*************************************************************************
	> File Name: arr2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Nov 2017 07:06:32 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    const int array_size = 7;
    int ia1[] = {1, 2, 3, 4, 5, 6, 7};
    int ia2[array_size];

    //size_t类型是专门作为数组下标用的
    for(size_t ix=0; ix!=70; ++ix){//ix!=70这种写法就是越界了但不会报错
        cout << ia1[ix] << endl;
    }

    //ia2 = ia1; //写法错误,在C++中未定义，并不会把数组ia1里的数据copy到ia2中
    for(size_t ix=0; ix!=array_size; ++ix){
        ia2[ix] = ia1[ix];
    }


    return 0;
}
