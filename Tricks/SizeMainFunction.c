// 4

#include <stdio.h>
#include <stdlib.h>

#define SIZEOF(a) (sizeof a / sizeof a[0])

//void PrintSize (int* array[]) --> is the same
void PrintSize (int array[])
{
    printf("Inside function: sizeof(array) = %zu bytes\n", sizeof(array)); // size of pointer
    return;
}

int main()
{
    int array[10];
    int length = sizeof(array)/sizeof(array[0]);

    printf("In main: sizeof(array) = %zu bytes\n", sizeof(array)); // size of array
    PrintSize(array);

    return 0;
}

// void printarray(double p[], int s)
// {
//     int i;

//     // THIS IS WHAT DOESN"T WORK, SO AS A CONSEQUENCE, I PASS THE
//     // SIZE IN AS A SECOND PARAMETER, WHICH I'D RATHER NOT DO.
//     printf("The size of p calculated = %ld.\n", SIZEOF(p));
//     printf("The size of p = %ld.\n", sizeof p);
//     printf("The size of p[0] = %ld.\n", sizeof p[0]);

//     for (i = 0; i < s; i++)
//         printf("Eelement %d = %lf.\n", i, p[i]);

//     return;
// }

// int main()
// {
//     double array1[10];

//     printf("The size of array1 = %ld.\n", SIZEOF(array1));
//     printf("The size of array1 = %ld.\n", sizeof array1);
//     printf("The size of array1[0] = %ld.\n\n", sizeof array1[0]);

//     printarray(array1, SIZEOF(array1));

//     return EXIT_SUCCESS;
// }