#include <stdio.h>
#include <math.h>

int FindCount(int n)
{
    if (n == 0)
        return 1;

    int count = 0;

    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

int FindCountLogarithmic(int n)
{
    if (n == 0)
        return 1;

    int count = 0;

    count = (n == 0) ? 1 : log10(n) + 1;

    return count;
}

int FindCountRecursion(int n)
{
    if (n == 0)
        return 1;

    static int Count = 0;

    if (n > 0)
    {
        Count = Count + 1;
        FindCountRecursion(n / 10);
    }

    return Count;
}

int FindCountRepeatedMultiplication(unsigned int n)
{
    if (n == 0)
        return 1;

    unsigned int count = 0;
    unsigned int temp = 1;
    while (temp <= n)
    {
        count++;
        temp *= 10;
    }
    return count;
}

int FindCountPowersOf10(unsigned int n)
{
    if (n == 0)
        return 1;

    int count = 1;

    if (n >= 100000000)
    {
        count += 8;
        n /= 100000000;
    }

    if (n >= 10000)
    {
        count += 4;
        n /= 10000;
    }

    if (n >= 100)
    {
        count += 2;
        n /= 100;
    }

    if (n >= 10)
    {
        count += 1;
    }

    return count;
}

int main()
{
    int n = 900000;
    printf("Count of digits in %d = %d\n", n, FindCount(n));
    printf("Count of digits (Logarithmic Approach) in %d = %d\n", n, FindCountLogarithmic(n));
    printf("Count of digits (Using Recursion) in %d = %d\n", n, FindCountRecursion(n));
    printf("Count of digits (Using Repeated Multiplication) in %d = %d\n", n, FindCountRepeatedMultiplication(n));
    printf("Count of digits (Dividing with Powers of 10) in %d = %d\n", n, FindCountPowersOf10(n));
    return 0;
}