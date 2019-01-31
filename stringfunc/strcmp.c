/*比较函数，返回str1的ASCII减去str2的ASCII*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int my_strcmp(char const *str1, char const *str2){
	while(*str1 == *str2 && *str1 != '\0'){	//strcmp函数是用str1的第i个与str2的第i个去比,所以只需判断str1 != '\0';即可
		str1++;
		str2++;
	}
	return (*str1 - *str2);	//对应ASCII码值的差
}

int main(){
	char str1[10] = "1bctesta";
	char str2[10] = "1134567";
	char *str3 = "1bctest";
	int ret1 = my_strcmp(str1, str3);
	int ret2 = my_strcmp(str2, str3);
	int ret3 = strcmp(str1, str3);
	int ret4 = strcmp(str2, str3);
	printf("ret1:%d\tret2:%d\n", ret1, ret2);
	printf("ret3:%d\tret4:%d\n", ret3, ret4);
	return 0;
}
