// 7

#include <stdio.h>

#define print(x) _Generic((x), int: print_int, char*: print_string)(x)

void print_int(int x)
{
    printf("Integer: %d\n", x);
}

void print_string(char* x)
{
    printf("String: %s\n", x);
}

int main()
{
    print(42);
    print("Hello");

    return 0;
}