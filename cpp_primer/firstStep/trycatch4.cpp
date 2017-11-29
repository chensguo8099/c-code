/*************************************************************************
	> File Name: trycatch4.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2017 07:20:55 AM PST
 ************************************************************************/

#include<iostream>
#include <new>
using namespace std;

class Dog{
    public:
    Dog(){
        parr = new int[1000000];//4MB
    }
    private:
    int *parr;
};

int main(){
    Dog *pDog;
    try{
        for(int i = 1; i < 10000000; i++){//40GB
            pDog = new Dog();
            cout << i << ":new Dog 成功" << endl;
        }
    }
    catch(bad_alloc err){//内存分配异常
        cout << "new Dog 失败：" << err.what() << endl;
    }
    return 0;
}
