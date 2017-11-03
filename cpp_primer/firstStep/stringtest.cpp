#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

int main(){
	char a[10] = "abcd";
	std::string b("abcdefghi");

	printf("%d\n", sizeof(a));
	std::cout << sizeof(a) << std::endl;//计算字符串长度，末尾有'\0'

	printf("%d\n", sizeof(b));//sizeof(b)计算的是字符串指针大小
	std::cout << b.size() << std::endl;//计算字符串长度，末尾无'\0'
	std::cout << b.length() << std::endl;
/*
 *size_type __CLR_OR_THIS_CALL length() const
 *{// return length of sequence
 *		return (_Mysize);
 *}
 *
 *size_type __CLR_OR_THIS_CALL size() const
 *{// return length of sequence
 *		return (_Mysize);
 *}
 *size()和length()没区别
 *
 *string类最初只有length,引入STL后,为了兼容加入了size(),为STL容器的属性而存在,便于符合STL接口规则
 */
	std::string c(b);
	std::cout << c << std::endl;//字符串拷贝
	return 0;
}
