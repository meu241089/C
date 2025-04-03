// 8

/*
    Converting Celsius to Fahrenheit: multiply by 1.8 (or 9/5) and add 32
*/

#include <stdio.h>

int main(void)
{

    double celsius = 0;
    double start = 0;
    double end = 0;
    double step = 0;
    double fahrenheit = 0;

    printf("Enter start celsius temperature: ");
    scanf("%lf", &start);

    printf("Enter end celsius temperature: ");
    scanf("%lf", &end);

    printf("Enter step value: ");
    scanf("%lf", &step);

    printf("  Celsius  Fahrenheit\n");

    for (celsius = start; celsius <= end; celsius += step)
    {
        fahrenheit = (celsius * 9 / 5) + 32;

        printf("%8.2lf %8.2lf\n", celsius, fahrenheit);
    }

    return 0;
}