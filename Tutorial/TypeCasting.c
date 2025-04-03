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

    return 0;
}