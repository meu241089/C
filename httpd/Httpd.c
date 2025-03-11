// 27

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// #define ListenAddress "0.0.0.0"
#define ListenAddress "127.0.0.1"

/* global */
char *error; // static text wich is saved in a special part of the memory called BSS and it's available for all functions

/*returns 0 on error, or it return a socked fd*/
int ServerInit(int portNumber)
{
    int sock;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) // value = -1 equals an error
    {
        error = "socket() error";
        return 0;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ListenAddress);
    server.sin_port = htons(portNumber);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)))
    {
        close(sock);
        error = "bind() error";
        return 0;
    }

    if (listen(sock, 5))
    {
        close(sock);
        error = "listen() error";
        return 0;
    }

    return sock;
}

int main(int argc, char *argv[])
{
    int socketFileDescriptor;
    char *portNumber;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <listening port>\n", argv[0]);
        return -1;
    }
    else
    {
        portNumber = argv[1];
    }

    socketFileDescriptor = ServerInit(atoi(portNumber)); // atoi --> ASCII to integer

    if (!socketFileDescriptor)
    {
        fprintf(stderr, "%s\n", error);
        return -1;
    }

     while(1)
     {
        
     }
}
