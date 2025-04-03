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

    for (int i = 0; i < length1; i++)
        s[i] = s1[i];

    for (int i = 0; i < length2; i++)
        s[length1 + i] = s2[i];

    s[size - 1] = '\0';

    return s;
}

/*

s1 - "abc" - length1 = 3
a   b   c   \0  -> data
0   1   2   3   -> indexes

s2 - "wxyz" - length2 = 4
w   x   y   z   \0   -> data
0   1   2   3   4    -> indexes

s
a   b   c   w   x   y   z   \0
0   1   2   3   4   5   6   7   -> indexes

*/

int main(void)
{
    char first[20] = "First";
    char second[10] = "Second";

    strcat(first, second);
    printf("String append: %s\n", first);

    char s1[] = "abc";
    char s2[] = "wxyz";

    char *s = StringAppend(s1, s2);

    printf("String append: %s\n", s);
    free(s);

    return 0;
}