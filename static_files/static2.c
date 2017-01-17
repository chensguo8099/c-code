#include <stdio.h>

void func(){
	static i = 0;
	i++;
	printf("%d\n", i);
}

void func2(){
	int i = 0;
	i++;
	printf("%d\n", i);
}

int main(){
	int a = 0;
	for(a = 0; a < 5; a++){
		func();
	}
	for(a = 0; a < 5; a++){
		func2();
	}
	return 0;
}
