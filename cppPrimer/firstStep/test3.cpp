/*************************************************************************
	> File Name: test3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年02月20日 星期三 17时04分20秒
 ************************************************************************/

#include<iostream>
using namespace std;

class MyArray{
    //遍历整个数组 不使用for循环+getData的方法 重新定义cout重载
    friend ostream &operator<<(ostream &output, const MyArray &another);
public:
    MyArray(int len);
    MyArray(const MyArray &another);
    MyArray &operator=(const MyArray &another);

    //用于将obj.setData(index, data) 变为space[index]，对[]重载
    //space[i] 为int类型 所以返回int&
    int &operator[](int index) const;
    ~MyArray();

    void setData(int index, int data);
    int getData(int index) const;
    int getLen() const;
private:
    int len;
    int *space;
};

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
    //防治自身附值
    if(this == &another)
        return;
    //无须像=操作符重载那样的第二步，因为拷贝构造发生在最开始，space == NULL
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
MyArray &MyArray::operator=(const MyArray &another){
    //1.防止自身附值
    if(this == &another)
        return *this;

    //2.先将自身的额外开辟的空间回收掉
    if(this->space != NULL){
        this->len = 0;
        delete []this->space;
        this->space = NULL;
    }

    //3.执行深拷贝
    if(another.len >= 0){
        this->len = another.len;
        this->space = new int[this->len];
        for(int i = 0; i < this->len; i++){
            this->space[i] = another.space[i];
        }
    }
    return *this;
}
#if 0 //用operator[]代替
void MyArray::setData(int index, int data){
    if(this->space == NULL){
        cout << "未分配内存" << endl;
        return;
    }
    this->space[index] = data;
    return;
}
#endif
int MyArray::getData(int index) const{
    if(this->space != NULL)
        return this->space[index];
    else
        return false;
}
int MyArray::getLen() const{
    return this->len;
}
int &MyArray::operator[](int index) const{
    return this->space[index];
}
ostream &operator<<(ostream &output,const MyArray &another){
    for(int i = 0; i < another.getLen(); i++)
        output << another[i] << " ";
    //another类为const 则[]重载函数后也为const；这里重载的another[i]省去了another.getData[i]这样的方法
    //[]重载隐式传递了this指针所指的对象 即<<重载传递的const类型的another 因为this所指const 所以限定this为const
    //因此operator[]重载时函数后面有const
    return output;
}


int main(){
    MyArray arr1(10);
    //arr1.setData(3, 5);
    //通过[]重载 this->space[1] = 3;
    arr1[3] = 3;

    //调用拷贝构造函数
    //MyArray arr2 = arr1;
    
    //先调用参数构造函数 再调用arr2.operator=(arr1);等号操作符重载
    MyArray arr2(1);
    //虽然arr1长度为10 arr2长度为1 但是=重载函数中释放了1内存又重新分配了10内存 然后进行深拷贝
    arr2 = arr1;
    cout << arr1 << endl;
    cout << arr2 << endl;

#if 0 //默认的operator=等号重载时指针悬挂造成内存重复释放
    //所以我重写了一个=重载函数
    //void operator=(const MyArray &another);
    MyArray arr2;
    arr2 = arr1;
    cout << "arr1: ";
    for(int i = 0; i < 10; i++){
        cout << arr1.getData(i) << " ";
    }
    cout << endl << "arr2: ";
    for(int i = 0; i < 10; i++){
        cout << arr2.getData(i) << " ";
    }
    cout << endl;
#endif 
    return 0;
}
