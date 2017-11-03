/*************************************************************************
	> File Name: typedef.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 31 Oct 2017 06:18:10 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAXSIZE 50

typedef int exam_score;
typedef double salary;
typedef salary wages;
//salary wages均为工资的意思

#if 0 
//复杂类型typedef

typedef int KeyType;
typedef double ValueType;
typedef struct {
    KeyType key;
    ValueType value;
} DataType;

typedef struct {
    DataType data[MAXSIZE];
    int length;
}SqList;
#endif

int main(){
    int a;
    exam_score b;
    //a和b一看b就知道是考试分数，而a若要表示考试分数则不是那么直观

    double k;
    salary m;
    wages hourly, weekly;//时薪 周薪等等

    hourly = 50.00;
    weekly = 800.00;

    cout << weekly << endl;
    return 0;
}

#if 0
typedef作用
1. 可以将原有复杂类型或名字隐藏起来转换成简单可理解的名字
2. 简化复杂类型的定义，使其更容易理解
3. 允许一种类型用于多个目的，同时使得每次用该类型的时候目的明了
#endif
