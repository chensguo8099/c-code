/*
    > File Name: deque-1.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 16时51分35秒
*/

#include <iostream>
#include <deque>
using namespace std;

void test1(){
    deque<int> d1;
    deque<int> d2(10, 5);
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4(d3);

    for(deque<int>::iterator bbegin = d4.begin(); bbegin != d4.end(); bbegin++)
        cout << *bbegin << endl;
}

void test2(){
    deque<int> d;
    d.assign(2, 5);
    deque<int> d2;
    d2.assign(d.begin(), d.end());
    for(deque<int>::iterator bbegin = d2.begin(); bbegin != d2.end(); bbegin++)
        cout << *bbegin << endl;
    
}

int main(){
    test2();
    return 0;
}
