#include <stdio.h>
union A{
	int f1;
	float f2;
	int f3;
	char a[9];
};


int main(){
	union A a1;
	a1.f3 = 5;

	printf("%d\n", sizeof(a1));
	printf("%d\n", a1.f1);
	return 0;
}
