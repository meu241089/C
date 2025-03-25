// 21

/*
Malloc --> Dinamic Memory Allocation
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char name[32]; // static memory allocation

    char *name;

    name = malloc(32);

    printf("What is your name?\n");
    // scanf("%s", &name);
    scanf("%s", name);

    /*
        With pointers and malloc, the input value of scanf doesn't required a &
    */

    printf("Hello %s\n", name);

    free(name);

    return 0;
}