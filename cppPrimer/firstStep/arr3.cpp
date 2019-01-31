/*************************************************************************
	> File Name: arr3.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2017 05:28:18 AM PST
 ************************************************************************/

#include<iostream>
#include <cstdlib>
using namespace std;

int main(){
    int a[10];
    int n;
    cout << "你想要多大数组：" << endl;
    cin >> n;

    //C风格
    int *p = (int *)malloc(n * sizeof(int));
    if(p != NULL){
        cout << "C创建动态数组成功！" << endl;
    }
    free(p);

    //C++风格
    int *pia = new int[n];
    if(pia != NULL){
        cout << "C++创建动态数组成功！" << endl;
    }
    delete[] pia;//[]说明我们申请的是个数组，所以在堆上释放
    //int *pia = new int;
    //delete pia;

    return 0;
}
