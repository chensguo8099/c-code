#include "unp.h"

char* transform(char *tmp, int n){
	int i;
	for(i=0; i<n; i++){
		if(tmp[i] >= 'a' && tmp[i] <= 'z')
			tmp[i] -= 32;
		else if(tmp[i] >= 'A' && tmp[i] <= 'Z')
			tmp[i] += 32;
	}
	return tmp;
}

void str_echo(int sockfd){
	ssize_t n;
	char buf[MAXLINE];
	char *tmp;
	int i = 0;
again:
	while((n = read(sockfd, buf, MAXLINE)) > 0){
		tmp = transform(buf, n);
		Writen(sockfd, tmp, n);
		bzero(tmp, sizeof(buf));
	}
	if(n < 0 && errno == EINTR)
		goto again;
	else if(n < 0)
		err_sys("str_echo: read error");
}
