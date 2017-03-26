#include <stdio.h>

int main(){
	char a = 'a';
	int *b = ((int*)&a);
	printf("%d\n", *b);
	return 0;
}
