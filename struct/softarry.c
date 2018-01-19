#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

typedef int ElemType;
typedef struct softarray{
	ElemType len;
	ElemType array[];
}SoftArray; //init softarray

//create softarray
SoftArray* create_softarray(){
	SoftArray* tmp = (SoftArray*)malloc(sizeof(SoftArray) + sizeof(*(tmp->array))*NUM);
	memset(tmp, 0, sizeof(*(tmp->array)));
	tmp-> len = NUM;
	return tmp;
}

void print_softarray(SoftArray* tmp){
	int i = 0;
	for(i = 0; i < NUM; i++)
		printf("%d\n", *(tmp->array) + i);
}

//delete softarray
void delete_softarray(SoftArray* tmp){
	free(tmp);
}

int main(){
	SoftArray *SA = create_softarray();
	print_softarray(SA);
	delete_softarray(SA);
	return 0;
}
