#include <stdio.h>

int main(){
	int i = 5, j = 5;
	while(i--){}
	while(j){j--;}
	printf("i:%d j:%d\n", i, j);//两者写法的区别

	int k = 10;
	char a = '\0';
	while(a)
		k--;
	printf("%d\n", k);//当while条件中是\0时也会终止循环
	return 0;
}
