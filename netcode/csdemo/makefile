all : server client
	gcc -o server server.o
	gcc -o client client.o

server.o : server.c
	gcc -c server.c

client.o : client.c
	gcc -c client.c

clean : 
	rm -fr client.o server.o client server
