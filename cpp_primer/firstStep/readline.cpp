/*************************************************************************
	> File Name: readline.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 01 Nov 2017 07:07:26 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>

using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        cout << line << endl;
    }
    return 0;
}
