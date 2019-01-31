/*阶乘*/
#include <stdio.h>
#include <iostream>
int func(int n){
	if(n == 1)
		return 1;
	else
		return n * func(n-1);
}

int main(){
	int n;
	int sum1 = 0, sum2 = 0;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i = i + 2)
			sum1 += func(i);
		for(int j = 2; j <= n; j = j + 2)
			sum2 += func(j);
		printf("%d %d\n", sum1, sum2);
		sum1 = 0, sum2 = 0;
	}
	return 0;
}
