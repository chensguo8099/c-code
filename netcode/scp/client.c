/**client**/
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

int Connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen){
	int nsec;
	for(nsec = 1; nsec <= MAXSLEEP; nsec <<= 1){
		if((connect(sockfd, addr, addrlen)) == 0){
			return 0;
			printf(">>connect failed");
			exit(1);
		}
		if(nsec <= MAXSLEEP/2)
			sleep(nsec);
	}
	return 1;
}

int main(int argc, char** argv){
	int sockfd, n;
	char buffer[BUF_SIZE];
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(53350);


	sockfd = Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	Connect(sockfd, (SA*)&servaddr, sizeof(servaddr));


	int fd = open("NEWmusic.mp3", O_RDWR|O_CREAT);
	while(n = recv(sockfd, buffer, BUF_SIZE, 0)){
		write(fd, buffer, n);
	}
	close(fd);
	exit(0);
}
