/*
    > File Name: set-1.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 21时10分49秒
*/

#include <iostream>
#include <set>
using namespace std;

class compare{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    //仿函数自定义set/multiset内置的排序 默认有小到大 可由大到小
    //multiset<int> s;
    multiset<int, compare> s;//仿函数写法
    s.insert(10);
    s.insert(9);
    s.insert(8);
    s.insert(22);
    s.insert(13);
    s.insert(12);
    s.insert(3);
    for(multiset<int, compare>::iterator it = s.begin(); it != s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "---------" << endl;
    multiset<int>::iterator it1 = s.lower_bound(12);//第一个大于等于12的值
    multiset<int>::iterator it2 = s.upper_bound(12);//第一个大于12的值
    cout << "lower_bound" <<*it1 << endl;
    cout << "upper_bound" << *it2 << endl;

    //equal_range用法，返回两个迭代器 第一个为ret.first 第二个为ret.second
    //指向lower_bound返回的值和upper_bound返回的值
    pair<multiset<int>::iterator, multiset<int>::iterator> ret = s.equal_range(12);
    if(ret.first == s.end()){
        cout << "not found" << endl;
    }else{
        cout << "multiset :" << *(ret.first) << endl;
    }
    if(ret.second == s.end()){
        cout << "not found" << endl;
    }else{
        cout << "multiset :" << *(ret.second) << endl;
    }

    //pair组 构造方法
    pair<int, int> pair1(10, 100);
    cout << pair1.first << " " << pair1.second << endl;

    pair<int, string> pair2 = make_pair(666, "guochen");
    cout << pair2.first << " " << pair2.second << endl;

    return 0;
}
