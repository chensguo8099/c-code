### go summary

---------------

[go学习指南](https://tour.go-zh.org/welcome/1)
[go标准库中文文档](https://studygolang.com/pkgdoc)

-----------------


* go函数可以直接支持返回多个返回值，在C/C++中需要通过数组返回。

```go
package main
import "fmt"
func function() (int, int) {
	a := 10
	b := 5
	return a + b, a - b
}

func main() {
	fmt.Println(function()) //15 5
}
```

* 要有正确注释风格（推荐行注释 `go fmt -w main.go`可以对`main.go`文件格式美化。
* 如果代码过长，如
```go
  Printl("233333",
  "333333", 
  "33333") //可以采用逗号的方式将字符串23333333333分割成几行写
```

* Go语言的SDK是什么？SDK就是软件开发工具包。我们做 Go开发，首先需要先安装并配置好sdk。
* 能够一次性定义多局部变量和多全局变量，如下
```go
//局部变量
//var a1, a2, a3 = 15, "tom", 17
a1, a2, a3 := 15, "tom", 17

//全局变量
//var n1 = 100
//var n2 = 200
//var v3 = "tom"
var (
	n1 = 100
	n2 = 200
	n3 = "tom"
)
```
* go语言中内嵌C代码，如下
```go
package main

import "fmt"

//go语言中嵌入C语言代码时必须注释C中代码，并在尾部用import "C"链接

/*
#include <stdio.h>
void printfunc(){
	printf("hello world , it's C programming\n");
}
*/
import "C"

func main() {
	C.printfunc() //打印hello world , it's C programming\n
}
```
* `unsafe.Sizeof()`可查看变量大小，`fmt.Printf(“%T”， num)`可查看`num`的数据类型，`num := .123`表示`var num = 0.123`，可以用科学计数法初始化，如`num := 5.12e2`等价于`num := 5.12E2`，既就是`512`，推荐开发中使用`float64`。
* go中的string类型字符串一旦附值，则无法修改其中某些字符，可重新附值新串。
* 多个字符串拼接时`+`号留在后面而不能放在换行后的前面，如
```go
var str = "hello" + 
	"world" + 
	"welcome"
	
/*error
var str = "hello"
	+ "world"
	+ "welcome"
*/
```
* go中的数据类型必须显式转换，而不能像`c/java`这样进行自动的隐形转换。
* go中的`%T`格式化输出变量类型，`%v`输出变量默认值，如`var err error`，如果未发生错误，`%v`输出的就是nil。
* 基本类型转`string`一般不会出现问题，但是要特别注意`string`转基本类型时要确保能够转换成功，需要注意的是如果要将一个`string`转成`int`时，如果转换不合法，接收变量的值也会被修改为`0`，如果将一个`string`转为`bool`，转换不合法的情况下可以编译通过，但是接收的变量会被置为`false`，其他类型同，如下：
```go
var intNum int64 = 13
var strConvInt string = "hello"
intNum, _ = strconv.ParseInt(strConvInt, 10, 64)
fmt.Printf("%v\n", intNum) //0 原来的13被覆盖掉

var boolNum bool = true
var strConvBool string = "lalala"
boolNum, _ = strconv.ParseBool(strConvBool)
fmt.Printf("%v\n", boolNum) //boolNum由最初的true置为false
```

* 如果变量名、函数名、常量名首字母大写，则可以被其他的包访问；如果首字母小写，则只能在本包中使用（注：可以简单的理解成首字母大写是公开的，首字母小写是私有的），在`golang`没有`public`，`private`等关键字。
* 在`golang`中设计的`++``--`只能单独使用，不像`c`这种还分前+和后+，而且GO中不能连`++`，如`a++++`，只能分开写两次`++`，而且只有后`++``--`。
* 分支结构`{}`是必须有的，哪怕代码只有一行，同样也可以在if中定义变量，同时if后条件可以有`()`，但是不建议使用。
* `switch`：1）`case/switch`后是一个表达式（即：常量值、变量、一个有返回值的函数等都可以）。2）`case`后的各个表达式的值的数据类型，必须和`switch`的表达式数据类型一致。3）`case`后面可以带多个表达式，使用逗号间隔。比如`case`表达式1，表达式2...。4）`case`后面的表达式如果是常量值（字面量），则要求不能重复。5）`case`后面不需要带`break`，程序匹配到一个`case`后就会执行对应的代码块，然后退出`switch`，如果一个都匹配不到，则执行`default`。6）`default`语句不是必须的。7）`switch`后也可以不带表达式，类似`if else`分支来使用。8）`switch`后也可以直接声明/定义一个变量，分号结束，不推荐。9）`switch`穿透`fallthrough`，如果在`case`语句块后增加`fallthrough`，则会继续执行下一个`case`，也叫`switch`穿透。10）`Type Switch:switch`语句还可以被用于`type-switch`来判断某个`interface`变量中实际指向的变量类型。如下：
```go
var days int = 1
switch days {
case 1:
	fmt.Println("1")
	fallthrough //穿透
case 2:
	fmt.Println("2")
	fallthrough //穿透
case 3:
	fmt.Println("3")
}

var x interface{}
var y = "stringlala"
x = y
switch i := x.(type) {
case int:
	fmt.Printf("x type : %T\n", i)
case string:
	fmt.Printf("x type : %T\n", i) //执行
}
```

* `for {//循环执行语句}`这样的写法等价`for ; ; {}`是一个无限循环，通常需要配合`break`语句使用`utf8`编码是对应`3`个字节。如下情况：
```go
func test7() {
	var str string = "hello郭晨"

	//传统遍历
	for i := 0; i < len(str); i++ {
		fmt.Printf("%c\n", str[i])
	}

	//for-range遍历方法
	var str2 string = "nihao郭晨"
	for index, val := range str2 {
		fmt.Printf("index = %d val = %c\n", index, val)
	}
	//切片方法解决传统遍历中文乱码情况
	str3 := []rune(str)
	for i := 0; i < len(str3); i++ {
		fmt.Printf("%c\n", str3[i])
	}
}
```
* Go语言没有`while`和`do...while`语法，这一点需要同学们注意一下，如果我们需要使用类似其它语言（比如`java / c`的`while`和`do...while`），可以通过`for`循环来实现其使用效果。
* `break`语句出现在多层嵌套的语句块中时，可以通过标签指明要终止的是哪一层语句块。（1）`break`默认会跳出最近的`for`循环（2）`break`后面可以指定标签，跳出标签对应的`for`循环。如下：
```go
label1:
for i := 0; i < 5; i++ {
	println("aaa")
	// label2:
	for j := 0; j < 5; j++ {
		println("bbb")
		break label1
	}
}
```
* Go函数不支持函数重载，在Go中，函数也是一种数据类型，可以赋值给一个变量，则该变量就是一个函数类型的变量了，通过该变量可以对函数调用。函数既然是一种数据类型，因此在Go中，函数也可以作为形参并且调用，如下：
```go
func getSum(n1 int, n2 int) int {
	return n1 + n2
}

func getSum2(tmpfunc func(int, int) int, n1 int, n2 int) int {
	return tmpfunc(n1, n2)
}

func main() {
	//函数也是一种数据类型
	a := getSum
	var b func(int, int) int
	fmt.Printf("a type = %T, getSum type = %T\n", a, getSum)

	b = getSum
	fmt.Printf("%d\n", b(1, 2)) //3

	//函数嵌套 getSum类型为func(int, int) int 因此用tmpfunc接收
	res := getSum2(getSum, 5, 7)
	fmt.Printf("res : 5 + 7 = %d\n", res)

	//函数类型附值 res2类型也为func(int, int) int
	res2 := getSum2
	fmt.Printf("res : 13 + 22 = %d\n", res2(getSum, 13, 22))
}
```
* Go支持自定义数据类型，即`type [自定义数据类型] [基本数据类型]`，类似C语言中的`typedef`。
* Go支持对函数返回值命名，返回时即可不需要写要返回什么，如下：
```go
func test9(n1 int, n2 int) (sum int, sub int) {
	type myInt int
	var test myInt
	fmt.Printf("myInt type : %T\n", test)
	sum = n1 + n2
	sub = n1 - n2
	return //若返回值列表定义值 则return这里可以省略返回什么
}
func main(){
	var sum int
	var sub int
	sum, sub = test9(6, 13)
	fmt.Printf("sum = %d, sub = %d\n", sum, sub)
}

```
* Go支持可变参数，即`func function(args ...int)`，其中`args`为一个存放可变参数的数组，名字不一定非要起为`args`，可任意取，只不过后面取出参数的时候用到的是自己起的名字，而且可变参数`args ...int`应放在形参列表的最后一个。
* Go中有一个init函数，通常是在main函数前进行执行，可以完成一些初始化工作，如果一个文件同时包含全局变量定义，`init`函数和`main`函数，则执行的流程为：`全局变量定义->init函数->main函数`。
* 如果`main.go`和`utils.go`都含有变量定义，`init`函数时，执行的流程又是怎么样的呢？[链接](https://blog.csdn.net/claram/article/details/77745665)
* Go支持匿名函数，匿名函数就是没有名字的函数，如果我们某个函数只是希望使用一次，可以考虑使用匿名函数，匿名函数也可以实现多次调用。
* Go语言匿名函数及回调方法：[链接](https://blog.csdn.net/ynzcxx/article/details/84138062)
* *闭包*就是一个函数和与其相关的引用环境组合的一个整体（实体），如下实例代码观察n的值变化情况：
```go
func AddUpper() func(int) int {
	var n int = 10
	return func(x int) int {
		n = n + x
		return n
	}
}
func main() {
	//闭包
	f2 := AddUpper()
	fmt.Println(f2(1)) //11
	fmt.Println(f2(1)) //12
	/*
	返回的是一个匿名函数，但是这个匿名函数引用到函数外的n
	因此这个匿名函数就和n形成一个整体，构成闭包。
	*/
}
```
