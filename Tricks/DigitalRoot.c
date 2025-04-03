// 13

#include <stdio.h>

int NormalDigitalRoot(int n)
{
    while (n >= 10)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int DigitalRoot(int n)
{
    return 1 + (n - 1) % 9;
}

int main()
{

    int n = 10000;

    printf("Digital Root (Normal) in %d = %d\n", n, NormalDigitalRoot(n));
    printf("Digital Root in %d = %d\n", n, DigitalRoot(n));

    return 0;
}