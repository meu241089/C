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

/* structures */

struct structHttpRequest
{
    char method[8];
    char url[128];
};

typedef struct structHttpRequest httpReq;

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

/* returns 0 on error, or returns the new client's socket file descriptor */
int ClientAccept(int socketFileDescriptor)
{
    int c;
    socklen_t addressLength;
    struct sockaddr_in cli;

    memset(&cli, 0, sizeof(cli));
    c = accept(socketFileDescriptor, (struct sockaddr *)&cli, &addressLength);

    if (c < 0)
    {
        error = "accept() error";
        return 0;
    }
    return 0;
}

/* returns 0 on error, or it returns a httpreq structure*/
httpReq *ParseHttp(char *str)
{
}

void ClientConnection(int serverSocketFileDescriptor, int clientSocketFileDescriptor)
{

    return;
}

int main(int argc, char *argv[])
{
    int socketFileDescriptor, client;
    char *portNumber;
    char *template;
    httpReq *req;

    template = "GET / HTTP/1.1\n"
               "Host : 127.0.0.1 : 8181\n"
               "Upgrade-Insecure-Requests: 1\n"
               "User - Agent : Mozilla / 5.0(X11; Ubuntu; Linux x86_64; rv : 136.0)Gecko / 20100101 Firefox / 136.0 \n"
               "Accept : text / html, application / xhtml + xml, application / xml; q = 0.9, * /*;q=0.8\n"
               "Accept-Language: it-IT,it;q=0.8,en-US;q=0.5,en;q=0.3\n"
               "Accept-Encoding: gzip, deflate, br, zstd\n"
               "Connection: keep-alive\n"
               "\n";

    req = ParseHttp(template);

    printf("Method: '%s'\n URL: '%s'\n", req->method, req->url);

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

    printf("Listening on %s:%s\n", ListenAddress, portNumber);

    while (1)
    {
        client = ClientAccept(socketFileDescriptor);
        if (!client)
        {
            fprintf(stderr, "%s\n", error);
            continue;
        }

        printf("Incoming connection\n");

        if (!fork())
        {
            ClientConnection(socketFileDescriptor, client);
        }

        /*fork does create a copy of your program so it runs in two instances from here on and forward

        for the main process: return the new process id

        for the new process: return 0

        */
    }
    return -1;
}
