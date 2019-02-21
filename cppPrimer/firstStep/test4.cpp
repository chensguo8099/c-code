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
    friend Test operator-(Test &a1, Test &a2);
    public:
    Test(int a){
        this->a = a;
        this->b = 0;
    }
    Test(int a, int b){
        this->a = a;
        this->b = b;
    }
    void printT(){
        cout << this->a << " " << this->b << endl;
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
    int b;
};

#if 0
//全局重载  通过friend友元
Test operator+(Test &a1, Test &a2){
    Test tmp(10);
    tmp.a = a1.a + a2.a;
    return tmp;
}
#endif 
Test operator-(Test &a1, Test &a2){
    Test tmp(a1.a - a2.a, a1.b - a2.b);
    return tmp;
}
int main(){
    Test a1(5, 5), a2(15);
    /*
    a1.printT();//5
    a2.printT();//15
    a1 + a2 = a2;
    a1.printT();//15
    */
    //调用全局operator-重载后返回匿名对象作为=重载的参数
    Test a3 = a1 - a2;
    a3.printT();//-10
    return 0;
}
