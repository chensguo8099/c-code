#include <iostream>
using namespace std;
//64位机器测试结果
int main(){
	cout << sizeof(bool) << endl;//1
	cout << sizeof(char) << endl;//1
	cout << sizeof(wchar_t) << endl;//4
	cout << sizeof(short) << endl;//2
	cout << sizeof(int) << endl;//4
	cout << sizeof(long) << endl;//8
	cout << sizeof(long long) << endl;//8
	cout << sizeof(long double) << endl;//16
	return 0;
}
