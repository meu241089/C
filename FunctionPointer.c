// 23

#include <stdio.h>
#define F fflush(stdout)
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4

void Addition(int *target, int a, int b)
{
    *target = a + b;
    return;
}

void Subtraction(int *target, int a, int b)
{
    *target = a - b;
    return;
}

void Multiplication(int *target, int a, int b)
{
    *target = a * b;
    return;
}

void Division(int *target, int a, int b)
{
    if (b > 0)
        *target = a / b;
    else
        *target = 0;
    return;
}

int main()
{
    int x, y, operation, result;
    void (*functionPointer)(int *, int, int);

    printf("Press 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division and 0 to quit\n");
    scanf("%d", &operation);

    printf("Number 1: ");
    F;
    scanf("%d", &x);

    printf("Number 2: ");
    F;
    scanf("%d", &y);

    switch (operation)
    {
    case ADDITION:
        functionPointer = Addition;
        break;
    case SUBTRACTION:
        functionPointer = Subtraction;
        break;
    case MULTIPLICATION:
        functionPointer = Multiplication;
        break;
    case DIVISION:
        functionPointer = Division;
        break;

    default:
        return 0;
    }

    (functionPointer)(&result, x, y);

    printf("\nResult: %d\n", result);

    return 0;
}