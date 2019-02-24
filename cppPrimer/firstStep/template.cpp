/*
    > File Name: template.cpp
    > Author: JerryChen
    > Created Time: 2019年02月24日 星期日 10时42分52秒
*/

#include <iostream>
using namespace std;

template<class T>class Obj;
//之所以给operator声明模板是因为该友元不属于模板类Obj，需但另声明
template<class T>ostream &operator<<(ostream &os, Obj<T> &another);

template<class T>
class Obj{
public:
    Obj(T sign){
        this->sign = sign;
    }
    void print();
    friend ostream &operator<<<T>(ostream &os, Obj<T> &another);
    T sign;
};

template<class T>
void Obj<T>::print(){
    cout << sign << endl;
}

template<class T>
ostream &operator<<(ostream &os, Obj<T> &another){
    os << another.sign << endl;
    return os;
}

int main(){
    Obj<char> a1('a');
    Obj<char> a2('b');
    cout << a1;
    cout << a2;
    a1.print();
    a2.print();
    return 0;
}
