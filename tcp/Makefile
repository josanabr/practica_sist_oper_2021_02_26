all: tcp.o server client

tcp.o:
	gcc -c tcp.c

server: tcp.o
	gcc server.c -o server tcp.o

client: tcp.o
	gcc client.c -o client tcp.o

clean:
	rm -f tcp.o server client
