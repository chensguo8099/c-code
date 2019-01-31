#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
/*客户端只需要填写服务器端信息即可*/

// socket connect
int main(char argc, char **argv){
	struct sockaddr_in servaddr;
	bzero(&servaddr, 0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(-1);//服务器端口为argv[1] 客户端端口是内核分配的，无需关心
	servaddr.sin_addr.s_addr = INADDR_ANY;

	int sockfd;
	if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		perror("socket");
		exit(1);
	}
	if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("connect");
		exit(1);
	}
	printf("client connect successful with %s\n", inet_ntoa(servaddr.sin_addr));
//-----------------建立连接-----------------
	char sendbuf[1024];
	char recvbuf[1024];
	bzero(sendbuf, 0);
	bzero(recvbuf, 0);
	int recvnum;//recv函数的返回值
	int sendnum;//send函数的返回值

	pid_t pid = fork();
	while(1)
	{
//客户端接收数据
		if(pid == 0)
		{
			if((recvnum = recv(sockfd, recvbuf, sizeof(recvbuf), 0)) < 0)
			{
				perror("client recv");
				exit(1);
			}
			recvbuf[recvnum] = '\0';
			printf("client recv : %s\n", recvbuf);
		}
		if(pid > 0)
		{
			scanf("%s", sendbuf);
			if((sendnum = send(sockfd, sendbuf, strlen(sendbuf), 0)) < 0)
			{
				perror("client send");
				exit(1);
			}
		}
	}
	close(sockfd);
}
