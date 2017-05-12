#include <iostream>

int main(){
	int ival(1024);//直接初始化
	int ival2 = 1024;//复制初始化
	//int month;
	//std::cout << month << std::endl;//未初始化Liunx下输出为0 建议不要这样写
	std::cout << ival << std::endl;//C++中推荐初始化方法为直接初始化
	std::cout << ival2 << std::endl;

	std::string titleA = "C++ Primer, abc";
	std::string titleB("C++ Primer, abc");//两者初始化效果相同

	std::string all_nines(10, '9');//给10个数赋值为9
	std::string gc_convert(5, 'f');
//(std::string) (int, char);

	std::cout << all_nines << std::endl;
	std::cout << gc_convert << std::endl;

	return 0;
}
