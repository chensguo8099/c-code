/*
    > File Name: test14.cpp
    > Author: JerryChen
    > Created Time: 2019年02月23日 星期六 22时49分56秒
*/

#include <iostream>
using namespace std;
//图形类 称之为抽象类
//不管这个类中有无成员属性，只要这个类有纯虚函数，就是一个抽象类。
//抽象类是不能实例化对象的
class Shape{
public:
    //求图形面积的方法
    //表示图形类声明一个方法getArea()，它是一个纯虚函数，没有函数的实现。
    virtual double getArea() = 0;
};

//正方形
//如果说一个普通类继承拥有纯虚函数的类，必须要重写这个纯虚函数
//如果说不去重写纯虚函数，继承过来的类仍是抽象类，不能被实例化
class Rect : public Shape{
public:
    Rect(int a){
        this->a = a;
    }
    virtual double getArea(){
        cout << "正方形面积" << endl;
        return a*a;
    }
private:
    int a;//正方形边长
};

class Circle:public Shape{
public:
    Circle(int r){
        this->r = r;
    }
    virtual double getArea(){
        cout << "圆型面积" << endl;
        return 3.14*r*r;
    }

private:
    int r;
};

//抽象类接口
//x写接口后则不需要再让main与各个抽象类的实例进行交互
//直接可以让main函数与该函数进行交互，该函数将抽象类转化为实例
void printArea(Shape *sp){
    sp->getArea();
}

int main(){
    Shape *sp = new Circle(20);
    sp->getArea();
    return 0;
}
