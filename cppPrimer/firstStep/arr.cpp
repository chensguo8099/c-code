/*************************************************************************
	> File Name: arr.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Nov 2017 06:49:23 AM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int mia[3];//若未初始化，全局数组会被自动初始化为0，但函数内部不会自动初始化

unsigned get_size(){
    int a = 100;
    int b = 200;
    return a + b;
}

int main(){
    int a[100];

    const unsigned buf_size = 512, max_files = 20;
    int staff_size = 27;

    const unsigned sz = get_size();

    char input_buffer[buf_size];
    string fileTable[max_files + 1];
    //如果能在编译的时候确定一个数 则为常量表达式
    //double salaries[staff_size];staff_size不是常量 无法声明
    //int test_scores[get_size()];无法声明
    //int vals[sz];无法声明虽然sz是const常量，但是在编译的时候函数还没有返回值
    
    const unsigned array_size = 3;
    int ia[array_size] = {12, 9, 37};
    int ia2[] = {12, 9, 37};
    //int ib[3] = {1, 2, 3, 4, 5};
    int ic[5] = {1, 2, 3};
    //使用一个数组之前必须先初始化
    cout << ia[0] << "," << ia[1] << "," << ia[2] << endl;
    cout << ic[2] << "," << ic[3] << "," << ic[4] << endl;

    string str_arr[5] = {"hi", "bye"};

    char ca1[] = {'C', '+', '+'};//字符数组
    char ca2[] = {'C', '+', '+', '\0'};//字符串
    char ca3[] = "C++";//末尾有\0

    //const char ca4[6] = "Daniel"; 末尾\0存不下去 报错

    cout << "OK!" << endl;
    return 0;
}
