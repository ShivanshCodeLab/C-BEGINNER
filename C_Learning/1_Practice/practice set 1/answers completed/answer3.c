#include <stdio.h>

int main()
{

    // value of celsius can be decimal so we used float
    float celsius = 30;

    // vlaue of fahrenheit can be decimal like celsius
    float fahrenheit;

    // formula of fahrenheit
    fahrenheit = (celsius * 1.8) + 32;

    printf("celsius is %f fahrenheit is %.2f", celsius, fahrenheit);

    return 0;
}