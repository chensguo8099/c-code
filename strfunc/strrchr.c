/*从后往前找第一个字符c，找到了返回一个指向该位置的指针，否则返回NULL*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strrchr(char *str, char c){
	char *end = str + strlen(str);
	while(*end != *str && *end != c)
		end--;
	if(*end == *str && *end != c)
		return NULL;
	return end;
}


int main(){
	char *str = "abc123225";
	char *s1 = NULL;
	s1 = my_strrchr(str, '2');
	if(s1)
		printf("%s\n", s1);
	else
		printf("not found !\n");
	return 0;
}
