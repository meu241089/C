// 2

#include <stdio.h>

int FindMaximumNumber(int array[], int length)
{
    int maximum;

    maximum = array[0];

    for (int i = 0; i < length; i++)
    {
        printf("Checking myArray[%d] = %d\n", i, array[i]);
        if (array[i] > maximum)
        {
            maximum = array[i];
            printf("New max found: %d\n", maximum);
        }
    }

    return maximum;
}

int main(void)
{
    int myArray1[] = {5, 9, 10, 11, 4, 3, 8, 6, 7};

    int length1 = sizeof(myArray1) / sizeof(int);

    int myArray2[] = {2, 5, 9, 3, 4, 1, 8};

    int length2 = sizeof(myArray2) / sizeof(int);

    int maximum1 = FindMaximumNumber(myArray1, length1);

    int maximum2 = FindMaximumNumber(myArray2, length2);

    printf("Maximum 1: %d\n", maximum1);
    printf("Maximum 2: %d\n", maximum2);

    return 0;
}