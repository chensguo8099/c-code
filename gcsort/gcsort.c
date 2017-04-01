#include "gcsort.h"

SoftArray* generate_data(int arrsize, int top_max){
	int cnt = 0;
	srand(time(NULL));
	SoftArray *tmp = (SoftArray*)malloc(sizeof(SoftArray) + sizeof(int)*arrsize);
	tmp->len = arrsize;
	for(cnt = 0; cnt < arrsize; cnt++)
		tmp->array[cnt] = RANDOM(top_max);
	return tmp;
}

int compar_num(const void *p1,const void *p2){
		return *(int*)p1 > *(int*)p2 ? 1 : -1;
}

void msort(SoftArray *arr, int max, int (*compare)(const void *p1,const void *p2)){
	int tmp = 0, result = 0;
	int numslow = 0, numquick = 0;
	for(numslow = 0; numslow < max; numslow++){
		for(numquick = numslow + 1; numquick < max; numquick++){
			result=compare(&(arr->array[numslow]), &(arr->array[numquick]));
			if(1 == result){
				tmp = arr->array[numslow];
				arr->array[numslow] = arr->array[numquick];
				arr->array[numquick] = tmp;
			}
		}
	}
}
