#include <stdio.h>

int main()
{
    int x, y, rev = 0, d, cp;

    printf("Enter Lower Limit: ");
    scanf("%d", &x);

    printf("Enter Upper Limit: ");
    scanf("%d", &y);

    for (int i = x; i <= y; i++)
    {
        rev = 0;
        cp = i;
        while (cp > 0)
        {
            d = cp % 10;
            rev = rev * 10 + d;
            cp /= 10;
        }

        if (i == rev)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}