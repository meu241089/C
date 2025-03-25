// 13

#include <stdio.h>

int main()
{
    int x;
    printf("Choose between 1.Apples, 2.Pears or 3.Bananas\n");
    scanf("%d", &x);

    switch (x)
    {
    case 1: /* apples*/
        printf("Apples\n");
        break;
    case 2: /* pears*/
        printf("Pears\n");
        break;
    case 3: /* banans*/
        printf("Bananas\n");
        break;
    default:
        printf("Something else\n");
    }

    return 0;
}