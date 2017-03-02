#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 5;
	int *p = &a;
	p = malloc(0);
	printf("address : %0x\n data : %d\n", p, *p);
	return 0;
}
