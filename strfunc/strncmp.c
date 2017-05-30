/*返回str1的ASCII减去str2的ASCII*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strncmp(char const *str1, char const *str2, int cnt){
	if(!cnt)//cnt == 0
		return 0;
	while(--cnt && *str1 == *str2){
		str1++;
		str2++;
	}
#if 0
	while(cnt && *str1 == *str2){
		cnt--;
		str1++;
		str2++;
	}//这个注释是错误的，多执行了一次循环 需要注意cnt--不能放入到循环中，从cnt到0的话会多1次循环

例如：
	int i = 5;
	int k = 1;
	while(i--){k++}; //k = 1 + 5 = 6;

	i = 5;
	k = 1;
	while(i){i--; k++} //k = 1 + 6 = 7;
#endif
	return (*str1 - *str2);
}

int main(){
	char *str1 = "abcdefg";
	char *str2 = "123456";
	char *str3 = "abce";
	int ret1 = my_strncmp(str1, str2, 3);//'a'-'1' 97-49 = 48
	int ret2 = my_strncmp(str1, str3, 4);//'d'-'e' = -1

	int ret3 = strncmp(str1, str2, 3);
	int ret4 = strncmp(str1, str3, 4);

	printf("ret1:%d\tret2:%d\tret3:%d\tret4:%d\n", ret1, ret2, ret3, ret4);//48 -1 48 -1
	return 0;
}
