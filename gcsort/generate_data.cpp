#include "gcsort.h"
#include "generate_data.h"

SoftArray* generate_data(int arrsize, int top_max){
	if(arrsize < 0 || top_max < 0){
		printf("error ! size < 0 !\n");
		return 0;
	}
	int cnt = 0;
	srand(time(NULL));
	SoftArray *tmp = (SoftArray*)malloc(sizeof(SoftArray) + sizeof(int)*arrsize);
	tmp->len = arrsize;
	for(cnt = 0; cnt < arrsize; cnt++)
		tmp->array[cnt] = RANDOM(top_max);
	return tmp;
}

