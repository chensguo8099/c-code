/*
    > File Name: list-1.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 20时14分51秒
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Person{
public:
    Person(int a, int b):a(a), b(b){}
    bool operator==(const Person &a) const{
        return a.a == 10;
    }
public:
    int a;
    int b;
};

int main(){
    list<Person> l1;
    Person a1(10, 20), a2(30, 5), a3(22, 6), a4(1, 100);
    l1.push_back(a1);
    l1.push_back(a2);
    l1.push_back(a3);
    l1.push_back(a4);
    list<Person>::iterator it = find(l1.begin(), l1.end(), a1);
    if(it == l1.end()){
        cout << "not fount" << endl;
    }else{
        cout << (*it).a << " " << (*it).b  << endl;
    }
    return 0;
}
