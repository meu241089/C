// 5

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool IsPalindrome(char string[])
{
    int middle = strlen(string) / 2;

    int lenght = strlen(string);

    for (int i = 0; i < middle; i++)
        if (string[i] != string[lenght - i - 1])
            return false;
}

void PrintResult(char string[])
{
    if (IsPalindrome(string) == true)
        printf("%s - Is a palindrome!\n", string);
    else
        printf("%s - Is not a palindrome!\n", string);
}

int main(void)
{

    char string1[] = "Not a palindrome!";
    char string2[] = "abccba";
    char string3[] = "abcdcba";

    PrintResult(string1);
    PrintResult(string2);
    PrintResult(string3);

    return 0;
}