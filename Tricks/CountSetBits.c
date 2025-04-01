// 3

#include <stdio.h>

int main(void)
{
    int a = 10, count = 0;

    // while(a != 0)
    // {
    //     if(a % 2 == 1)
    //     {
    //         count++;
    //     }
    //     a /= 2;
    // }

    // while (a)
    // {
    //     count += a & 1;
    //     a >>= 1;
    // }

    while (a)
    {
        a &= a - 1;
        count++;
    }

    printf("The total bit set is %d", count);

    return 0;
}