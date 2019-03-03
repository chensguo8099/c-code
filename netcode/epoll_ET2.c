/*
    > File Name: epoll_tcp.c
    > Author: JerryChen
    > Created Time: 2019年03月03日 星期日 12时04分57秒
*/
//客户端给服务器发送数据，发一次数据 server的epoll_wait返回一次，不在乎数据是否读完
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]){

    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(lfd < 0){
        perror("socket");
        exit(1);
    }
    socklen_t len = sizeof(struct sockaddr_in);
    struct sockaddr_in serv;
    struct sockaddr_in cli;
    memset(&serv, 0, sizeof(serv));
    memset(&cli, 0, sizeof(cli));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(9999);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);
    bind(lfd, (struct sockaddr *)&serv, len);
    listen(lfd, 128);
    
    int efd = epoll_create(3000);
    struct epoll_event all[3000];
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = lfd;
    epoll_ctl(efd, EPOLL_CTL_ADD, lfd, &ev);
    int i;
    while(1){
        int ret = epoll_wait(efd, all, sizeof(all)/sizeof(all[0]), -1);
        printf("------------epoll_wait---------------\n");
        for(i = 0; i < ret; ++i){
            int fd = all[i].data.fd;
            //有新连接
            if(fd == lfd){
                //接收连接请求
                int cfd = accept(lfd, (struct sockaddr *)&cli, &len);
                if(cfd == -1){
                    perror("accept");
                    exit(1);
                }
                //设置非阻塞
                int flag = fcntl(cfd, F_GETFL);
                flag |= O_NONBLOCK;
                fcntl(cfd, F_SETFL, flag);
                //注册新连接至红黑树
                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = cfd;
                epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &ev);
                char ip[16];
                printf("New client IP:%s, PORT:%d\n", inet_ntop(AF_INET, &cli.sin_addr.s_addr, ip, sizeof(ip)), ntohs(cli.sin_port));
            }
            else{//已连接客户端有新数据
                if(!(all[i].events & EPOLLIN))
                    continue;

                char buf[5] = {0};
                int readlen;
                while((readlen = recv(fd, buf, sizeof(buf), 0)) > 0){
                    printf("11111111111111111111111111\n");
                    //数据打印至终端
                    write(STDOUT_FILENO, buf, readlen);
                    //发送给客户端
                    //write(fd, buf, strlen(buf) + 1);
                    send(fd, buf, readlen, 0);
                }
                if(readlen == 0){
                    printf("client is closed\n");
                    int epoll_ret = epoll_ctl(efd, EPOLL_CTL_DEL, all[i].data.fd, NULL);
                    if(epoll_ret < 0){
                        perror("epoll_ctl");
                        exit(1);
                    }
                    close(fd);
                }
                else if(readlen == -1){
                    if(errno == EAGAIN){
                        printf("缓冲区已经读完\n");
                    }
                    else{
                        printf("recv error\n");
                        exit(1);
                    }
                }
                #if 0
                if(readlen == -1){
                    perror("recv");
                    exit(1);
                }else if(readlen == 0){
                    printf("client closed\n");
                    close(fd);
                    epoll_ctl(efd, EPOLL_CTL_DEL, all[i].data.fd, NULL);
                }else{
                    write(STDOUT_FILENO, buf, strlen(buf) + 1);
                    //不用printf是因为其为标准C库函数 有自己的缓冲区
                    //当使用边沿触发时本来大于buf的数据，无法被全部获取，但是printf因为在buf内未读取到数据 则把读到的数据暂存至自己缓冲区
                    //达不到ET的效果
                }
                //send(lfd, buf + 1, readlen, 0);
                write(fd, buf, strlen(buf) + 1);
                #endif
            }
        }
    }
    close(lfd);
    return 0;
}
