#include <stdio.h>
#include <stdlib.h>

#if 0
typedef struct array{
	int len;
	int array[]
}
#endif

int main(){
	int *p = NULL;
	int i = 0;
	p = (int *)calloc(4, sizeof(int));		
	for(i = 0; i < 4; i++){
		printf("%d\n", *p);
		p = p + 1;
	}
	return 0;
}
