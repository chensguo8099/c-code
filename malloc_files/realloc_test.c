#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 3

int main(){
	int *p1 = NULL;
	int *p2 = NULL;
	int i = 0, j = 0;

	p1 = malloc(5*sizeof(int));
	memset(p1, 0, sizeof(int));

	for(i = 0; i < 5; i++)
		*(p1 + i) = i;

	for(i = 0; i < 5; i++)
		printf("%d ", *(p1 + i));

	printf("\nEND OF p1\n");


	p2 = realloc(p1, NUM * sizeof(int));//free p1

	for(j = 0; j < NUM; j++)
		printf("%d ", *(p1 + j));//print p2

	printf("\n%d", *(p1+1));//??
	return 0;
}
