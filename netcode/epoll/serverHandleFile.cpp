#include "epoll_mod.h"

int main(){
    int connfd, i;
    struct sockaddr_in servaddr, localaddr;
    socklen_t addrlen = sizeof(localaddr);

    bzero(&servaddr, sizeof(servaddr));
    bzero(&localaddr, sizeof(localaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6066);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    //创建TCP对象
    TCPSocket tcpsocket;
    //建立socket
    tcpsocket.Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //设置地址和端口复用
    tcpsocket.Setsockopt();
    //设置socket套接字非阻塞
    if(!tcpsocket.SetSocketNonBlock(tcpsocket.Getsockfd()))
        ERR_EXIT("setSocketNonblock");
    //绑定套接字
    tcpsocket.Bind((struct sockaddr *)&servaddr, sizeof(servaddr));
    //监听
    tcpsocket.Listen(BACKLOG_SIZE);


    //创建EPOLL对象
    SocketEvent sockevent;
    //sockevent.event.push_back();

    sockevent.event.resize(MAX_EVENTS);

    //将listenfd加入事件EPOLLIN列表
    sockevent.eventAdd(tcpsocket.Getsockfd(), true, false);
    for(;;){
        int nfds = sockevent.getEvents(EPOLL_TIMEOUT);//epoll_wait

        for(std::vector<epoll_event>::iterator iter = sockevent.event.begin(); iter != sockevent.event.end(); ++iter){

            //创建一个sockfd，该sockfd与TCP类中的sockfd_不一样
            int sockfd = (*iter).data.fd;
            if(sockfd < 0) continue;
            //处理新连接
            if((*iter).data.fd == tcpsocket.Getsockfd()){
                while((connfd = tcpsocket.Accept((struct sockaddr*)&localaddr, &addrlen)) > 0){
                    tcpsocket.SetSocketNonBlock(connfd);
                    std::cout << "远程连入地址>> " << inet_ntoa(localaddr.sin_addr)
                            << "  远程连入端口>> " << ntohs(localaddr.sin_port) << std::endl;

                    sockevent.eventAdd(connfd, true, false);
                }
            }
            else if((*iter).events & EPOLLIN) {
                int total_read_size = tcpsocket.Read(sockfd);
                if(total_read_size == 0){
                    close(sockfd);
                    std::cout << "远程地址主机>> " << inet_ntoa(localaddr.sin_addr)
                            << "  远程主机端口>> " << ntohs(localaddr.sin_port)
                            << " 的主机关闭"  << std::endl;
                    continue;
                }
                std::cout << "read size is " << total_read_size << std::endl;
            }
        }
    }
    return 0;
}
