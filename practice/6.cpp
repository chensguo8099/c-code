/*大整数排序*/
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
	char buf[1000];

	strcpy(buf, a);
	strcpy(a, b);
	strcpy(b, buf);//字符串交换
}

int main(){
	char arr[100][1000];
	int N = 0;
	memset(arr, '0', sizeof(arr));

	while(scanf("%d", &N) != EOF){
		for(int i = 0; i < N; i++)
			scanf("%s", arr[i]);

		for(int j = 0; j < N; j++){
			for(int k = j + 1; k < N; k++){
				if(strlen(arr[j]) > strlen(arr[k]))
					swap(arr[j], arr[k]);//按长度排列

				else if(strlen(arr[j]) == strlen(arr[k]) && strcmp(arr[j], arr[k]) > 0){
					swap(arr[j], arr[k]);//按ASCII前后顺序排列
				}
			}
		}


		for(int h = 0; h < N; h++)
			printf("%s\n", arr[h]);
	}
	return 0;
}
