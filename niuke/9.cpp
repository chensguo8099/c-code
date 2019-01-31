/*A + B*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int func(string str){
	int tmp = 0;
	for(int i = 0; i < str.length(); ++i){
		if(str[i] == ',' || str[i] == '-')
			continue;
		else
			tmp = tmp * 10 + (str[i] - '0'); 
	}
	if(str[0] != '-')
		return tmp;
	else
		return -tmp;
}

int main(){
	string str1;
	string str2;
	int tmp1, tmp2;
	while(cin >> str1 >> str2){
		tmp1 = func(str1);
		tmp2 = func(str2);
		cout << tmp1 + tmp2 << endl;
	}
	return 0;
}
