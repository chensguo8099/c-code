/*在str中找字符c，找到了返回指向该位置的指针，否则返回NULL*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strchr(char *str, char c){
	while(*str != '\0' && *str != c)
		str++;
	return (*str == c ? str : NULL);
}

int main(){
	char *str = "woshiguochen123";
	char srch1 = 'e';
	char srch2 = '2';

	char *s1 = NULL;
	char *s2 = NULL;
	char *s3 = NULL;
	s1 = my_strchr(str, srch1);
	s2 = strchr(str, srch2);
	printf("find :\ns1:%c\ts2:%c\n", *s1, *s2);

	s3 = my_strchr(str, 'a');
	if(s3)
		printf("find :\ns3:%c\n", *s3);
	else
		printf("not found !\n");//strchr返回NULL则未找到
	return 0;
}
