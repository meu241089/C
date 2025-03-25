#include <stdio.h>

int main()
{
    int array[5];
    printf("Enter elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Duplicate Elements: ");
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (array[i] == array[j])
            {
                printf("%d ", array[i]);
            }
        }
    }

    return 0;
}