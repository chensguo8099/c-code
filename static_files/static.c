#include <stdio.h>

void func(){
	static int i = 0;
	i++;
	printf("%d\n", i);
}


int main(){
	int j = 0;
	static int i = 1;
	for(j = 0; j < 3; j++){
		func();
	}
	for(j = 0; j < 10; j++){
		printf("%d\n", i++);
	}
	return 0;
}
