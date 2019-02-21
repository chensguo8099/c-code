* 什么时候用`初始化列表`？
* `new/delete`与`malloc/free`的区别？（两点
* static成员是命名空间，属于`类的全局变量`，存储在data区。
* static成员函数只能返回static成员变量，不能用this指针，static成员函数`属于类而不属于类对象`。
* this指针不是`const [类]*`类型，是`[类]* const`类型的常指针。

```
int get() const{//成员函数尾部出现const修饰this指针，表示this指针无法修改
    this->_a = 100;//error
}
```

* 1.友元关系是单向的，不具有交换性；不能被继承；不具有传递性