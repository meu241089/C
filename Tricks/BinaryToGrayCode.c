// 2

#include <stdio.h>

int BinaryToGray(int n)
{
    return n ^ (n >> 1);
}

int GrayToBinary(int n) {
    int res = n;
    while (n > 0) {
        n >>= 1;
        res ^= n;
    }
    return res;
}

int main(void)
{
    int res = 0;

    res = BinaryToGray(3);

    printf("Result: %d\n", res);

    res = GrayToBinary(2);

    printf("Result: %d\n", res);

    return 0;
}