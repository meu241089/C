// 28

#include <stdio.h>

int main()
{

    int a;
    float b, q;

    a = 15, b = 2;

    q = a / b;

    /*wrong*/
    printf("%d\n", q); // first result = -516780792, second result = 1002299176, etc

    /*implicity type casting*/
    printf("%f\n", q);

    /*explicity type casting*/
    q = (float)a / b;
    printf("%f\n", q);

    int c, d, r;
    c = 15, d = 2;

    r = c / d;

    printf("%d\n", r);
    printf("%f\n", r);

    /*
        char = 8 bits -> 256 combinations
        long long int = 64 bit -> 2^64 combinations
        int, float, double = 32 bit -> 2^32 combinations
    */

    char e;
    int f;

    f = 100;
    e = f;

    printf("%d\n", e); // printf 100 beacuse we are in the rage of char

    f = 300;
    e = f;

    printf("%d\n", e); // print 44 beacuse 300 - 256 = 44, we lost information

    return 0;
}