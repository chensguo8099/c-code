/*斐波那切递推*/
#include <stdio.h>

int main(){
	int N, i;
	int arr[100];
	while(scanf("%d", &N) != EOF){
		arr[1] = 1, arr[2] = 2;
		for(i = 3; i <= N; i++)
			arr[i] = arr[i - 1] + arr[i - 2];
		printf("%d\n", arr[N]);
	}
	return 0;
}
