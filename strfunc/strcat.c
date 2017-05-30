/*字符串拼接函数，将str2的内容写到str1函数后,返回一个指向str1首地址的指针*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *str1, char const*str2){
	char *save = str1;
	while(*str1)
		++str1;
	while((*str1++ = *str2++));
	return save;
}//把str2接到str1后面

int main(){
	char a[10] = "abc";
	char *b = "def";
	char c[10] = "123";
	char *str1 = my_strcat(a, b);
	char *str2 = strcat(c, b);
	printf("%s\n%s\n", str1, str2);
	return 0;
}
