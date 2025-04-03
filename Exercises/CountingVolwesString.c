// 10

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int VowelCount(char *string)
{
    int count = 0;

    for (int i = 0; i < strlen(string); i++)
    {
        switch (toupper(string[i]))
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            count++;
        }
    }

    return count;
}

int main(void)
{
    char string[] = "It's a wonderful life!";

    int count = VowelCount(string);

    printf("Vowel count: %d\n", count);

    return 0;
}
