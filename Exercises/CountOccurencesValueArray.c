// 3

#include <stdio.h>

int Occurrences(int array[], int length, int toFind)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        printf("myArray1[%d] = %d\n", i, array[i]);
        if (array[i] == toFind)
        {
            count++;

            printf("Found %d incremented count to %d\n", toFind, count);
        }
    }

    return count;
}

int main(void)
{

    int myArray1[] = {4, 9, 7, 6, 5, 8, 3, 2, 1, 5};

    int length1 = sizeof(myArray1) / sizeof(int);

    int toFind = 5;

    int count = Occurrences(myArray1, length1, toFind);

    printf("# of %ds found: %d\n", toFind, count);

    return 0;
}