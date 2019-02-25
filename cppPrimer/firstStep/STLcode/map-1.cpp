/*
    > File Name: map-1.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 23时45分34秒
*/

#include <iostream>
#include <map>
using namespace std;

void test(){
    //map容器模板参数，第一个参数key的类型，第二个参数value的类型
    map<int, int> mymap;
    //第一种
    pair<map<int, int>::iterator, bool> ret = mymap.insert(pair<int, int>(10, 10));
    if(ret.second){
        cout << "第一次插入成功" << endl;
    }else{
        cout <<"插入失败" << endl;
    }
    
    ret = mymap.insert(pair<int, int>(10, 20));
    if(ret.second){
        cout << "第二次插入成功" << endl;
    }else{
        cout <<"插入失败" << endl;//第二次插入失败 因为map要求key不同
    }

    //第二种
    mymap.insert(make_pair(20, 20));
    //第三种
    mymap.insert(map<int, int>::value_type(30, 30));
    //第四种
    mymap[40] = 40;
    mymap[10] = 20;
    //发现key不存在则创建pair插入到map容器中
    //发现key存在则修改对应value
    cout << mymap[70] << endl;
    //如果通过[]访问map中不存在的key，map会将这个访问插入到map中，并给其一默认value 一般为0


    //打印
    for(map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
    //*it取出来的是一个pair
        cout << (*it).first << " " << (*it).second << endl;
        //cout << it->first << " " << it->second << endl;
    }
}


class MyKey{
public:
    MyKey(int index, int id):mIndex(index), mId(id){}
public:
    int mIndex;
    int mId;
};


//map排序规则
struct compare{
    bool operator()(MyKey a1, MyKey a2){
        return a1.mIndex > a2.mIndex;
    }
};


void test2(){
    map<MyKey, int, compare> mymap;
    mymap.insert(make_pair(MyKey(1, 2), 10));
    mymap.insert(make_pair(MyKey(4, 5), 20));
    for(map<MyKey, int, compare>::iterator it = mymap.begin(); it != mymap.end(); it++){
        cout << (*it).first.mIndex << endl;
    }
}

//equal_range
void test3(){
    map<int, int> mymap;
    mymap.insert(make_pair(1, 1));
    mymap.insert(make_pair(2, 2));
    mymap.insert(make_pair(3, 3));

    pair<map<int, int>::iterator, map<int, int>::iterator> ret = mymap.equal_range(2);
    if(ret.first->second){
        cout << "找到" << endl;
    }else{
        cout << "未找到" << endl;
    }
    if(ret.second->second){
        cout << "找到" << endl;
    }else{
        cout << "未找到" << endl;
    }
}

int main(){
    test3();
    return 0;
}
