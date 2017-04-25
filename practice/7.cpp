#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, i, j;
	int arr[105];
	while(scanf("%d", &n) != EOF){
		for(i = 0; i < n; i++)
			scanf("%ld", &arr[i]);
		sort(arr, arr + n);
		for(j = 0; j < n; j++)
			printf("%d ", arr[j]);
		printf("\n");
	}
	return 0;
}
