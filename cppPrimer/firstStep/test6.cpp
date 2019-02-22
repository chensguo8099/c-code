/*
    > File Name: test6.cpp
    > Author: JerryChen
    > Created Time: 2019年02月22日 星期五 11时35分34秒
*/
//简单实现string类
#include <iostream>
#include <cstring>
using namespace std;

//string类的重载
//重载[] + << >> = == !=
class MyString{
public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &another);

    char &operator[](const int index);
    MyString operator+(const MyString &another);
    MyString &operator=(const MyString &another);
    bool operator==(const MyString &another);
    bool operator!=(const MyString &another);
    friend ostream &operator<<(ostream &os, const MyString &ostring);
    friend istream &operator>>(istream &is, MyString &istring);

    ~MyString();
private:
    int len;
    char *str;
};
MyString::MyString(){
    this->len = 0;
    this->str = NULL;

}
MyString::MyString(const char *str){
    if(str == NULL){
        this->len = 0;
        this->str = new char[0 + 1];
        strcpy(this->str, "");
    }
    else{
        this->len = strlen(str);
        this->str = new char[this->len + 1];
        strcpy(this->str, str);
    }
}

MyString::MyString(const MyString &another){
    this->len = another.len;
    this->str = new char[this->len+1];
    strcpy(this->str, another.str);
}

MyString &MyString::operator=(const MyString &another){
    if(this == &another)
        return *this;
    if(this->str != NULL){
        this->len = 0;
        delete []this->str;
        this->str = NULL;
    }
    this->len = another.len;
    this->str = new char[this->len + 1];
    strcpy(this->str, another.str);
    return *this;
}

/*[]只能作为成员函数重载*/
char &MyString::operator[](const int index){
    return this->str[index];
}
MyString MyString::operator+(const MyString &another){
    MyString tmp;
    tmp.len = this->len + another.len;
    tmp.str = new char[tmp.len];
    strcpy(tmp.str, this->str);
    strcat(tmp.str, another.str);
    return tmp;
}
ostream &operator<<(ostream &os, const MyString &ostring){
    os << ostring.str;
    return os;
}
istream &operator>>(istream &is, MyString &istring){
    //1.将istring之前的字符串释放掉
    if(istring.str != NULL){
        istring.len  = 0;
        delete []istring.str;
        istring.str = NULL;
    }
    //2.通过cin添加新的字符串
    char tmp[4096] = {0};
    is >> tmp;//如果str为NULL就无法输入 因此内部申请了4096字节的tmp临时空间
    istring.str = new char[strlen(tmp)];
    strcpy(istring.str, tmp);
    istring.len = strlen(tmp);
    return is;
}

MyString::~MyString(){
    if(this->str != NULL){
        cout << "~MyString()...." << endl;
        delete this->str;
        this->str = NULL;
        this->len = 0;
    }
}


int main(){
    MyString s1("abc");
    MyString s2(s1);
    cout << s1 << endl;
    cout << s2 << endl;
    s2[1] = 'y';
    cout << s2 << endl;
    s1 = s2;
    cout << s1 << endl;
    cout << s1 + s2 << endl;
    s1 = s1 + s2;
    cout << s1 << endl;
    return 0;
}
