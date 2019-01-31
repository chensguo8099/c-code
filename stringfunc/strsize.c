#include <stdio.h>
#include <string.h>

int main(){
	char *p = "hello";
	char arr[10] = {"hello"};
	char arr2[10] = {'h', 'e', 'l', 'l', 'o'};
	char arr3[10] = {'h', 'e', 'l', '\0', 'l', 'o'};
	printf("strlen:%d sizeof:%d\n", strlen(arr3) ,sizeof(arr3));
	printf("strlen:%d sizeof:%d\n", strlen(arr2) ,sizeof(arr2));
	printf("strlen:%d sizeof:%d\n", strlen(arr) ,sizeof(arr));
	printf("strlen:%d sizeof:%d\n", strlen(p) ,sizeof(p));
	printf("strlen:%d sizeof:%d\n", strlen("hel\0lo"), sizeof("hel\0lo"));
	return 0;
}
