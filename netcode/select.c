#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#define SA struct sockaddr

int main(int argc, char *argv[]){
	if(argc <= 2){
		printf("usage:%sip_address port_number\n", basename(argv[0]));
		//basename()当向basename传递一个路径名，它会删除任何前缀，直到最后一个斜线'/'字符，然后返回结果。
		return 1;
	}

	const char* ip = argv[1];
	int port = atoi(argv[2]);//atoi将字符串转换为整形

	int ret = 0;
	struct sockaddr_in address;
	bzero(&address, sizeof(address));

	address.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &address.sin_addr);
	address.sin_port = htons(port);

	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	assert(listenfd >= 0);

	ret = bind(listenfd, (SA*)&address, sizeof(address));
	assert(ret != -1);

	ret = listen(listenfd, 5);
	assert(ret != -1);
	
	struct sockaddr_in client_address;
	socklen_t client_addrlength = sizeof(client_address);
	int connfd = accept(listenfd, (SA*)&client_address, &client_addrlength);

	if(connfd < 0){
		printf("errno is : %d\n", errno);
		close(listenfd);
	}

	char buf[1024];
	fd_set read_fds;
	fd_set exception_fds;
	FD_ZERO(&read_fds);
	FD_ZERO(&exception_fds);

	while(1){
		memset(buf, '\0', sizeof(buf));
		/*每次调用select前都要重新在read_fds和exception_fds中设置文件描述符connfd,因为事件发生之后，文件描述符集合将被内核修改*/
		FD_SET(connfd, &read_fds);
		FD_SET(connfd, &exception_fds);
		ret = select(connfd + 1, &read_fds, NULL, &exception_fds, NULL);
		//select(maxfdp1, fd_set *readset, fd_set *writeset, fd_set *exceptset,const struct timeval *timeout);
		if(ret < 0){
			printf("selection failure\n");
			break;
		}//<0error     =0timeout

		/*对于可读事件，采用普通的recv函数取数据*/
		if(FD_ISSET(connfd, &read_fds)){//FD_ISSET判断描述符connfd是否可读
			ret = recv(connfd, buf, sizeof(buf) - 1, 0);
			if(ret <= 0)
				break;
			printf("get %d bytes of normal data: %s\n", ret, buf);
		}
		/*对于异常事件，采用带MSG_OOB标志的recv函数读取带外数据*/
		//recv成功执行时，返回收到的字节数
		else if(FD_ISSET(connfd, &exception_fds)){
			ret = recv(connfd, buf, sizeof(buf) - 1, MSG_OOB);
			if(ret <= 0)
				break;
			printf("get %d bytes of oob data: %s\n", ret, buf);
		}
	}
	close(connfd);
	close(listenfd);
	return 0;
}
