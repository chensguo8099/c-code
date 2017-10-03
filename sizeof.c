#include <stdio.h>

int main(){
	int tag = 10;
	printf("%d\n", sizeof(tag++));
	printf("%d\n", tag);
	printf("%d\n", sizeof(1.1));
	printf("%d\n", sizeof('a'));
	printf("%d\n", sizeof("a"));
	printf("%d\n", sizeof(float));
	char *p = "a";
	printf("%d\n", sizeof(*p));
	return 0;
}
