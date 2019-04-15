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

```go
//请编写一个程序,具体要求如下
//1) 编写一个函数 makeSuffix(suffix string) 可以接收一个文件后缀名（比如.jpg），并返回一个闭包
//2) 调用闭包，可以传入一个文件名，如果该文件名没有指定的后缀（比如.jpg），则返回 文件名.jpg，如果已经有.jpg 后缀，则返回原文件名。
//3) 要求使用闭包的方式完成。
//4) strings.HasSuffix(name string, suffix string)，该函数可以判断某个字符串是否有指定的后缀。
package main

import (
	"fmt"
	"strings"
)

//实现一个闭包
func makeSuffix(suffix string) func(string) string {
	return func(name string) string {
		//name无suffix后缀
		if !strings.HasSuffix(name, suffix) {
			return name + suffix
		} else {
			return name
		}
	}
}

func main() {
	f := makeSuffix(".jpg")
	fmt.Println(f("heleee"))
}
//上面代码的总结和说明：
//1) 返回的匿名函数和 makeSuffix(suffix string) 的suffix变量组合成一个闭包，因为返回的函数引用到suffix这个变量。
//2) 我们体会一下闭包的好处，如果使用传统的方法，也可以轻松实现这个功能，但是传统方法需要每次都传入后缀名，比如.jpg，而闭包因为可以保留上次引用的某个值，如.jpg，所以我们传入一次就可以反复使用。
```

* 在函数中，程序员经常需要创建资源（比如：数据库连接、文件句柄、锁等），为了在函数执行完毕后，及时的释放资源，Go的设计者提供`defer(延时机制)`。
```go
//1) 当 go 执行到一个 defer 时，不会立即执行 defer 后的语句，而是将 defer 后的语句压入到一个栈中[暂时称该栈为 defer 栈]，然后继续执行函数下一个语句。
//2) 当函数执行完毕后，在从 defer 栈中，依次从栈顶取出语句执行（注：遵守栈先入后出的机制）。
//3) 在 defer 将语句放入到栈时，也会将相关的值拷贝同时入栈。请看一段代码:
func deferTest(n1 int, n2 int) int {
	defer fmt.Println("first defer", n1, n2)  //third
	defer fmt.Println("second defer", n1, n2) //second
	n1++ //此n1非defer栈中n1
	n2++ //此n2非defer栈中n2
	res := n1 + n2
	fmt.Println("res : ", res) //frist
	return res
}

func main() {
	res := deferTest(10, 20) //forth
	fmt.Println("main", res)
}
//1) 在 golang 编程中的通常做法是，创建资源后，比如（打开了文件，获取了数据库的链接，或者是锁资源），可以执行 defer file.Close() defer connect.Close()
//2) 在 defer 后，可以继续使用创建资源。
//3) 当函数完毕后，系统会依次从 defer 栈中，取出语句，关闭资源。
//4) 这种机制，非常简洁，程序员不用再为在什么时机关闭资源而烦心。
```
* 1）值传递：基本数据类型`int`系列，`float`系列，`bool`，`string`、数组和结构体`struct`。2）引用传递：指针、`slice`切片、`map`、管道`chan`、`interface`等
```
//字符串相关函数
说明：字符串在我们程序开发中，使用的是非常多的，常用的函数需要掌握：
1) 统计字符串的长度，按字节： len(str)
2) 字符串遍历，同时处理有中文的问题： r := []rune(str)
3) 字符串转整数： n, err := strconv.Atoi("12")
4) 整数转字符串： str = strconv.Itoa(12345)
5) 字符串转[]byte： var bytes = []byte("hello go")
6) []byte转字符串： str = string([]byte{97, 98, 99})
7) 10进制转2，8，16进制： str = strconv.FormatInt(123, 2) // 2-> 8 , 16
8) 查找子串是否在指定的字符串中： strings.Contains("seafood", "foo") //true
9) 统计一个字符串有几个指定的子串： strings.Count("ceheese", "e") //4
10) 不区分大小写的字符串比较（==是区分字母大小写的）： strings.EqualFold("abc", "Abc") //返回true
11) 返回子串在字符串第一次出现的index值，如果没有返回-1： strings.Index("NLT_abc", "abc") //4
12) 返回子串在字符串最后一次出现的index。如没有返回-1： strings.LastIndex("go golang", "go")
13) 将指定的子串拷贝，对拷贝的串替换并返回： strings.Replace("go go hello", "go", "go语言", n) //n可以指定你希望替换几个,如果 n=-1 表示全部替换
14) 按照指定的某个字符，为分割标识，将一个字符串拆分成字符串数组： strings.Split("hello,wrold,ok", ",") //返回一个数组，存放3个元素 "hello" "world" "ok"
15) 将字符串的字母进行大小写的转换： strings.ToLower("Go") //strings.ToUpper("Go") // GO
16) 将字符串左右两边的空格去掉： strings.TrimSpace(" tn a lone gopher ntrn   ") //结果"tn a lone gopher ntrn"
17) 将字符串左右两边指定的字符去掉： strings.Trim("! hello! !", " !") // ["hello"] //将左右两边 ! 和 " "去掉
18) 将字符串左边指定的字符去掉： strings.TrimLeft("! hello! !", " !") // ["hello! !"] //将左边 ! 和 " "去掉
19) 将字符串右边指定的字符去掉 : strings.TrimRight("! hello! !", " !") // ["! hello"] //将右边 ! 和 " "去掉
20) 判断字符串是否以指定的字符串开头: strings.HasPrefix("ftp://192.168.10.1", "ftp") // true
21) 判断字符串是否以指定的字符串结束: strings.HasSuffix("NLT_abc.jpg", "abc") //false


//时间日期相关函数
1) 时间和日期相关函数，需要导入 time 包
2) time.Now()返回值类型为 time.Time 类型，用于表示时间
3) 如何获取到其它的日期信息：now := time.Now() now.Year() now.Month() now.Day() now.Hour() now.Minute() now.Second()
4) 格式化日期时间
方式一： 就是使用 Printf 或者 Sprintf
方式二： 使用 time.Format() 方法完成
5) 时间的常量：
const (
	Nanosecond	         = 1 //纳秒
	Microsecond	         = 1000 * Nanosecond	//微秒
	Millisecond          = 1000 * Microsecond //毫秒
	Second               = 1000 * Millisecond //秒
	Minute               = 60 * Second //分钟
	Hour                 = 60 * Minute //小时
)
time.Sleep(time.Second(1))

rand.Seed(time.Now().UnixNano())
randNum := rand.Intn(100) //随机一个[0, 100)的数
```

___________
* Go异常处理通过`defer + recover`实现，并且必须写在可能出现异常部分的前方，如下：
```go
//recover必须写在捕捉到异常之前
func catchErr() {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Printf("err : %v\n", err)
		}
	}()
	num1 := 10
	num2 := 0
	num := num1 / num2
	fmt.Printf("num : %d\n", num)
}
```
* Go 程序中，也支持自定义错误，使用 errors.New 和 panic 内置函数。1) errors.New("错误说明")，会返回一个 error 类型的值，表示一个错误2） panic 内置函数，接收一个 interface{} 类型的值（也就是任何值了）作为参数。可以接收 error 类
型的变量，输出错误信息，并退出程序。即自定义错误处理：err := errors.New("balabala..") 和 panic(err)，实例如下：
```go
func errTest2(name string) (err error) {
	if name == "config.init" {
		return nil
	} else {
		return errors.New("配置文件不匹配")
	}
}

func catchErr2() {
	err := errTest2("config.ini")
	if err != nil {
		panic(err)
	}
}
```

__________
* 数组定义三种方式即`for-range`遍历方式：
```go
func arrDefine() {
	// var arr [3]string = [3]string{"aa", "bb", "cc"}
	// var arr = [3]string{"aa", "bb", "cc"}
	arr := [3]string{"aa", "bb", "cc"} //以上三种定义均可 第三种最简洁

	for index, value := range arr {
		fmt.Printf("index : %d\tval : %s\n", index, value)
	}
}
```
* 数组是多个相同类型数据的组合，一个数组一旦声明/定义了，其长度是固定的，不能动态变化。
* `var arr []int`这时 arr 就是一个 slice 切片，所以定义数组必须写长度，如果不像定义则写成类似这样：`arr := []string{"abc", "def", "wadwf"}`。
* 数组中的元素可以是任何数据类型，包括值类型和引用类型。
* 数组创建后如果没有赋值，有默认值（零值）数值类型数组：默认值为0，字符串数组：默认值为""，bool数组：默认值为false。
* 切片是数组的一个引用，因此切片是引用类型，在进行传递时，遵守引用传递的机制。切片的使用和数组类似，遍历切片、访问切片的元素和求切片长度len(slice)都一样。切片的长度是可以变化的，因此切片是一个可以动态变化数组。
* slice使用的三种方式：
```go
func sliceCreate() {
	//方式1. 定义一个切片 然后引用一个数组
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}
	slice := arr[2:4]
	fmt.Printf("slice: %d\tslice len: %d\tslice cap: %d\n", slice, len(slice), cap(slice))
	//使得slice置空 len = 0
	slice = arr[:0]
	fmt.Printf("slice: %d\tslice len: %d\tslice cap: %d\n", slice, len(slice), cap(slice))
	//从arr[4]到arr[len(arr) - 1]
	slice = arr[4:] //等价于取arr  ->  [0, len(arr))
	fmt.Printf("slice: %d\tslice len: %d\tslice cap: %d\n", slice, len(slice), cap(slice))
	//取arr所有
	slice = arr[:] //等价于取arr  ->  [0, len(arr))
	fmt.Printf("slice: %d\tslice len: %d\tslice cap: %d\n", slice, len(slice), cap(slice))

	//方式2. 通过make创建切片 基本语法：var 切片名 []type = make([]type, len, [cap])
	// 1) 通过 make 方式创建切片可以指定切片的大小和容量
	// 2) 如果没有给切片的各个元素赋值，那么就会使用默认值[int, float=>0， string=>””， bool=>false]
	// 3) 相比于方式1 通过 make 方式创建的切片对应的数组是由 make 底层维护，对外不可见，即只能通过 slice 去访问各个元素。
	var slice2 []int = make([]int, 4, 10)
	for index, _ := range slice2 {
		fmt.Printf("slice2[%d]: %d\t", index, slice2[index])
	}
	fmt.Println()

	//方式3. 直接将数组附值给切片
	var slice3 []string = []string{"tom", "jerry", "spack"}
	for _, value := range slice3 {
		fmt.Printf("%v\t", value)
	}
	fmt.Println()
}
```
* 切片初始化时 var slice = arr[startIndex:endIndex]说明:从 arr 数组下标为 startIndex，取到下标为 endIndex 的元素（不含 arr[endIndex]）。切片初始化时，仍然不能越界。范围在 [0-len(arr)] 之间，但是可以动态增长。var slice = arr[0:end] 可以简写：var slice = arr[:end]，var slice = arr[start:len(arr)] 可以简写：var slice = arr[start:]var slice = arr[0:len(arr)]，可以简写：var slice = arr[:]3) cap 是一个内置函数，用于统计切片的容量，即最大可以存放多少个元素。切片定义完后，还不能使用，因为本身是一个空的，需要让其引用到一个数组，或者 make 一个空间供切片来使用。切片可以继续切片。
* 切片 append 操作的底层原理分析：切片 append 操作的本质就是对数组扩容，go 底层会创建一下新的数组 newArr，将 slice 原来包含的元素拷贝到新的数组 newArr，slice 重新引用到 newArr，注意 newArr 是在底层来维护的，程序员不可见。
* copy函数可用于对切片的拷贝：
```go
func sliceCopy() {
	var sliceCopySrc []string = []string{"09", "pdd", "pis"}
	var sliceCopyDest []string = make([]string, 10)

	copy(sliceCopyDest, sliceCopySrc)
	fmt.Println(sliceCopyDest)
}
```
* string 底层是一个`byte`数组，因此`string`也可以进行切片处理。如果要修改`string`中的内容，修改字母可通过将str转为`[]byte`然后修改，修改完毕再转回来；如果修改汉字（汉字占三个字符）则需将字符串转为`[]rune`类型切片，修改完毕后再转为`string`。
```go
func sliceModifyString() {
	//将string改为[]byte切片 然后修改后 再转为string 而不能直接对string修改
	var str string = "hello world!"
	arr := []byte(str)
	arr[2] = 'b'
	str = string(arr)
	fmt.Printf("%s\n", str) //heblo world!

	arr2 := []rune(str)
	arr2[0] = '晨'
	str = string(arr2)
	fmt.Println(str) //晨eblo world!
}
```