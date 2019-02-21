/*
    > File Name: test5.cpp
    > Author: JerryChen
    > Created Time: 2019年02月21日 星期四 18时45分43秒
*/

#include<iostream>
using namespace std;

class Test{
friend ostream &operator<<(ostream &couT, Test &a);
public:
    Test(int a){
        this->res = a;
    }
private:
    int res;
};

//cout是ostream类型的对象 实现<<操作符的重载
ostream &operator<<(ostream &couT, Test &a){
    cout << a.res << "  OK~";
    return couT;
}

int main(){
    Test obj(10);
    cout << obj;//输出10  OK~
    return 0;
}
