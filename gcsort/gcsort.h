#ifndef _GCSORT_H
#define	_GCSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM(x) (rand()%x+1)

typedef struct softarray{
	int len;
	int array[];
}SoftArray;//声明SoftArray

int compar_num(const void *, const void *);
void msort(SoftArray*, int, int (*)(const void *,const void*));

#endif
