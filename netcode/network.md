### 网络编程杂记
| 七层模型OSI ||
|---|--|
|  物理层 | 双绞线、光纤|
|数据链路层|数据传输错误检测|
|网际层|为数据包选择路由|
|传输层|提供端对端接口 TCP/UDP
|会话层|解除或建立节点间联系
|表示层|数据格式化、代码转换、数据加密
|应用层|文件传输、电子邮件、文件服务、虚拟终端

| TCP/IP四层模型  |   |
|---|---|
|数据传输层|物理层+数据链路层合并
|网络层|
|传输层|
|应用层|会话层+表示层+应用层合并

* IP头部：版本（v4\v6）、8位生存时间（TTL）、32位源IP、32位目的IP等。每经过一个路由，TTL-1直到TTL为0则路由丢弃该数据包。

* UDP数据包：16位源port、16位目的port、16为UDP长度、16位UDP校验和、数据。

* 16位源port、16位目的port、32位序列号、32位确认序列号、6个标志位、16位滑动窗口。

* tcp是**面向连接**的**安全**的**流式**传输协议。连接的时候进行三次握手，数据发送的时候会进行数据确认，数据丢失之后会进行数据重传。
* udp面向无连接的不安全的报文传输，连接时候不会握手，数据发送出去之后就不管了。如果数据包丢失会全丢，不存在丢失一半的情况。


### socket
#### 服务器
1. 创建套接字
```c
int lfd = socket
```
2. 绑定本地IP和PORT
```c
struct sockaddr_in serv;
serv.port = htons(port);
serv.ip = htonl(INADDR_ANY);
bind(lfd, &serv, sizeof(serv));
```
3. 监听
```c
listen(lfd, 128);
```
4. 等待并接受连接请求
```c
struct sockaddr_in client;
int len = sizeof(client);
int cfd = accept(lfd, &client, &len);
//cfd用于通信
```
5. 通信
```c
接收数据：read/recv
发送数据：write/send
```
6. 关闭
```c
close(lfd);
close(cfd);
```
#### 客户端
1. 创建套接字
```c
int fd = socket;
```
2. 连接服务器
```c
struct sockaddr_in server;
server.port
server.ip = (int) ?? //如何把点分十进制ip转成int
server.family
connect(fd, &server, sizeof(server));
```
3. 通信
```c
接收数据：read/recv
发送数据：write/send
```
4. 关闭
```c
close(fd);
```
