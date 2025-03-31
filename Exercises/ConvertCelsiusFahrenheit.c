// 8

/*
    Converting Celsius to Fahrenheit: multiply by 1.8 (or 9/5) and add 32
*/

#include <stdio.h>

int main(void)
{

    double celsius = 0;
    double fahrenheit = 0;

    printf("Enter Celsius temperature: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("Celsius: %.2lf -> Fahrenheit: %.2lf\n", celsius, fahrenheit);

    return 0;
}