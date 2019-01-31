#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p = (int *)malloc(4);
	printf("%p %d\n", &p, *p);
	*p = 10;
	printf("%p %d\n", &p, *p);
	free(p);
	printf("%p %d\n", &p, *p);
	return 0;
}
