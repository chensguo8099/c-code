/*不区分大小写的比较两个字符串*/
//返回值：str1的ASCII值减去str2的ASCII值
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>//strcasecmp
#include <ctype.h>


#if 1
int my_strcasecmp(const char *str1, const char *str2){
	const u_char *str_f = str1;
	const u_char *str_s = str2;
	while(tolower(*str_f) == tolower(*str_s)){
		if(*str_f++ == '\0')
			return 0;
		*str_s++;
	}
	return (tolower(*str_f) - tolower(*str_s));
}
#endif

int main(){
	char a[10] = "a cabc";
	char b[10] = "AbCABC";
	char c[10] = "ABCABC";//由b和c一起比较可知strings.h中的库函数strcasecmp是将字符串统一转换成小写进行比较
	int ret1 = __strcasecmp(a, b);//strcasecmp(a, b)
	int ret2 = my_strcasecmp(a, b);
	printf("ret1:%d\tret2:%d\n", ret1, ret2);
	return 0;
}
