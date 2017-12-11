/*************************************************************************
	> File Name: createfunc.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Dec 2017 04:16:58 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;
class Dog;
typedef void (Dog::*classptr)();//另一种函数指针的声明方法

class Dog{
public:
    Dog():_year(0){};
    Dog(int year):_year(year){};
    void Print();
private:
    int _year;
};

void Dog::Print(){
    cout << "Dog's age is " << _year << endl;
}

int main(){
    Dog jerry(10);
    classptr pDog1 = &Dog::Print;//指向Print()成员函数的指针
    void (Dog::*pDog)() = &Dog::Print;//类成员函数指针，与上面定义含义相同
    (jerry.*pDog)();
    //jerry.Print();
    return 0;
}
