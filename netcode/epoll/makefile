main: server client
.PHONY : clean

server : serverHandleFile.o TCPSocket.o
	g++ -std=c++11 -o server serverHandleFile.o TCPSocket.o

client : clientHandleFile.o TCPSocket.o
	g++ -std=c++11 -o client clientHandleFile.o TCPSocket.o

serverHandleFile.o : serverHandleFile.cpp
	g++ -c -std=c++11 serverHandleFile.cpp

clientHandleFile.o : clientHandleFile.cpp
	g++ -c -std=c++11 clientHandleFile.cpp

TCPSocket.o : TCPSocket.cpp
	g++ -c -std=c++11 TCPSocket.cpp

clean :
	rm TCPSocket.o serverHandleFile.o clientHandleFile.o server client

