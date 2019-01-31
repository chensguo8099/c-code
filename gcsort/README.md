Code Describe: 

gcsort函数创建一个用户输入大小的动态的数组，为此数组产生一个用户自己给定的有随机数大小上限的数，然后自动排序输出，不足点在于虽然运用了回调函数，但没有实现像qsort这样的通用排序函数,使用了测试框架googletest，运用了googletest的断言中基本的宏对gcsort进行测试。

Makefile代码运行,命令如下：
```c
make 
./test 查看测试情况
make clean清楚残余.o文件
```
