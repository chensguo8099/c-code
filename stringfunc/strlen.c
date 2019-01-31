/*返回字符串长度*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int my_strlen(char const *src){
	unsigned int length;
	while(*src != '\0'){
		length++;
		src++;	//src指向字符串的末位,即'\0'
	}
#if 0
	while(*src++ != '\0')
		length++;	//不用这种方式是因为src最后指向字符串最后一位'\0'的下一位
#endif
	return length;
}

int main(){
	char src[10] = "abcdef";
	unsigned int len1 = my_strlen(src);
	unsigned int len2 = strlen(src);
	printf("my_strlen : %d\tstrlen : %d\n", len1, len2);
	return 0;
}
