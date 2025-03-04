// 25

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define IP "142.251.209.35" /*www.google.it*/
#define PORT 80             /*http*/

int main()
{
    int server;
    struct sockaddr_in sock;
    char buffer[512];
    const char *data;

    data = "HEAD / HTTP/1.0\r\n\r\n";

    server = socket(AF_INET, SOCK_STREAM, 0);

    if (server < 0)
    {
        printf("socket() error\n");
        return -1;
    }
 
    sock.sin_addr.s_addr = inet_addr(IP);
    sock.sin_port = htons(PORT);
    sock.sin_family = AF_INET;

    if (connect(server, (struct sockaddr *)&sock, sizeof(struct sockaddr_in)) != 0)
    {
        printf("connect() error\n");
        close(server);

        return -1;
    }

    write(server, data, strlen(data));
    memset(buffer, 0, 512);

    read(server, buffer, 511);
    close(server);

    printf("\n%s\n", buffer);

    return 0;
}

// shortcut --> ctrl + shift + i --> format code
// terminal --> strace -f -/Sockets.out --> debug