// 6

#include <stdio.h>

int sumArray(int array[], int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum = sum + array[i];
    }

    return sum;
}

int main(void)
{

    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(myArray) / sizeof(int);
    int sum = 0;

    sum = sumArray(myArray, length);

    printf("Sum of array: %d\n", sum);
    return 0;
}