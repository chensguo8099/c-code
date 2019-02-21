/*
	> File Name: test4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月20日 星期三 20时39分51秒
*/
#include <iostream>
#include <vector>
using namespace std;
class Test{
    //friend Test operator+(Test &a1, Test &a2);
    public:
    Test(int a){
        this->a = a;
    }
    void printT(){
        cout << this->a << endl;
    }
    Test &operator=(const Test &a1){
        this->a = a1.a;
        return *this;
    }
    Test &operator+(Test &a1){
        this->a += a1.a ;
        return *this;
    }
    ~Test(){}
    private:
    int a;
};

#if 0
//全局重载  通过friend友元
Test operator+(Test &a1, Test &a2){
    Test tmp(10);
    tmp.a = a1.a + a2.a;
    return tmp;
}
#endif 
int main(){
    Test a1(5), a2(15);
    a1.printT();//5
    a2.printT();//15
    a1 + a2 = a2;
    a1.printT();//15
    return 0;
}
