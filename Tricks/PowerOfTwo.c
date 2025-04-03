// 12

#include <stdio.h>
#include <stdbool.h>

/* Using Log – O(1) time and O(1) space */
bool IsPowerofTwo1(int n) {
    if (n <= 0)
        return false;
    
    // Calculate log base 2 of n
    int logValue = log2(n);
    
    // Check if log2(n) is an integer and 2^(logn) = n
    return pow(2, logValue) == n;
}

/* Using Division and Modulo Operator – O(log n) time and O(1) space */
bool IsPowerofTwo2(int n) {
    if (n <= 0)
        return false;
    
    while (n > 1) {
        if (n % 2 != 0)
            return false;
        n = n / 2;
    }
    return true;
}

/* Using Count of Set Bits – O(log n) time and O(1) space */
bool IsPowerofTwo3(int n)
{
    if (n <= 0)
        return false;

    // Count set bits
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
            count++;
        n = n >> 1;
    }

    // If count of set bits is 1, then n is a power of 2
    return (count == 1);
}

/* Using AND Operator – O(1) time and O(1) space */
bool IsPowerOfTwo4(int n)
{
    return n > 0 && !(n & (n - 1));
}

int main()
{
    int n = 16;

    if (IsPowerOfTwo4(n))
        printf("Yes");
    else
        printf("No");

    return 0;
}