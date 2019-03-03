/*
    > File Name: client_tcp.c
    > Author: JerryChen
    > Created Time: 2019年02月28日 星期四 11时38分08秒
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char *argv[]){
    if(argc < 2){
        printf("./a.out port\n");
        exit(1);
    }
    int port = atoi(argv[1]);
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    int flag = fcntl(fd, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);

    struct sockaddr_in serv;
    memset(&serv, 0, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(port);
    //serv.sin_addr.s_addr = htonl();
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr.s_addr);//将127.0.0.1的网络字节序写入serv.sin_addr.s_addr;
    connect(fd, (struct sockaddr*)&serv, sizeof(serv));

    while(1){
        //send msg
        char buf[1024] = {0};
        printf("请输入要发送的字符串\n");
        fgets(buf, sizeof(buf), stdin);
        write(fd, buf, strlen(buf) + 1);//strlen而非sizeof
        int len = 0;
        while((len = read(fd, buf, sizeof(buf))) > 0){
            printf("recv buf: %s\n", buf);
        }
        if(len == -1){
            if(errno == EAGAIN){
                printf("读完\n");
            }
            else{
                perror("read error");
                exit(1);
            }
        }
        else if(len == 0){
            printf("服务器关闭了链接\n");
            break;
        }
    }
    close(fd);
    return 0;
}
