// 1

#include <stdio.h>

double FastPow(double a, int b)
{
    double res = 1;

    while (b > 0)
    {
        if (b % 2 > 0)
            res *= a;

        a *= a;
        b /= 2;
    }

    return res;
}

int main(void)
{
    int array[10];

    return 0;
}