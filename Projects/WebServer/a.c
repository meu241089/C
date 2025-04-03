#include <stdio.h>
#include <unistd.h>

int main()
{

    char *data;

    data = "Shall I compare thee to a summers's day?\n";

    write(1, data, 512);

    return 0;
}