/*
    > File Name: test9.cpp
    > Author: JerryChen
    > Created Time: 2019年02月22日 星期五 22时07分57秒
*/

#include <iostream>
#include <string>
using namespace std;

class Yuebuqun{
public:
    Yuebuqun(string kongfu){
        this->kongfu = kongfu;
    }
    virtual void fight(){//修饰成员方法为虚函数
        cout << "岳不群使出了" << kongfu << "打人" << endl;
    }
    string kongfu;
};
//林平之继承了岳不群
class Linpingzhi:public Yuebuqun{
public:
    Linpingzhi(string kongfu):Yuebuqun(kongfu){}
    void fight(){
        cout << "林平之使出了" << kongfu << "打人" << endl;
    }

};
//父类指针兼容子类对象 所以形参用父类指针
//父类指针操作范围比子类本身范围小 所以父类指针可指向子类
//父子均调用fightPeople默认hero为父类指针，则调用两次父类fight
//若要避免调用两次均父类fight、实现多态，则把父类fight定义为virtual
//这里的virtual修饰的是虚函数 与之前的解决菱形继承的虚继承是两个不同的问题
//(-.-) c++真是博大精深 喜欢！
void fightPeople(Yuebuqun *hero){
    cout << "调用打人方法" << endl;
    hero->fight();
}
int main(){
    //Yuebuqun xiaoyy("僻邪剑谱");
    Yuebuqun *xiaoyy = new Yuebuqun("葵花宝典");
    //xiaoyy->fight();
    //delete []xiaoyy;//仅打印Yuebuqun的fight 后面就不打印了 内存越界！！理解这里!question.md中有答案
    //delete xiaoyy;

    Linpingzhi *xiaopp = new Linpingzhi("僻邪剑谱");
    //xiaopp->fight();
    //delete xiaopp;

    fightPeople(xiaoyy);
    fightPeople(xiaopp);
    return 0;
}
