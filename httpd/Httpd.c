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

struct structFile
{
    char fileName[64];
    char *fileContents;
    int size;
};

typedef struct structFile File;

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

    addressLength = 0;

    memset(&cli, 0, sizeof(cli));

    c = accept(socketFileDescriptor, (struct sockaddr *)&cli, &addressLength);

    if (c < 0)
    {
        error = "accept() error";
        return 0;
    }
    return c;
}

/* returns 0 on error, or it returns a httpreq structure*/
httpReq *ParseHttp(char *str)
{
    httpReq *req;
    char *pointer;

    req = malloc(sizeof(httpReq));
    // memset(&req, 0, sizeof(httpReq)); ERRORE

    for (pointer = str; *pointer && *pointer != ' '; pointer++)
        ;
    if (*pointer == ' ')
    {
        *pointer = 0;
    }
    else
    {
        error = "parseHttp() NOSPACE error";
        free(req);
        return 0;
    }

    strncpy(req->method, str, 7); // method [8]

    for (str = ++pointer; *pointer && *pointer != ' '; pointer++)
        ;
    if (*pointer == ' ')
    {
        *pointer = 0;
    }
    else
    {
        error = "parseHttp() 2ND SPACE error";
        free(req);
        return 0;
    }

    strncpy(req->url, str, 127); // url [128]
    return req;
}

/* return 0 on error, or return the data */
char *ClientRead(int clientSocketFileDescriptor)
{
    static char buffer[512];

    memset(buffer, 0, 512);

    if (read(clientSocketFileDescriptor, buffer, 511) < 0)
    {
        error = "read() error";
        return 0;
    }
    else
    {
        return buffer;
    }
}

void HttpHeaders(int clientSocketFileDescriptor, int code)
{
    char buffer[512];
    int number;

    memset(buffer, 0, 512);
    snprintf(buffer, 511, "HTTP/1.0 %d OK\n"
                          "Server: httpd.c\n"
                          "Cache-Control: no-store, no-cache, max-age=0, private\n"
                          "Content-Type: text/html;\n"
                          "Content-Language: en\n"
                          "Expires: -1\n"
                          "X-Frame-Options: SAMEORIGIN\n",
             code);

    number = strlen(buffer);
    write(clientSocketFileDescriptor, buffer, number);

    return;
}

void HttpResponse(int clientSocketFileDescriptor, char *contentType, char *data)
{
    char buffer[512];
    int number;

    number = strlen(data);

    /* if size is true, then size else strlen(data)*/

    memset(buffer, 0, 512);
    snprintf(buffer, 511, "Content-Type: %s;\n"
                          "Content-Length: %d\n"
                          "\n%s\n",
             contentType, number, data);

    number = strlen(buffer);
    write(clientSocketFileDescriptor, buffer, number);

    return;
}

/* 1 = everything okay, 0 on error */

int SendFile(int clientSocketFileDescriptor, char *contentType, File *file)
{
    char buffer[512];
    char *pointer;

    int number, x;

    if (!file)
        return 0;

    memset(buffer, 0, 512);
    snprintf(buffer, 511, "Content-Type: %s;\n"
                          "Content-Length: %d\n",
             contentType, file->size);

    number = file->size;
    pointer = file->fileContents;

    while (1)
    {
        x = write(clientSocketFileDescriptor, pointer, (number < 512) ? number : 512);

        if (x < 1)
            return 0;

        number -= x;

        if (number < 1)
            break;
        else
            pointer += x;
    }

    return 1;
}

void ClientConnection(int serverSocketFileDescriptor, int clientSocketFileDescriptor)
{
    httpReq *req;
    char *pointer;
    char *res;

    pointer = ClientRead(clientSocketFileDescriptor);

    if (!pointer)
    {
        fprintf(stderr, "%s\n", error);
        close(clientSocketFileDescriptor);
        return;
    }

    req = ParseHttp(pointer);

    if (!req)
    {
        fprintf(stderr, "%s\n", error);
        close(clientSocketFileDescriptor);
        return;
    }

    if (!strcmp(req->method, "GET") && !strcmp(req->url, "/img>/", 5))
    {
    }

    if (!strcmp(req->method, "GET") && !strcmp(req->url, "/app/webpage"))
    {
        res = "<html>Hello world!</html>";
        HttpHeaders(clientSocketFileDescriptor, 200); // 200 = everything okay
        HttpResponse(clientSocketFileDescriptor, "text/html", res);
    }
    else
    {
        res = "File not found";
        HttpHeaders(clientSocketFileDescriptor, 404); // 404 = file not found
        HttpResponse(clientSocketFileDescriptor, "text/plain", res);
    }

    free(req);
    close(clientSocketFileDescriptor);

    return;
}

int main(int argc, char *argv[])
{
    int socketFileDescriptor, clientFileDescriptor;
    char *portNumber;

    // char *template;
    // httpReq *req;
    // char buffer[512];

    // template = "GET /Ciaone HTTP/1.1\n"
    //            "Host : 127.0.0.1 : 8181\n"
    //            "Upgrade-Insecure-Requests: 1\n"
    //            "User - Agent : Mozilla / 5.0(X11; Ubuntu; Linux x86_64; rv : 136.0)Gecko / 20100101 Firefox / 136.0 \n"
    //            "Accept : text / html, application / xhtml + xml, application / xml; q = 0.9, * /*;q=0.8\n"
    //            "Accept-Language: it-IT,it;q=0.8,en-US;q=0.5,en;q=0.3\n"
    //            "Accept-Encoding: gzip, deflate, br, zstd\n"
    //            "Connection: keep-alive\n"
    //            "\n";

    // memset(buffer, 0, 512);
    // strncpy(buffer, template, 511);

    // req = ParseHttp(buffer);

    // if (!req)
    //     fprintf(stderr, "%s\n", error);
    // else
    //     printf("Method: '%s'\n URL: '%s'\n", req->method, req->url);

    // free(req);

    // return 0;

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
        clientFileDescriptor = ClientAccept(socketFileDescriptor);

        if (!clientFileDescriptor)
        {
            fprintf(stderr, "%s\n", error);
            continue;
        }

        printf("Incoming connection\n");

        if (!fork())
        {
            ClientConnection(socketFileDescriptor, clientFileDescriptor);
        }

        /*fork does create a copy of your program so it runs in two instances from here on and forward

        for the main process: return the new process id

        for the new process: return 0

        */
    }
    return -1;
}
