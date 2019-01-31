#ifndef __unp_h
#define __unp_h

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>

#ifndef HAVE_BZERO
#define bzero(ptr, n) memset(ptr, 0, n)
#endif  //bzero

#define SA struct sockaddr
#define BUF_SIZE 2048
#define MAXSLEEP 128
#define LISTENLINE 20

int Socket(int domain, int type, int protocol);
/*server*/
int Bind(int sockfd, const const struct sockaddr* addr, socklen_t addrlen);
int Listen(int sockfd, int backlog);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

/*client*/
int Connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
#endif
