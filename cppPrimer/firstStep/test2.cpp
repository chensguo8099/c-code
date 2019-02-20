/*************************************************************************
	> File Name: test2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月20日 星期三 12时14分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Test{
public:
    static int get(){return _a;}
    static int set(int a){
        _a = a;
        return _a;
    }

private:
    static int _a;
};
//a不属于Test类 只作为Test类对象的全局变量 存贮在静态区
int Test::_a = 0;

int main(){
    Test obj;
    cout << sizeof(obj) << endl; //1 说明set()方法也不属于Test类
    cout << Test::get() << endl;//0
    cout << Test::set(10) << endl;//10
    return 0;
}
