/*************************************************************************
 读入一段文本到vector对象，每个单词存储为vector中的一个元素，把vector对象中
 的每个单词转换为大写字母，输出vector对象中转化后的元素，每8个单词为1行输出
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str;
    vector<string> svec;

    cout << "Enter text(Ctrl+d to end):" << endl;
    while(cin >> str){
        svec.push_back(str);
    }

    if(svec.size() == 0){
        cout << "No string?!" << endl;
        return -1;
    }

    cout << "Transformed elements from the vector:" << endl;

    for(vector<string>::size_type i=0; i!=svec.size(); ++i){
        for(string::size_type index=0; index != svec[i].size(); ++index){
            if(islower(svec[i][index]))
                svec[i][index] = toupper(svec[i][index]);
        }
        cout << svec[i] << " ";
        if((i+1) % 8 == 0){
            cout << endl;
        }
    }
    return 0;
}
