// 1

#include <stdio.h>

int FindMinimumNumber(int array[], int length)
{
    int minimum;

    minimum = array[0];

    for (int i = 0; i < length; i++)
    {
        printf("Checking myArray[%d] = %d\n", i, array[i]);
        if (array[i] < minimum)
            minimum = array[i];
    }

    return minimum;
}

int main(void)
{

    int myArray1[] = {5, 9, 10, 11, 4, 3, 8, 6, 7};

    int length1 = sizeof(myArray1) / sizeof(int);

    int myArray2[] = {2, 5, 9, 3, 4, 1, 8};

    int length2 = sizeof(myArray2) / sizeof(int);

    int minimum1 = FindMinimumNumber(myArray1, length1);

    int minimum2 = FindMinimumNumber(myArray2, length2);

    printf("Minimum 1: %d\n", minimum1);
    printf("Minimum 2: %d\n", minimum2);

    return 0;
}