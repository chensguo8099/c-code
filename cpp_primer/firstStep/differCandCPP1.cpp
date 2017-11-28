/*************************************************************************
	> File Name: differCandCPP1.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Nov 2017 07:15:42 AM PST
 ************************************************************************/
//读入一组string类型的数据，把这些string都保存在vector中，然后把vector中的字符串复制给字符指针数组 
#include<iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main(){
    vector<string> svec;
    string str;
    cout << "Enter strings:(ctrl+d to end):" << endl;
    while(cin >> str){
        svec.push_back(str);
    }
    char **parr = new char*[svec.size()];

    size_t ix = 0;
    for(vector<string>::iterator iter=svec.begin(); iter!=svec.end(); ++iter){
        char *p = new char[(*iter).size() + 1];
        strcpy(p, (*iter).c_str());
        parr[ix] = p;
    }

    cout << "Content of vector:" << endl;
    for(vector<string>::iterator iter=svec.begin(); iter!=svec.end(); ++iter){
        cout << *iter << endl;
    }
    return 0;
}
