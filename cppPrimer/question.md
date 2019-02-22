C++基础学习总结
-----------

* 什么时候用`初始化列表`？
* `new/delete`与`malloc/free`的区别？（两点
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

-----
* 将一个对象当成普通函数调用，称这种对象是`仿函数`或`伪函数`。
```c++
void *operator new(size_t size);
void *operator new[](size_t size);
void operator delete(void *p);
void operator delete[](void *p);
//重点关注new/delete重载时的返回值和参数
```

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
* 对于`菱形结构`的继承关系，最上层记为A类，中间记为B、C类，最下层记为D类，则因为D继承B、C两个类来自A的成员变量时会产生重复，所以将B、C继承A类时改为虚继承（D类无须加`virtual`），`防止A类中的成员变量由于D对B、C的多继承而产生多份。`
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
