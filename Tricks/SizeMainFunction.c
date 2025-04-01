// 4

#include <stdio.h>

void PrintSize (int array[])
{
    printf("Inside function: sizeof(array) = %zu bytes\n", sizeof(array)/sizeof(array[0]));
}

int main()
{
    int array[10];
    int length = sizeof(array)/sizeof(array[0]);

    printf("In main: sizeof(array) = %zu bytes\n", sizeof(array));
    return 0;
    PrintSize(array);

    return 0;
}