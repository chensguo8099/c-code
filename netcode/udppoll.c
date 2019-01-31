#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#define SA struct sockaddr

int main(int argc, char *argv[]){
	int udpfd = 0;
	//UDP文件描述符
	int ret = 0;
	struct pollfd fds[2];
	//监测文件描述结构体数组：2个
	struct sockaddr_in saddr;
	struct sockaddr_in caddr;

	bzero(&saddr, sizeof(saddr));
	bzero(&caddr, sizeof(caddr));
	//为客户端和服务器socket结构体清零

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(8000);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//服务器通讯协议族AF_INET 端口8099
	//sockaddr_in结构体中有sin_addr结构体，这个结构体中有变量s_addr
	//s_addr设为INADDR_ANY表示服务器可以和任何主机通信

	caddr.sin_family = AF_INET;
	caddr.sin_port = htons(8000);
	//客户端信息初始化

	if((udpfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("socket error");
		exit(-1);
	}
	//创建套接字

	if(bind(udpfd, (SA *)&saddr, sizeof(saddr)) < 0){
		perror("bind error");
		close(udpfd);
		exit(-1);
	}
	//绑定端口
	printf("input : \"sayto 192.168.220.X\" to sendmsg to somebody\n");
	fds[0].fd = 0; //标准输入描述符
	fds[1].fd = udpfd; //udp描述符

	fds[0].events = POLLIN;
	fds[1].events = POLLIN;
	//给这两个描述符分别赋予 普通或优先级带数据可读

	while(1){
		//监视并等待多个文件（标准输入，udp套接字）描述符的属性变化（是否可读）
		//没有属性变化，这个函数会阻塞，直到有变化才往下执行，这里没有设置超时
		ret = poll(fds, 2, -1);
		write(1, "UdpQQ", 6);

		if(-1 == ret)
			perror("poll error");
			//出错
		else if(ret > 0){ //准备就绪的文件描述符
			char buf[100] = {0};

			if((fds[0].revents & POLLIN) == POLLIN){ //标准输入??????????
				fgets(buf, sizeof(buf), stdin);
				buf[strlen(buf) - 1] = '\0';

				if(strncmp(buf, "sayto", 5) == 0){
					char ipbuf[16] = "";
					inet_pton(AF_INET, buf+6, &caddr.sin_addr);
					//将buf+6后面的值赋给caddr.sin_addr
					printf("\rsay to %s\n", inet_ntop(AF_INET, &caddr.sin_addr, ipbuf, sizeof(ipbuf)));
					continue;
				}//输入sayto+IP可以让本地客户端写入要连接的目标IP

				else if(strcmp(buf, "exit") == 0){
					close(udpfd);
					exit(0);
				}//输入exit退出传输
			}
			//fds[0]中的文件描述符执行完毕


			else if((fds[1].revents & POLLIN) == POLLIN){
				struct sockaddr_in addr;
				char ipbuf[INET_ADDRSTRLEN] = "";
				socklen_t addrlen = sizeof(addr); //????????????????

				bzero(&addr, sizeof(addr));

				recvfrom(udpfd, buf, 100, 0, (SA*)&addr, &addrlen);
				printf("[%s] : %s\n", inet_ntop(AF_INET, &addr.sin_addr, ipbuf, sizeof(ipbuf)), buf);
			}
		}

		else if(0 == ret)
			printf("time out\n");
	}
	return 0;
}
