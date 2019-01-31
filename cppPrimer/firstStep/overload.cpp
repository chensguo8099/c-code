#include<iostream>
#include <vector>
using namespace std;

class Account{};
class Phone{};
class Name{};

class Record{
public:
    Account a;
    Phone b;
    Name c;
};

void lookup(const Account& acct){
    cout << "使用帐号进行查找" << endl;
}
void lookup(const Phone& phone){
    cout << "使用电话号码进行查找" << endl;
}
void lookup(const Name& name){
    cout << "使用姓名进行查找" << endl;
}

void show(int x){
    cout << x << endl;
}

void show(vector<int> v){
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout << *iter << endl;
    }
}

/*不能根据返回值的不同而重载
void foo(int a){}
bool foo(int a){}
*/
class MyScreen{
public://提倡用重载函数，但这中情况：这三个move***比下面类的move好，比函数重载好 因为这样的设计有助于程序代码的直观性
    void moveHome();
    void moveAbs(int, int);
    void moveRel(int, int, char *direction);
};

class YourScreen{
public:
    void move();
    void move(int, int);
    void move(int, int, char* direction);
};

int main(){

    MyScreen m;
    YourScreen n;
    m.moveHome();
    n.move();

    Account x;
    Phone y;
    Name z;

    lookup(x);
    lookup(y);
    lookup(z);

    int a = 89;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);

    show(a);
    show(b);
    return 0;
}
