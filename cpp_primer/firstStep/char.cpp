#include <iostream>
using namespace std;

int main(){
	char c1;
	c1 = 'A';

	wchar_t c2;
	c2 = '中';

	unsigned char c3;
	c3 = 360;

	unsigned char c4;
	c4 = -5;

	cout << c1 << c2 << endl;
	cout << (int)c3 << endl;
	cout << (int)c4 << endl;
	return 0;
}
