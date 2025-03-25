// 5
#include <stdio.h>

int main()
{
    int x;

    x = 0;

    while (x != 1)
    {
        printf("Do you want to quit? Press 1\n");
        scanf("%d", &x);
    }

    return 0;
}