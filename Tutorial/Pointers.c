// 14

#include <stdio.h>
#include <string.h>

int main()
{
    char str[32];
    char *pointer;

    strncpy(str, "I like apples", 31);

    pointer = str;

    printf("%s\n", pointer);

    pointer++;

    printf("%s\n", pointer);

    pointer--;

    printf("%c\n", *pointer);

    return 0;
}