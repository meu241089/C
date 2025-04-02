// 8

#include <stdio.h>
#define PRINT_VALUE(var, num) printf("Value of " #var #num ": %d\n", var##num)

int main()
{
    int value1 = 100;
    PRINT_VALUE(value,1);
    return 0;
}