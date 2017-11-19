/*************************************************************************
	> File Name: ptr3.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Nov 2017 11:15:28 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    int ia[] = {9, 2, 4, 6, 8};
    int *ip = ia;
    cout << *ia << endl;
    cout << *ip << endl;

    //ip = &ia[4];//同ip = ia; int *ip2 = ip + 4;
    ip = &ia[0]; //同ip = ia;
    cout << *ip << endl;
    return 0;
}
