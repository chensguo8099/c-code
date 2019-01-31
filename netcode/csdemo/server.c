#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>//bzero
#include <sys/types.h>
#include <sys/socket.h>

//socket bind listen accept

int main(){
	struct sockaddr_in servaddr;//服务器自己的连接信息
	struct sockaddr_in cliaddr;//客户端连接信息

	bzero(&servaddr, 0);
	bzero(&cliaddr, 0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(-1);//服务器监听的端口
	servaddr.sin_addr.s_addr = INADDR_ANY;//转换过来就是0.0.0.0，也表示本地IP

	int sockfd;
	if((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) //sockfd == -1 error
	{
		perror("socket");
		exit(1);
	}
	//-1 error 0 success
	if((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr))) < 0)
	{
		perror("bind");
		exit(1);
	}

//完全连接队列大小 min(backlog, /proc/sys/net/core/somaxconn) somaxconn默认为128
	int backlog = 20;//能够同时接收没有accept的连接
	if(listen(sockfd, backlog) < 0)
	{
		perror("listen");
		exit(1);
	}
//----------三握手结束监听并等待连接--------------
	int newfd;
	int acceptSize = sizeof(struct sockaddr);

	char sendbuf[1024];
	char recvbuf[1024];
	bzero(sendbuf, 0);
	bzero(recvbuf, 0);
	int recvnum;//recv函数的返回值
	int sendnum;//send函数的返回值
	while(1)
	{
//accept回填client的port ip
//accept(sockfd, (struct sockaddr*)NULL, NULL);
		if((newfd = accept(sockfd, (struct sockaddr*)&cliaddr, &acceptSize)) < 0)
		{
			perror("accept");
			continue;
		}
		printf("server connect with %s successfully\n", inet_ntoa(cliaddr.sin_addr));
//cliaddr.sin_addr是accept连接后服务器回填的
//inet_ntoa(填写结构体sin_addr)

		pid_t pid = fork();
		while(1)
		{
			if(pid == 0)
			{
//服务器端发送数据
				scanf("%s", sendbuf);
				if((sendnum = send(newfd, sendbuf, strlen(sendbuf), 0)) < 0)
				{
					perror("serv send");
					exit(1);
				}
			}
			if(pid > 0)
			{
				if((recvnum = recv(newfd, recvbuf, sizeof(recvbuf), 0)) < 0)
				{
					perror("serv recv");
					exit(1);
				}
				recvbuf[recvnum] = '\0';
		  		printf("server recv : :%s\n", recvbuf);
		    }
		}
		close(newfd);
	}
	close(sockfd);
}
