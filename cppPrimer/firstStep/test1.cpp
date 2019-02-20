/*************************************************************************
	> File Name: test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月19日 星期二 20时58分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Test{
public:
    Test(){
        cout << "Test()..." << endl;
    }
    Test(int a, int b){
        cout << "Test(int, int)..." << endl;
        _a = a;
        _b = b;
    }
    void printT(){
        cout << _a << " " << _b << endl;
    }
    ~Test(){
        cout << "~Test()..." << endl;
    }
private:
    int _a;
    int _b;
};

Test gg(){
    cout << "gg begin" << endl;
    Test tmp(5, 5);
    cout << "gg end before return tmp" << endl;
    return tmp;
}
void test(){
    cout << "test begin" << endl;
    //不会调用默认拷贝构造函数,而是直接将tmp的消息给匿名对象
    //然后让匿名对象转正成为test1,观察运行代码发现默认拷贝构造并未调用
    //比下面的方式效率高
    Test test1 = gg();

    //调用默认operator=操作符重载函数,多了一次传参构造的步骤
    //Test test1(10, 20);
    //test1 = gg();

    test1.printT();
    cout << "test end" << endl;

}
int main(){
    test();
    return 0;
}
