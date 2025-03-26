// 4

#include <stdio.h>

void ReverseArray(int array[], int length)
{
    int temp = 0;

    for (int i = 0; i < (length / 2); i++)
    {
        temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++)
    {
        printf("myArray[%d] = %d\n", i, array[i]);
    }
}

int main(void)
{
    int myArray1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int length1 = sizeof(myArray1) / sizeof(int);

    ReverseArray(myArray1, length1);

    return 0;
}