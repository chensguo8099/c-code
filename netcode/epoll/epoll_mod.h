#ifndef _EPOLL_MOD_H
#define _EPOLL_MOD_H
#include<iostream>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cerrno>
#include <cstring>

#define MAXSLEEP 64
#define MAX_BUFFER_SIZE 4096
#define MAX_EXTERA_SIZE 65536
#define BACKLOG_SIZE 1024
#define MAX_EVENTS 1024
#define EPOLL_TIMEOUT -1

#define ERR_EXIT(msg) \
    do{ \
        perror(msg); \
        exit(EXIT_FAILURE); \
    } while(0)

class TCPSocket{
public:
    TCPSocket();//创建套接字
    virtual ~TCPSocket();//销毁套接字
    //客户端
    int Socket(int domain, int type, int protocol);
    int Connect(const struct sockaddr*, socklen_t addrlen);
    //服务器端
    int Bind(const struct sockaddr* addr, socklen_t addrlen);
    int Listen(int backlog);
    int Accept(struct sockaddr* addr, socklen_t* addrlen);
public:
    int Getsockname(struct sockaddr* localaddr, socklen_t* addrlen);//获取本地地址及端口
    bool SetSocketNonBlock(int connfd);//设置套接字非阻塞
    int Setsockopt();//设置地址端口复用
    int Getsockfd();//SOCKET handle获取函数
    int Read(int fd);//服务器集中读
private:
    int sockfd_;
};



class SocketEvent{
public:
    SocketEvent();//构造函数
    virtual ~SocketEvent();//析构函数
    int getEvents(int timeout);//epoll_wait
    bool eventAdd(int fd, bool readable, bool writeable);//EPOLL_CTL_ADD操作
    //struct epoll_event event[MAX_EVENTS];
    std::vector<struct epoll_event> event;
private:
    int epollfd_;
};

#endif
