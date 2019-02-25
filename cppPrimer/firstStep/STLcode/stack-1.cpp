/*
    > File Name: stack-1.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 19时12分24秒
*/

#include <iostream>
#include <stack>
using namespace std;

class Person{
public:
    Person(){}
    Person(string name, int age):_name(name), _age(age){};

public:
    string _name;
    int _age;
};


int main(){
    stack<Person> s;

    for(int i = 0; i < 5; i++){
        Person obj;
        obj._name = 'a' + i;
        obj._name += "选手";
        obj._age  = rand()%5 + 25;

        s.push(obj);
    }
    while(!s.empty()){
        cout << "name : " << s.top()._name  << " age : " << s.top()._age << endl;
        s.pop();
    }

    return 0;
}
