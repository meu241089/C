// 11

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *StringAppend(char *s1, char *s2)
{
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int size = length1 + length2 + 1;

    char *s = calloc(size, sizeof(char));
}

/*

s1 - "abc" - length1 = 3
a   b   c   \0  -> data
0   1   2   3   -> indexes

s2 - "wxyz" - length2 = 4
w   x   y   z   \0   -> data
0   1   2   3   4    -> indexes

*/

int main(void)
{
    char first[20] = "First";
    char second[10] = "Second";

    strcat(first, second);
    printf("String append: %s\n", first);

    return 0;
}