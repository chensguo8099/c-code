/*返回目的字符串的起始位置*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* my_strcpy(char *dest, char const *src){//把src拷贝到dest
	assert(dest != NULL && src != NULL);
	while(*dest++ = *src++);//while遇到'\0'时也会退出循环
// 	while(*dest++ = *src++){}	test ok
// 	while(*dest++ = *src++){;}	test ok
// 	while(*dest++ = *src++){};	test ok
	return dest;
}

int main(){
	char arr[10];
	char *dest1 = arr;
	char *src = "testsrc";
	char dest2[10];
//我的strcpy 指针偏移存放字符串
	my_strcpy(arr, src);
	int i;
	for(i = 0; i <= strlen(src); i++)
		printf("%c", dest1[i]);//"testsrc"
	printf("\n");

//我的strcpy 数组存放拷贝的字符串
	my_strcpy(dest2, src);
	printf("%s\n", dest2);//"testsrc"

//库函数用例1 dest > strtest
	char dest[10] = "abcdefgh";
	char *srctest = "1234";
	strcpy(dest, srctest);
	printf("%s\n", dest);//打印1234 不会像strncpy如果指定拷贝前4个而打印类似1234efgh这样的覆盖，如果是strcpy则1234和\0均被拷贝过去，及为1234\0fgh\0,所以打印到第一个\0即终止

//库函数用例2 dest3 < strtest3
	char dest3[5] = "abcd";
	char *srctest3 = "12345678";
	//strcpy(dest3, srctest3); "12345678"//当while循环至12345678\0时会退出循环，所以最终输出结果为12345678,其中12345在所申请的dest3[5]中存放，另外678三个数字则是紧跟该数组的三个连续内存地址，存放的三个值可能会被修改
	my_strcpy(dest3, srctest3);
	printf("%s\n", dest3);
	return 0;
}
