/*
    > File Name: aaaa.cpp
    > Author: JerryChen
    > Created Time: 2019年02月24日 星期日 21时21分10秒
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
public:
    Person(int a):res(a){};
    int res;
};

void func(Person obj){
    cout << obj.res << endl;
}

void fun2(int obj){
    cout << obj << endl;
}

int main(){/*
    vector<Person> v;
    Person *p1 = new Person(10);
    Person *p2 = new Person(20);
    Person *p3 = new Person(30);
    Person *p4 = new Person(40);
    Person *p5 = new Person(60);
    v.push_back(*p1);
    v.push_back(*p2);
    v.push_back(*p3);
    v.push_back(*p4);
    v.push_back(*p5);


    vector<Person> v1;
    Person *p12 = new Person(1);
    Person *p22 = new Person(2);
    Person *p32 = new Person(3);
    Person *p42 = new Person(4);
    Person *p52 = new Person(6);
    v.push_back(*p12);
    v.push_back(*p22);
    v.push_back(*p32);
    v.push_back(*p42);
    v.push_back(*p52);

    vector<Person>::iterator pBegin = v.begin();
    vector<Person>::iterator pEnd = v.end();
    //algorithm 遍历 func为回调函数
    for_each(pBegin, pEnd, func);
   
    //容器嵌入容器
    vector<vector<Person> > x;
    x.push_back(v);
    x.push_back(v1);

    //容器嵌套遍历
    for(vector<vector<Person> >::iterator ppBegin=x.begin(); ppBegin!=x.end(); ppBegin++){
        for(int i = 0; i < (*ppBegin).size(); i++)
            cout << (*ppBegin)[i].res << endl;
    }*/
	vector<int> v;
	int arr[] = {1, 2, 3, 4 };
	vector<int> v1(arr, arr+sizeof(arr)/sizeof(arr[0]));

	vector<int>::iterator bbgin = v1.begin();
	vector<int>::iterator eend = v1.end();
	cout << "size:" << v1.size() << endl;
	cout << "capacity:" << v1.capacity() << endl;
	v1.insert(bbgin, 10);
	//for_each(bbgin, eend, fun2);
	for(bbgin = v1.begin(); bbgin != v1.end(); bbgin++){
		cout << *bbgin << endl;
	}
	cout << "size:" << v1.size() << endl;
	cout << "capacity:" << v1.capacity() << endl;
	vector<int>(v1).swap(v1);
	cout << "size:" << v1.size() << endl;
	cout << "capacity:" << v1.capacity() << endl;

	cout << "------------" << endl;
	v1.swap(v);
	cout << "v1 size:::" << v1.size() << endl;
	cout << "v size:::" << v.size() << endl;
	vector<int> vv(10, 5);

	for(int j = 0; j < 10; j++){
		cout << vv[j] << endl;
	}

	vector<int> vv1(vv);
	for(int j = 0; j < 10; j++){
		cout << vv1[j] << endl;
	}

	/*
	vector<int> v;
	int num = 0;
	int * address = NULL;
	v.reserve(100000000);
	for(int i = 0; i < 100000000; i++){
		v.push_back(i);
		if(address != &(v[0])){
			address = &(v[0]);
			num++;//num为释放空间重新申请空间的次数，重新申请并拷贝数据会耗时，因此reserve可提前申请空间减少时间消耗
		}
	}
	cout << "num : " << num << endl;
	cout << "size:"<< v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;
	*/
    return 0;
}
