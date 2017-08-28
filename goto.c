#include <stdio.h>

int main(){
	int j = 0;
	int i = 0, a;
	for(i=0; i<2; i++)
	{
		again:
		scanf("%d", &a);
		j++;
		if(a == 2)
			goto again;
	}
	printf("%d\n", j);
	return 0;
}
