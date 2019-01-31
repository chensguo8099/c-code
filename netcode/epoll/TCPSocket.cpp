#include "epoll_mod.h"

SocketEvent::SocketEvent(){
    if((epollfd_ = epoll_create1(0)) < 0){
        std::cout << "create epoll handle error!" << std::endl;
        return;
    }
    bzero(event.data(), sizeof(struct epoll_event)*event.size());
}


SocketEvent::~SocketEvent(){
    if(epollfd_ > 0){
        close(epollfd_);
        epollfd_ = -1;
    }
}


bool SocketEvent::eventAdd(int fd, bool readable, bool writeable){
    struct epoll_event ev;

    bzero(&ev, sizeof(epoll_event));
    ev.events |= EPOLLET;//设置事件为ET触发模式

    if(readable){
        ev.events |= EPOLLIN;
    }
    if(writeable){
        ev.events |= EPOLLOUT;
    }
    ev.data.fd = fd;

    if(epoll_ctl(epollfd_, EPOLL_CTL_ADD, fd, &ev) == -1)
        ERR_EXIT("epoll_ctl");
    return true;
}



int SocketEvent::getEvents(int timeout){
    int nfds;
    if((nfds = epoll_wait(epollfd_, event.data(), event.size(), timeout)) < 0)
        ERR_EXIT("epoll_wait");
    return nfds;
}


//设置非阻塞
bool TCPSocket::SetSocketNonBlock(int sockFd){
    int opt = fcntl(sockFd, F_GETFL);
    if(opt < 0){
        std::cout << "set nonblock failed!!!" << std::endl;
        return false;		
    }
    opt = opt | O_NONBLOCK;
    if(fcntl(sockFd, F_SETFL, opt) < 0){
        std::cout << "set nonblock failed!!!" << std::endl;
        return false;
    }
    return true;
}



//绑定地址信息
int TCPSocket::Bind(const struct sockaddr* addr, socklen_t addrlen){
    if(bind(sockfd_, addr, addrlen) < 0)
        ERR_EXIT("bind");
    return 1;
}


//监听
int TCPSocket::Listen(int backlog){
    if(listen(sockfd_, backlog) < 0)
        ERR_EXIT("listen");
    return 1;
}


//接收连接请求
int TCPSocket::Accept(struct sockaddr* addr, socklen_t* addrlen){
    int connfd;
    if((connfd = accept(sockfd_, addr, addrlen)) < 0){
        if(errno != EAGAIN && errno != ECONNRESET && errno != EPROTO && errno != EINTR)
            ERR_EXIT("accept");
    }
    return connfd;
}


int TCPSocket::Read(int sockfd){
    ssize_t read_size;
    ssize_t total_read_size = 0;
    char buffer[MAX_BUFFER_SIZE] = {'\0'};
    char extera[MAX_EXTERA_SIZE] = {'\0'};

    int fd;
    if((fd = open("NEWfile", O_RDWR | O_CREAT | O_APPEND)) < 0)
        ERR_EXIT("open fd");
    struct iovec vec[2];
    vec[0].iov_base = buffer;
    vec[0].iov_len = MAX_BUFFER_SIZE;

    vec[1].iov_base = extera;
    vec[1].iov_len = MAX_BUFFER_SIZE;

    while((read_size = readv(sockfd, vec, 2)) > 0){
        if(read_size <= MAX_BUFFER_SIZE)
            write(fd, buffer, (size_t)read_size);
        else if(read_size > MAX_BUFFER_SIZE){
            write(fd, buffer, MAX_BUFFER_SIZE);
            write(fd, extera, (size_t)read_size - MAX_BUFFER_SIZE);
        }
        total_read_size += read_size;
    }
    return total_read_size;
}



int TCPSocket::Setsockopt(){
    int yes = 1;
    //设置端口复用
    if(setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(yes)))
        ERR_EXIT("setsockopt port");
    //设置地址复用
    if(setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)))
        ERR_EXIT("setsockpot ip");
}



TCPSocket::TCPSocket():sockfd_(-1){}

TCPSocket::~TCPSocket(){
    close(sockfd_);
}


int TCPSocket::Socket(int domain, int type, int protocol){
    sockfd_ = socket(domain, type, protocol);
    if(sockfd_ < 0){
        ERR_EXIT("socket");
    }
    return sockfd_;
}


int TCPSocket::Connect(const struct sockaddr* addr, socklen_t addrlen){
    int nsec;

    for(nsec = 1; nsec <= MAXSLEEP; nsec <<= 1){
        if((connect(sockfd_, addr, addrlen)) == 0){
            return 0;//connection accepted
        }

        //sleep nsec then connect retry
        if(nsec <= MAXSLEEP/2)
            sleep(nsec);
    }
    ERR_EXIT("connect");
}


int TCPSocket::Getsockname(struct sockaddr* localaddr, socklen_t* addrlen){
    if(getsockname(sockfd_, &(*localaddr), &(*addrlen)) < 0)
        ERR_EXIT("getsockname");
    return 1;
}



int TCPSocket::Getsockfd(){
    int sockfd = this->sockfd_;
    return sockfd;
}
