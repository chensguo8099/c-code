/*************************************************************************
	> File Name: func4.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 05:44:39 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

//传递指向指针的引用
void ptrswap(int *&v1, int *&v2){
    int *tmp = v2;
    v2 = v1;
    v1 = tmp;
}

int main(){
    int i = 10;
    int j = 20;
    int *pi = &i;
    int *pj = &j;
    ptrswap(pi, pj);
    //不是交换两个数，而是交换两个指针
    cout << i << j << endl;//1020
    cout << *pi << *pj << endl;//2010
    return 0;
}
