/*************************************************************************
 读一组整数到vector对象，计算并输出每对相邻元素的和，如果读入元素个数为奇数
 ，则提示用户最后一个元素没有求和，并输出其值，然后修改程序，头尾元素两两配
 对，依次类推，并计算每对元素的和并输出
 ************************************************************************/

#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int ival;
    vector<int> ivec;

    cout << "Enter numbers(Ctrl+D to end)" << endl;

    while(cin >> ival){
        ivec.push_back(ival);
    }


    //1--开始计算相邻的两个数之和
    if(ivec.empty()){
        cout << "No element?!" << endl;
        return -1;
    }
/*
    cout << "Sum of each pair of adjacent element in the vector:"
        << endl;
    for(vector<int>::size_type i=0; i<ivec.size()-1; i+=2){
        cout << ivec[i] + ivec[i+1] << endl;
    }
    if(ivec.size() %2 != 0){
        cout << endl
            << "The last element is not been summed"
            << " and its value is "
            << ivec[ivec.size()-1] << endl;
    }
*/

    //2--计算头尾相加
    cout << "Sum of each pair of counterpart element in the vector:"
        << endl;

    //如果要输出格式为六个一行
    vector<int>::size_type cnt = 0;
    vector<int>::size_type first, last;
    for(first=0, last=ivec.size()-1; first < last; ++first, --last){
        cout << ivec[first] + ivec[last] << "\t";
        ++cnt;
        if(cnt % 6 == 0)
            cout << endl;
        else
            cout << endl;
    }

    if(first == last){
        cout << endl
            << "The center element is not been summed "
            << "and its value is "
            << ivec[first] << endl;
    }

    return 0;
}
