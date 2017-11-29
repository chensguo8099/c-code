/*************************************************************************
	> File Name: trycatch6.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 04:29:51 PM PST
 ************************************************************************/

#include<iostream>
#include <stdexcept>
using namespace std;

class stu{
private:
    int stu_age;
public:
    stu(int age){
        if(age < 0 || age > 150){
            throw out_of_range("年龄不能小于0或大于150");
        }
        this->stu_age = age;
    }
};

int main(){
    try{
        //stu zhangfei(20);//学生没错
        stu zhangfei(200);//学生出错
        cout << "学生没错" << endl;
    }
    catch(out_of_range err){
        cout << "学生出错" << err.what() << endl;
    }
    return 0;
}
