/*************************************************************************
	> File Name: test3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月20日 星期三 17时04分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

class MyArray{
public:
    MyArray();
    MyArray(int len);
    MyArray(const MyArray &another);
    void operator=(const MyArray &another);
    ~MyArray();

    void setData(int index, int data);
    int getData(int index);
    int getLen();
private:
    int len;
    int *space;
};

MyArray::MyArray(){
    this->len = 0;
    this->space = NULL;
}
MyArray::MyArray(int len){
    if(len <= 0){
        this->len = 0;
        this->space = NULL;
        return;
    }
    this->space = new int[len];
    this->len = len;
}
MyArray::MyArray(const MyArray &another){
    //深拷贝 防止指针悬挂
    this->len = another.len;
    this->space = new int[len];
    for(int i = 0; i < len; i++){
        this->space[i] = another.space[i];
    }
}
MyArray::~MyArray(){
    this->len = 0;
    delete []this->space;
    this->space = NULL;
}
void MyArray::operator=(const MyArray &another){
    this->len = another.len;
    this->space = new int[this->len];
    for(int i = 0; i < this->len; i++){
        this->space[i] = another.space[i];
    }
}

void MyArray::setData(int index, int data){
    if(this->space == NULL){
        cout << "未分配内存" << endl;
        return;
    }
    this->space[index] = data;
    return;
}
int MyArray::getData(int index){
    if(this->space != NULL)
        return this->space[index];
    else
        return false;
}
int MyArray::getLen(){
    return this->len;
}
int main(){
    MyArray arr1(10);
    arr1.setData(3, 5);
    MyArray arr2 = arr1;
#if 0 //默认的operator=等号重载时指针悬挂造成内存重复释放
    //所以我重写了一个=重载函数
    //void operator=(const MyArray &another);
    MyArray arr2;
    arr2 = arr1;
#endif
    cout << "arr1: ";
    for(int i = 0; i < 10; i++){
        cout << arr1.getData(i) << " ";
    }
    cout << endl << "arr2: ";
    for(int i = 0; i < 10; i++){
        cout << arr2.getData(i) << " ";
    }
    cout << endl;
    return 0;
}
