#include <stdio.h>

#pragma pack(2)

struct test{
	char a;
	int  b;
	char c;
	char *d;
	short e;
	long long f;
};

int main(){
	struct test d1;
	printf("%d\n", sizeof(d1));
	return 0;
}
