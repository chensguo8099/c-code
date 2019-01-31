#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	short b[2];
}Ex2;

typedef struct EX {
	int	a;
	char b[3];
	Ex2	c;
	struct EX *d;
}Ex;

int main(){
	Ex x = {10, "Hi", {5, {-1, 25}}, 0};
	Ex *px = &x;

	printf("*px->c.b:%d\n", *px->c.b);
	printf("*(px->c.b+1):%d\n", *(px->c.b+1));
	return 0;
}
