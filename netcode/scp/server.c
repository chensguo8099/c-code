/**server**/
#include "unp.h"

int Socket(int domain, int type, int protocol){
	int sockfd;
	sockfd = socket(domain, type, protocol);
	if(sockfd < 0){
		printf(">>create socket failed");
		exit(1);
	}
	return sockfd;
}

int Bind(int sockfd, const const struct sockaddr* addr, socklen_t addrlen){
	if(bind(sockfd, addr, addrlen) < 0){
		printf(">>bind failed");
		exit(1);
	}
	return 1;
}

int Listen(int sockfd, int backlog){
	if(listen(sockfd, backlog) < 0){
		printf(">>listen failed");
		exit(1);
	}
	return 1;
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
	int connfd;
	if((connfd = accept(sockfd, addr, addrlen)) < 0){
		printf(">>accept failed");
		exit(1);
	}
	return connfd;
}

int main(int argc, char** argv){
	int sockfd, connfd, n;
	char buffer[BUF_SIZE];
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(53350);


	sockfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	Bind(sockfd, (SA*)&servaddr, sizeof(servaddr));
	Listen(sockfd, LISTENLINE);
	connfd = Accept(sockfd, (SA*)NULL, NULL);


	int fd = open("music.mp3", O_RDWR);
	while(n = read(fd, buffer, BUF_SIZE)){
		send(connfd, buffer, n, 0);
	}
	close(fd);
	exit(0);
}
