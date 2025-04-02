// 6

#include <stdio.h>

int multiply(int a, int b)
{
    int res = 0;
    while (b)
    {
        if (b & 1)
            res += a;
        a <<= 1;
        b >>= 1;
    }
    return res;
}

int main()
{
    int res = multiply(5,3);

    printf("%d", res);

    return 0;
}