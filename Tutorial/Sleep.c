// 9

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Wait while processing...");
    fflush(stdout);
    sleep(2); // in seconds

    printf("Ok\n");

    return 0;
}
