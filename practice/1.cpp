#include <stdio.h>

int main(){
	int N, j, t;
	int data[10];
	while(scanf("%d", &N) != EOF){
		int i = 0;
		while(N != 0){
			t = N%8;
			N /= 8;
			data[i++] = t;
		}
		for(int j = i - 1; j >= 0; j--)
			printf("%d", data[j]);
		printf("\n");
	}
	return 0;
}
