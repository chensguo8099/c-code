/*
    > File Name: test8.cpp
    > Author: JerryChen
    > Created Time: 2019年02月22日 星期五 19时37分34秒
*/

#include <iostream>
using namespace std;

class Parent{
    public:
    Parent(){
        cout << "Parent()..." << endl;
    }
    Parent(int a){
        this->a = a;
        cout << "Parent(int)..." << endl;
    }
    ~Parent(){
        cout << "~Parent()..." << endl;
    }
    int a;
    private:
    static int b;
};
class Child:public Parent{
    public:
    Child(){
        cout << "Child()..." << endl;
    }
    //或者写成 Child(int c_a, int p_a){}也可
    //父类先构造，子类再构造
    Child(int c_a){
        this->a = c_a;
    }
    Child(int c_a, int p_a):Parent(p_a){
        this->a = c_a;
        Parent::a = p_a;//当父子均有数据a时要访问父的a则可用Parent::a
        cout << "Child(int, int)" << endl;
    }
    ~Child(){
        cout << "~Child()..." << endl;
    }
    private:
    int a;
};

int main(){
    Child obj1(10, 20);//先调用Parent的构造 因为Child(int, int)第一个参数来自Parent
    Child obj2(5);
    Child obj3;
    return 0;
}

/*最重要的：
 * 子类调用构造必调用父类构造，至于调用父类的什么构造(默认构造、拷贝构造、或者有参构造等)取决于子类的构造方法。
 * 1.当子类构造中不需要父类对象时父类调用无参构造(默认构造)
 * 2.当子类构造中需要父类对象时根据父类对象传的成员变量还是类决定父类调用有参构造还是拷贝构造
 * */
