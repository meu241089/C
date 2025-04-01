#include <stdio.h>
#include <string.h>

// Function to find xor of two bits represented as character.
char xorChar(char a, char b)
{
    return (a == b) ? '0' : '1';
}

// Function to flip a bit represented as character.
char flip(char c)
{
    return (c == '0') ? '1' : '0';
}

// function to convert binary string to gray string
void binToGrey(const char *binary, char *gray)
{
    // MSB of gray code is same as binary code
    gray[0] = binary[0];

    // Compute remaining bits
    for (int i = 1; i < strlen(binary); i++)
    {
        // Concatenate XOR of previous bit with current bit
        gray[i] = xorChar(binary[i - 1], binary[i]);
    }
    gray[strlen(binary)] = '\0'; // Null-terminate the string
}

// function to convert gray code string to binary string
void greyToBin(const char *gray, char *binary)
{
    // MSB of binary code is same as gray code
    binary[0] = gray[0];

    // Compute remaining bits
    for (int i = 1; i < strlen(gray); i++)
    {
        // If current bit is 0, concatenate previous bit
        if (gray[i] == '0')
            binary[i] = binary[i - 1];
        // Else, concatenate invert of previous bit
        else
            binary[i] = flip(binary[i - 1]);
    }
    binary[strlen(gray)] = '\0'; // Null-terminate the string
}

int main()
{
    char binary[] = "01001";
    char gray[6]; // Length of binary + 1 for null terminator
    binToGrey(binary, gray);
    printf("%s\n", gray);

    char grayInput[] = "01101";
    char binaryOutput[6]; // Length of gray + 1 for null terminator
    greyToBin(grayInput, binaryOutput);
    printf("%s\n", binaryOutput);

    return 0;
}