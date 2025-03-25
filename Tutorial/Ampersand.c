// 16

#include <stdio.h>

// int addition(int a, int b)
// {
//     int result;
//     result = a + b;
//     return result;
// }

void addition(int a, int b, int *target)
{
    *target = a + b;
    return;
}

int main()
{
    int x, y, answer;

    x = 5;
    y = 10;

    // answer = addition(x, y);

    addition(x, y, &answer);

    printf("%d\n", answer);

    return 0;
}