/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月19日 星期二 11时17分26秒
 ************************************************************************/

#include<iostream>
#include <cmath>

using namespace std;

class Point{
    public:
    void setPoint(double x, double y){
        _x = x;
        _y = y;
    }
    void distance(double x, double y){
        cout <<sqrt((x-_x)*(x-_x) + (y-_y)*(y-_y))<< endl;
    }

    private:
    double _x;
    double _y;
};

class Circle{
    public:
    void setCircle(double x, double y, double r){
        _x = x;
        _y = y;
        _r = r;
    }

    bool judgeTouch(Circle &anotherCircle){
        if(((_x - anotherCircle._x)*(_x - anotherCircle._x)+
            (_y - anotherCircle._y)*(_y - anotherCircle._y)) < 
          ((_r + anotherCircle._r) * (_r + anotherCircle._r)))
            return true;
        else
            return false;
    }
    private:
    double _x;
    double _y;
    double _r;
};

int main(){
    Point obj;
    obj.setPoint(0, 0);
    obj.distance(3, 0);
    Circle a1, a2;
    a1.setCircle(0, 0, 1);
    a2.setCircle(3, 0, 2.000000000000001);

    if(a1.judgeTouch(a2)){
        cout << "相交" << endl;
    }
    else
        cout << "不相交" << endl;
    return 0;
}
