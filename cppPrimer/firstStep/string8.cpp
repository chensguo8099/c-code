/*************************************************************************
 编写一个程序，从标准输入读取多个string对象，把他们连接起来存放到一个更大
 的string对象中，并输出连接后的stirng对象，接着改写程序，将连接后相邻string
 对象以空格隔开
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
    string str, result_str;

    //linux下直接ctrl+z无法显示打印结果，在VC++2008夏可以
    //linux下ctrl+d即可退出进程，相当于exit命令
    cout << "Enter strings(Ctrl+d to end):" << endl;
    while(cin >> str){
        if(result_str.empty()){
            result_str = str;
        }else{
            result_str += " " + str;
            //result_str = result_str + " " + str;//该语句与上语句一样
        }
    }
    cout << "最后的大字符串：" << endl
         << result_str << endl;
    return 0;
}
