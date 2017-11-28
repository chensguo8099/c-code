/*************************************************************************
	> File Name: trycatch.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2017 05:53:53 AM PST
 ************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;

//copy函数
void my_cp2(const char *src_file, const char *dest_file){
    FILE *in_file, *out_file;

    in_file = fopen(src_file, "rb");//rb 二进制读 read binary
    if(in_file == NULL){
        //return 1;
        throw 1;//throw就是抛出异常
        //异常类型可以为：数字/字符串/类对象
    }
    out_file = fopen(dest_file, "wb");//wb 二进制写
    if(out_file == NULL){
        //return 2;
        throw 2;
    }
    char rec[256];
    size_t bytes_in, bytes_out;//记录实际读写的字节数
    while((bytes_in = fread(rec, 1, 256, in_file)) > 0 ){//返回size_t，将要读256字节，每次读1字节，返回值为实际读的字节数
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if(bytes_in != bytes_out){
            //return 3;
            throw 3;
        }
    }
    fclose(in_file);
    fclose(out_file);
}

int main(){
    try{//有可能出错的代码就放在try里，发生异常则跳入catch
        my_cp2("filetest1", "filetest2");
    }
    catch(int e){//变量e存放的就是throw抛出的值
        printf("发生异常%d\n", e);
    }
    return 0;
}
