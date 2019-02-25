## C++基础学习杂记（很敬畏这门语言.

* 什么时候用`初始化列表`？
* `new/delete`与`malloc/free`的区别？（两点
* 如果new和delete[]配对使用，new[]和delete配对使用，会发生什么事情？
* 处理多态时delete对象时要采用虚析构才能应对多态。
* static成员是命名空间，属于`类的全局变量`，存储在data区。
* static成员函数只能返回static成员变量，不能用this指针，static成员函数`属于类而不属于类对象`。
* this指针不是`const [类]*`类型，是`[类]* const`类型的常指针。
* 类成员函数默认第一个参数为`隐式`的this常指针

```
int get() const{//成员函数尾部出现const修饰this指针，表示this指针无法修改
    this->_a = 100;//error
}
```

------
### 重载相关
* 函数重载的条件：参数个数不同和参数类型不同。要是只有返回值不同，参数列表和参数类型相同，则这两函数为相同函数，无法重载。
* 友元关系是单向的，不具有交换性；`不能被继承`；不具有传递性
* 当重载++运算符时的前缀++和后缀++的写法：
```c++
//前缀++ (一般正常写为前缀++
Test &operator++(Test &obj){
    ++obj.num;
    return obj;
}
//后缀++ (第二个参数为占位符
Test &operator++(Test &obj, int){
    ...
}
```
* `[]重载只能作为成员函数`，不像+重载可以作为成员函数返回类的引用`return *this;`也可以为全局返回void，但是考虑到a+b+c+..这样连续加，一般也把+重载为成员函数让其返回类的引用，这样就可以将+的结果作为左值然后连续+操作。《C++ Primer》page 611 “C++要求，赋值=、下标[]、调用()、成员访问箭头->操作符必须被定义为类成员操作符，任何把这些操作符定义为名字空间成员的定义都会被标记为编译时刻错误。
* 将一个对象当成普通函数调用，称这种对象是`仿函数`或`伪函数`。
```c++
void *operator new(size_t size);
void *operator new[](size_t size);
void operator delete(void *p);
void operator delete[](void *p);
//重点关注new/delete重载时的返回值和参数
```


-----
### 继承相关
* C++的`可重用性`是通过继承机制实现的。
* 现有父子孙相互继承的三个类，`class Praent, class Child:public Parent`, `class Subchild:public Parent`，子类均可访问基类的`public`和`protected`，但`protected`仅能类内部访问，同时子类无法访问基类的`private`。
* 只要是父类的private成员，不管是什么继承方式，子类均不可访问。
* 如果是public继承，儿子中的访问控制权限保持不变。
* 如果是protected继承，儿子中父亲中除了private成员，其余在儿子中都是protected。

|父类属性-->  |  public |protected | private|
|---|---|---|---|
| 公有继承| public  |protected|不可见|
|保护继承 | protected  |protected|不可见|
|私有继承 | private  |private|不可见|

* 父类可等号附值给子类，但子类不可附值给父类；当定义指向父类的指针pp和定义指向子类的指针cp时，子类指针cp不能指向父类，但指向父类的pp指针可以指向子类（因为父类的内存布局包含于子类中，父类指针可以满足于子类的全部需求）
* 无论子类写不写构造函数，都会自动调用父类的构造方法。子类调用构造必调用父类构造，至于调用父类的什么构造(默认构造、拷贝构造、或者有参构造等)取决于子类的构造方法。当子类构造中不需要父类对象时父类调用无参构造(默认构造)；当子类构造中需要父类对象时根据父类对象传的成员变量还是类决定父类调用有参构造还是拷贝构造。
* C++中子类可以继承父类所有的成员变量和成员方法，但是无法继承父类的构造函数。
```c++
//C++特性 多继承
class SofaBed:public Sofa, public Bed{
public:
    ...
privte:
    ...
};
```
* 对于`菱形结构`的继承关系，最上层记为A类，中间记为B、C类，最下层记为D类，则因为D继承B、C两个类来自A的成员变量时会产生重复，所以将B、C继承A类时改为虚继承（D类无须加`virtual`），`防止A类中的成员变量由于D对B、C的多继承而产生多份。`这种菱形继承如果不采用虚继承方式，当D类继承B、C重叠的成员变量，会产生二义性，系统不知道选择B类中的成员变量还是C类中的成员变量，需要我们手动指定获取B、C谁的成员变量。假设不采用虚继承方式，则D访问某继承的成员变量时实际调用类的顺序是：`A类构造->B类构造->A类构造->C类构造`，拷贝了两个空间的成员变量，浪费空间；如果采用虚继承方式，则顺序为：`A类构造->B类构造->C类构造`，也就是说A类构造只执行了一次，虚继承很好的解决了D类对从A继承过来的B、C类共有的成员变量不会重复继承过来的问题，节约了空间也避免了成员变量继承的二义性，采用虚继承后D类用到的成员变量不再是B、C中的一个，而是直接从A中继承成员变量。但**采用虚继承无法解决成员函数冲突问题，必须手动指定调用哪个类中的成员函数**，假设A、B、C类中均有个成员方法`print()`，当D要调用`print()`时，需要指定为类似这种：`D obj;` `obj.B::print()`或者`obj.C::print`，且D仅能指定调用B或者C类中的成员方法，也就是说尽管B、C虚继承A，仍然会存在对`print()`方法调用上的二义性，但如果D类中也有print方法，则优先调用D类内部的print方法。[[链接1]](https://blog.csdn.net/gc348342215/article/details/87890844)[[链接2]](https://github.com/chensguo8099/practice/blob/master/cppPrimer/firstStep/test10.cpp)
```c++
class A{
public:
    int m;
}
class B:virtual public A{
    ...
}
class C:virtual public A{
    ...
}
```
* [为什么new/delete和new[]/delete[]必须配对使用？如果用new和delete[]或者让new[]和delete配对使用结果如何？](https://blog.csdn.net/cwcmcw/article/details/53873600)

* 虚继承与虚函数的`virtual`意义不同，是两种用法。（何种意义、何种用法？

----
### 多态相关
* 多态发生的三个条件：1）要有继承。2）要有虚函数重写。3）父类指针或引用指向子类对象。如下：
```c++
class Yuebuqun{
public:
    Yuebuqun(string kongfu){
        this->kongfu = kongfu;
    }
    virtual void fight(){//修饰成员方法为虚函数
        cout << "岳不群使出了" << kongfu << "打人" << endl;
    }
    string kongfu;
};
//林平之继承了岳不群
class Linpingzhi:public Yuebuqun{
public:
    Linpingzhi(string kongfu):Yuebuqun(kongfu){}
    virtual void fight(){//子类的virtual可不写 写了也无影响，增强代码可读性 表示父类和子类的fight方法实现多态。
        cout << "林平之使出了" << kongfu << "打人" << endl;
    }

};
//父类指针兼容子类对象 所以形参用父类指针
//父类指针操作范围比子类本身范围小 所以父类指针可指向子类
//父子均调用fightPeople默认hero为父类指针，则调用两次父类fight
//若要避免调用两次均父类fight、实现多态，则把父类fight定义为virtual
//这里的virtual修饰的是虚函数 与之前的解决菱形继承的虚继承是两个不同的问题
void fightPeople(Yuebuqun *hero){
    cout << "调用打人方法" << endl;
    hero->fight();
}
int main(){
    Yuebuqun *xiaoyy = new Yuebuqun("葵花宝典");
    Linpingzhi *xiaopp = new Linpingzhi("僻邪剑谱");

    fightPeople(xiaoyy);
    fightPeople(xiaopp);

    return 0;
}
```
* 动态联编和静态联编是对编译器来说的，多态对于编译器来说是一个动态联编，是迟绑定。
* 多态方法在调用delete释放new时需要使用虚析构的方法来实现多态，代码如下：
```c++
#include <iostream>
#include <cstring>
using namespace std;

class Father{
public:
    Father(){
        cout << "Father()" << endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "Father string...");
    }
    //实现多态
    virtual void print(){
        cout << "A:" << this->p << endl;
    }
    virtual ~Father(){
        cout << "~Father()" << endl;
        if(this->p != NULL){
            delete []this->p;
            this->p = NULL;
        }
    }
private:
    char *p;
};

class Son:public Father{
public:
    Son(){
        cout << "Son()" << endl;
        this->p = new char[64];
        memset(this->p, 0, 64);
        strcpy(this->p, "Son String...");
    }
    virtual void print(){
        cout << "B:" << this->p << endl;
    }
    ~Son(){
        cout << "~Son()" << endl;
        if(this->p != NULL){
            delete []this->p;
            this->p = NULL;
        }
    }
private:
    char *p;
};

void func(Father *fatherp){
    fatherp->print();
    delete fatherp;
    //此时必须将Father类的析构函数改为虚析构，否则：
    //即使fatherp接收Son类仍调用父类析构，却不执行子类析构
    //若父类析构改为虚构，当fatherp接受子类时会调用子类析构。
}

void test(){
    //Son obj;
    Son *bp = new Son;//传指针不是delete对象的话是不会打印该类析构的
    func(bp);
}

int main(){
    test();
    return 0;
}
```
* 重载、重定义、重写：
1. 重载一定是同一个作用域下。
2. 重定义是发生在两个不同的类中，一个是父类一个是子类。1）普通函数重定义：如果父类的普通成员函数被子类重写，说是重定义。2）虚函数重写：如果父类的虚函数被子类重写，就是虚函数重写，这个函数会发生多态。
* 若A、B类均存在同名同参不同函数体的成员函数`print()`且B继承A，A为B的父类，当一个A类指针接收一个B类对象时，通过A->访问B类的成员函数`print()`，编译器确定`print()`是否为虚函数：1）`print()`不是虚函数，编译器可直接确定被调用的成员函数，（静态联编，根据指针为A类型来确定）。2）若`print()`为虚函数，编译器会根据B对象的`Vptr指针`所指向的函数虚表查找`print()`并调用。
* 虚函数表指针Vptr调用重写函数是在程序运行时进行的，因此需要通过寻址操作才能确定真正应该调用的函数（静态联编），而普通成员函数是在编译时就确定了调用的函数，在效率上，虚函数效率要低很多。
* 当方法函数中发生多态时，此时delete会调用父类的析构函数，如果要释放多态对象，需要将父类的析构函数变为virtual虚析构。[[链接]](https://github.com/chensguo8099/practice/blob/master/cppPrimer/firstStep/test12.cpp)
* 对于虚函数需要避免的问题：当有继承和虚函数时避免用构造函数取调用虚函数，因为当子类构造时如果触发父类构造，**子类产生的Vptr是先指向父类的虚表的，进而当父类构造完毕后Vptr再指向子类虚表**，所以目的是说不要在构造函数中写业务，当项目代码过大时可能会产生繁琐的、难以察觉的问题，构造函数中调用业务出现的问题例子如下：
```c++
class A{
public:
    A(int a){
        this->a = a;
        print();//该print就会打印A中的虚函数virtual print!!!
    }
    virtual void print(){
        cout << "A(int)..." << endl;
    }
private:
    int a;
};
class B:public A{
public:
    B(int a, int b):A(a){
        print();//该函数就会打印B中的虚函数，此时A构造完毕因此vptr转移指向B的虚表
        this->b = b;
    }
    virtual void print(){
        cout << "B(int, int)..." << endl;
    }
private:
    int b;
};
int main(){
    A *ap = new B(10, 20);//在触发B构造函数前先触发A构造函数
    return 0;
}
```
* 要避免父类指针和子类指针步长越界问题，比如A类`sizeof(A) = 4`，B类继承A，B类`sizeof(B) = 8`，此时定义`A *pp`和`B *cp`，`A *pp = new B;`时`pp++`中`++`操作是按照父类的`sizeof(A)`进行`++`的，指针不会像多态一样根据B类的尺寸进行`++`，反而会因此产生指针非法或错误访问。

* 纯虚函数的抽象类下方的实例对象采用虚函数重写的方式将抽象类转换为多态。纯虚函数声明的抽象类不能被实例化。

---------
```c++
//模板
//等同于: template<typename T1, ...>
template<class T1, class T2, ...>
void swap(T1 &a, T1&b){
    ..
}
```
* 编译器优先寻找匹配的普通函数，若未找到才匹配模板，若用户想直接匹配模板，则：`MyFunc<>(a, b)`函数后加上尖括号即可。
* 模板类外实现成员函数时成员函数前也需加模板，构造和成员函数所属作用域后需要加上`<type>`才可以，如：`void Person<T>::show(){...}`这样，同样对象在创建时也要声明类型，如`Person<int> obj(10, 20)`，若模板类中有友元函数，友元函数在类外部实现时如果参数传递有模板类对象，那么需要在该友元函数上也加模板。
* 类模板若定义static变量，这个模板可能会生成多种的具体类对象，而实例化的某个具体类对象共用一个static成员变量，而另外的其他一些具体类对象共用另一个static。
* 在分离文件进行编译时需要将模板类函数实现放在调用的文件里，否则无法调用模板生成对应函数；我们可将模板函数当作是一种‘高级宏’。
* 容器都是值寓意，并非引用寓意，因此向容器中放的都是元素的拷贝份，并非元素本身。

|类型转换| 用法|
| ---  | ---|
|static_cast\<type>|用于**内置类型转换**和**有继承关系的指针或引用的转换**|
| dynamic_cast\<type>  | **只能转换具有继承关系的指针或引用**，在转换前会进行对象类型检查（子类指针可转为父类指针（从操作大空间变为操作小空间），安全；父类指针无法转为子类指针），这里要和子类指针可以接收父类对象但父类指针不能接收子类对象区分开  |
|const_cast\<type>|左值可以获得一个增加或取消const属性的变量，但变量原本const属性不会消失或不会给原本变量增加const属性，只是你拿过来后可以有const属性或可以取消const属性|
|reinterpret\<type>|强制类型转换，**任何类型**指针都可转为其他指针，包括函数指针等|
* 程序员必须清楚要转变的变量转换成什么类型，以及转换后的后果如何；一般情况下不建议使用或尽量避免使用类型转换。

-------
### STL标准模板库
* 容器中可以嵌套容器，容器分为：序列式容器：容器元素的位置是由进入容器的时机和地点来决定的；关联式容器：容器已有规则，进入容器的元素位置不由时间和地点决定。
* 迭代器：可理解为指针，对指针的操作基本都可以对迭代器操作，实际上迭代器是封装了一个指针的类。
* 算法：通过**有限步骤**解决问题。
* vector容器是单口容器，类似栈。特别要注意的是vector申请空间后capacity不会释放，所以需要我们手动收缩空间：`vector<type>(Obj).swap(Obj)`，实际含义就是创建匿名对象，然后给其赋Obj作初始化，然后匿名对象指针和原对象Obj指针进行交换，这时原对象指针则指向创建的匿名对象的空间，所以capacity就放缩了，并且释放了匿名对象。
```c++
//vector常用简单操作
vector<type> v;
v.size();
v.capacity();
v.reserve(100);//capacity 变为 100
v.resize(100); //size 变为 100
v.swap(v1);//v和v1交换空间及内容
vector<int>(v).swap(v);//防缩capacity
v.empty();//判断v是否为空
v.comapre(v1);//根据ASCII进行比较
v[i] = 100; v.at(i) = 100; //后者有异常检测
v.push_back(100);//尾插
v.pop_back(100);//尾出
v.assign(v1.begin(), v1.end());
v.assign(10, 5);//5555555555
vector<int> v(*begin, *end);
vector<int> v(10, 5);//5555555555
vector<int> v1; vector<int> v2(v1);
v1 = v2;



//-------
deque<type> d;//不需要像vector一样对capacity放缩，内部自动
d.push_front();//头插
d.pop_front();//头出
d.push_back();
d.pop_back();
//其他操作同vector


//-------
stack<type> s;
s.top();
s.pop();
s.push();
s.empty();
s.size();


//-------
queue<type> q;
q.front();//队头元素
q.back();//队尾元素
q.pop();//从队头出
q.push();//从队尾入


//-------
list<type> l;
l.pop_back();
l.push_back();
l.pop_front();
l.pop_front();
l.remove();//删除匹配所有值
l.reverse();//容器元素翻转
l.sort();//与算法sort不同，算法sort支持可随机访问的容器，而list不支持随机访问，只能给迭代器++操作访问下一个，如果用全局的算法提供的sort，效率会不稳定。
find(l.begin(), l.end(), 30);//查找基础数据类型还是对象，如果是对象需要提供回调。
//若要对类查找：
class Person{
public:
    Person(int a, int b):a(a), b(b){}
    bool operator==(const Person &a) const{
        return a.a == 10;
    }
public:
    int a;
    int b;
};

int main(){
    list<Person> l1;
    Person a1(10, 20), a2(30, 5), a3(22, 6), a4(1, 100);
    l1.push_back(a1);
    l1.push_back(a2);
    l1.push_back(a3);
    l1.push_back(a4);
    list<Person>::iterator it = find(l1.begin(), l1.end(), a1);
    if(it == l1.end()){
        cout << "not fount" << endl;
    }else{
        cout << (*it).a << " " << (*it).b  << endl;
    }
    return 0;
}




//-------
set<type> s;
s.find(key);//查找key是否存在，存在则返回该键元素的迭代起，不存在返回map.end();
如：
set<int>::iterator ret = s1.find(4);
if(ret == s1.end()){
    cout << "未找到" << endl;
}else{
    cout << "找到" << endl;
}
s.find(key);//返回迭代器位置 若it == s.end()则未找到
s.lower_bound(key);//返回迭代器指向第一个大于等于key的值
s.upper_bound(key);//返回迭代器指向第一个大于key的值
s.equal_range(key);//返回容器中与key相等的上下限的两个迭代器，也就是返回lower_bound和upper_bound的值。

s.equal_range的用法：
    pair<set<int>::iterator, set<int>::iterator> myret = s.equal.range(key);
    //myret.first;//第一个迭代器代表的值
    //myret.second;//第二个迭代器代表的值
    if(myret.first == s1.end()){
        cout << "not found" << endl;
    }else{
        cout << "found myret:" << *(myret.first) << endl;
    }

    if(myret.second == s1.end()){
        cout << "not found" << endl;
    }else{
        cout << "found myret:" << *(myret.second) << endl;
    }

set默认由小到大排序，也可以按照由大到小排序，自己定义仿函数：
class compare{
public:
    bool operator()(int a, int b){
        return a > b;
    }
    //解决类中根据某个元素排序的问题
    //bool operator()(Class &a, Class &b){
    //    return a.成员 > b.成员
    //}
}
set<int, compare> s;
s.insert(10);
s.insert(20);
for(set<int>::iterator it = ...){
    cout << (*it) << endl;
}



//map/multimap容器
//map相对与set的区别，map具有键值，所有元素根据键值自动排序，pair的第一元素被称为键值，第二元素被称为实值，map也是以红黑树为底层实现机制。map的键值无法修改，底层二叉树键值如果改了就混乱了，想改键值必须删除该对象后重新添加。
//map不允许相同键值key存在，multimap允许。
```



