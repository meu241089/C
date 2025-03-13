// 26

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8181

int main()
{
    int server, client, nByteReads;
    socklen_t addressLen;
    struct sockaddr_in srv, cli;
    char buffer[512];
    char *data;

    addressLen = 0;
    memset(&srv, 0, sizeof(srv));
    memset(&cli, 0, sizeof(cli));

    server = socket(AF_INET, SOCK_STREAM, 0);

    if (server < 0)
    {
        printf("socket()\n");
        return -1;
    }

    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = 0;
    srv.sin_port = htons(PORT);

    if (bind(server, (struct sockaddr *)&srv, sizeof(srv)))
    {
        printf("bind()\n");
        close(server);
        return -1;
    }

    if (listen(server, 5))
    {
        printf("isten()\n");
        close(server);
        return -1;
    }

    printf("Listeing on 0.0.0.0:%d\n", PORT);

    client = accept(server, (struct sockaddr *)&srv, &addressLen);
    if (client < 0)
    {
        printf("accept()\n");
        close(server);
        return -1;
    }

    printf("Client connected\n");
    nByteReads = read(client, buffer, 512);
    data = "http v1.0\n";

    write(client, data, strlen(data));
    write(1, buffer, nByteReads);

    close(client);
    close(server);

    return 0;
}

// dopo averlo avviato, per verificare se effettivamente è in ascolto (listening), digitare dal terminale:
// sudo netstat -an | grep LISTEN

// e

// sudo env - telnet localhost