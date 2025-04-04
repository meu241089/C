// 16

#include <stdio.h>

int main()
{
    goto start;

start:
    printf("Infinite loop\n");
    goto start;

    return 0;
}