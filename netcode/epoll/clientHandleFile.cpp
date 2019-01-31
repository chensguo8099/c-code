#include "epoll_mod.h"

int main(){
    char buffer[MAX_BUFFER_SIZE];
    ssize_t readn;
    struct sockaddr_in servaddr, localaddr;
    socklen_t addrlen = sizeof(localaddr);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6066);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");


    TCPSocket tcpsocket;
    //build socket
    tcpsocket.Socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    //connect
    tcpsocket.Connect((struct sockaddr*)&servaddr, sizeof(servaddr));


    tcpsocket.Getsockname((struct sockaddr*)&localaddr, &addrlen);

    std::cout << "本机IP>> "   << inet_ntoa(localaddr.sin_addr)
              << "本机端口>> " << ntohs(localaddr.sin_port) << std::endl;

    int fd = open("testdata", O_RDWR);
    while(readn = ::read(fd, buffer, MAX_BUFFER_SIZE)){
        ::send(tcpsocket.Getsockfd(), buffer, readn, 0);
    }

    while(::read(tcpsocket.Getsockfd(),buffer,MAX_BUFFER_SIZE) > 0){}

    return 0;
}
