/*将str拷贝一份至新的内存空间，并且返回指向新内存空间的首地址*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *my_strdup(const char *str){
	char *temp = (char *)malloc(strlen(str) + 1);
	assert(str != NULL && temp != NULL);
	strcpy(temp, str);
	return temp;
}

int main(){
	char *arr = "abcdefg";
	char *cpyarr = NULL;
	cpyarr = my_strdup(arr);
	printf("%s\n", cpyarr);
	return 0;
}
