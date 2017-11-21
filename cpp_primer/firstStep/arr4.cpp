/*************************************************************************
	> File Name: arr4.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2017 05:45:22 AM PST
 ************************************************************************/

#include<iostream>
#include <cstring>
using namespace std;

class Dog{


};

int main(){
    int *pia = new int[10];//没有初始化
    string *psa = new string[10];//默认构造函数进行初始化

    Dog *pDog = new Dog[10];

    int *pia2 = new int[10]();//内置类型的默认值进行初始化（不能用初始化列表初始化），全为0

    cout << *(pia2 + 2) << endl;//0

    *pia = 9;
    *(pia + 1) = 8;
    *(pia2 + 3) = 6;

    cout << *(pia + 1) << endl;
    cout << *(pia2 + 3) << endl;


    for(int *q = pia; q != pia + 10; ++q){
        *q = 11;
    }
    for(int *q = pia; q != pia + 10; ++q){
        cout << *q << endl;
    }


    //创建const对象的动态数组
    const int *pci_bad = new const int[100]();//创建后初始化后无法修改，全是0

    const int *pci_bad2 = new int [50]();

    //char arr[0];//静态创建数组大小为0是错误的写法
    char *cp = new char[0];//动态创建的数组可以允许大小为0

    cout << "请输入动态数组的大小：" << endl;
    size_t n;
    cin >> n;//n可以为0
    int *p = new int[n];

    delete[] p;


    //C
    const char *pc = "a string";
    const size_t len = strlen(pc);

    for(size_t ix=0; ix!=100; ++ix){
        char *pc2 = new char[len+1];
        strcpy(pc2, pc);
        cout << pc2 << endl;
        delete[] pc2;
    }

    //C++
    string str("a string");
    for(int ix = 0; ix!=100; ++ix){
        string str2 = str;
        cout << "C++:" << str2 << endl;
    }//很明显C++的方式要比C简单

    return 0;
}
