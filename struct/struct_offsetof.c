#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s1mple {
	char female;
	int reason;
	char male;
}bad;

#if 0
offsetof( type, member );

type就是结构体类型，member就是你需要的那个成员名
返回值是当前member之前已经偏移了多少字节
#endif 

int main(){
	printf("return of offsetof:%d\n", offsetof(bad, female));//0
	printf("return of offsetof:%d\n", offsetof(bad, reason));//4
	printf("return of offsetof:%d\n", offsetof(bad, male));//8
	return 0;
}
