/*************************************************************************
	> File Name: func2.cpp
	> Author: 

	> Mail: 
	> Created Time: Tue 28 Nov 2017 05:13:55 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int getBigger(int x, const int *y){
    return x > *y ? x : *y;
}

int main(){
    int a = 2, b = 9;
    cout << getBigger(a, &b) << endl;
    return 0;
}
