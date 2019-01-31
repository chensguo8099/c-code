/*返回目地字符串的首地址*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *my_strncpy(char *dest, char const *src, int cnt){
	assert(dest != NULL);
	int i = 0;
	while(cnt && (*dest++ = *src++)){cnt--;}
    //while(cnt-- && (*dest++ = *src++)){i++;} //error segmentfault(core dumped)
	while(cnt--)
		*dest++ = '\0';
	return dest;
}

int main(){
//test1
	char dest[10] = "abc123456";
	char *src = "abc";
	my_strncpy(dest, src, 6);//src字符串中前6个字符拷贝到dest中
	printf("%s\n", dest);
//test2
	int j;
	for(j = 0; j < 10; j++)
		printf("%c", dest[j]);
	printf("\n");

//test3
	char dest1[15] = "abcdefghij";
	char *src1 = "1234";
	strncpy(dest1, src1, 6);
	int i;
	for(i = 0; i < 15; i++)
		printf("%c", dest1[i]);//输出1234ghij,dest1中的ef用两个\0填充了,dest[10] = "1234\0\0ghij\0"
	printf("\n");
	return 0;
}
