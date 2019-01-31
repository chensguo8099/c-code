/*************************************************************************
	> File Name: trycatch.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 26 Nov 2017 05:53:53 AM PST
 ************************************************************************/
#include <cstdio>
#include<iostream>
using namespace std;

//传统C的异常检错方法（return 配合 switch语句）
//copy函数
int my_cp(const char *src_file, const char *dest_file){
    FILE *in_file, *out_file;

    in_file = fopen(src_file, "rb");//rb 二进制读 read binary
    if(in_file == NULL){
        return 1;
    }
    out_file = fopen(dest_file, "wb");//wb 二进制写
    if(out_file == NULL){
        return 2;
    }
    char rec[256];
    size_t bytes_in, bytes_out;//记录实际读写的字节数
    while((bytes_in = fread(rec, 1, 256, in_file)) > 0 ){//返回size_t，将要读256字节，每次读1字节，返回值为实际读的字节数
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if(bytes_in != bytes_out){
            return 3;
        }
    }
    fclose(in_file);
    fclose(out_file);
    return 0;
}

int main(){
    int result;
    if((result = my_cp("filetest1", "filetest2")) != 0){
        switch(result){
            case 1:printf("打开源文件时出错！\n");break;
            case 2:printf("打开目标文件出错！\n");break;
            case 3:printf("拷贝文件时出错！\n");break;
            default:printf("发生未知错误！\n");break;
        }
    }
    return 0;
}
