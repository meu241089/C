// 7

#include <stdio.h>

double Average(double array[], int length)
{
    double sum, average;

    for (int i = 0; i < length; i++)
    {
        sum = sum + array[i];

        printf("array[%d] = %.2lf, sum = %.2lf\n", i, array[i], sum);
    }

    average = sum / length;

    return average;
}

int main(void)
{
    double array[] = {5.2, 9.3, 6.5, 4.1, 7.8};
    int length = sizeof(array) / sizeof(double);
    double average = 0;

    average = Average(array, length);

    printf("Average: %.2lf", average);

    return 0;
}