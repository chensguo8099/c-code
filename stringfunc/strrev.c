/*strrev函数实现字符串反转，strrev函数不是C标准库函数，很多C编译器并没有提供支持*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *my_strrev(char *str){
	if(str == NULL)
		return NULL;
	char *end = str + strlen(str) - 1;
	char temp = '0';
	while(str < end){
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
	return str;
}

int main(){
	char str[] = "abc def";
	printf("%s\n", str);
	char *ret1 = my_strrev(str);
	printf("%s\n", str);
	return 0;
}
