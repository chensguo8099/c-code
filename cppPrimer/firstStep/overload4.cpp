/*************************************************************************
	> File Name: overload4.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Dec 2017 05:58:43 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

class Account{
public:
    Account(){};
    Account(int x):num(x){}   
public:
    int num;
};

enum Tokens{
    INLINE = 128,
    VIRTUAL = 129
};

void lookup(Account& x){cout << "lookup(Account& x)" << endl;}
void lookup(const Account& y){cout << "lookup(const Account&y)" << endl;}

//error 28行和29行是重复声明 并不是重载
//void f(int* const p){cout << "f(int* const p)" << endl;}
void f(int *p){cout << "f(int *p)" << endl;}
void f(const int *p){cout << "f(const int *p)" << endl;}

void newf(unsigned char x){cout << "newf(unsigned char x)" << endl;}
void newf(int y){cout << "newf(int y)" << endl;}

void ff(Tokens t){cout << "ff(Tokens t)" << endl;}
void ff(int x){cout << "ff(int x)" << endl;}
void ff(short y){cout << "ff(short y)" << endl;}

void manip(double x){cout << "manip(double)" << endl;}
void manip(float y){cout << "manip(float)" << endl;}

int main(){
    int m = 5, n = 6;
    int *p = &m;
    const int *p2 = &n;
    f(p);//f(int *p);
    f(p2);//f(const int *p);

    const Account a(0);
    Account b;
    lookup(a);//lookup(const Account& y);
    lookup(b);//lookup(Account& x);

    Tokens curTok = INLINE;
    ff(curTok);//ff(Tokens t);
    ff(INLINE);//ff(Tokens t);

    unsigned char uc = 129;
    newf(VIRTUAL);//new(int y);
    newf(uc);//newf(unsigned char x);

    ff(128);//ff(int x),不是枚举类型
    ff('a');//ff(int x);类型提升的时候int版本级别优先与short，所以先转为int
    manip(3.1);

    return 0;
}
