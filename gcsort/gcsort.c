#include "gcsort.h"
#include "generate_data.h"

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
