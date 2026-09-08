// print the factorial of given number.

#include <stdio.h>

int main()
{
    int i , n = 1;
    int mul = 1;

    printf("Enter number: ");
    scanf("%d", &i);

    while (n<=i)
    {
        mul = mul * n;
        n++;
    }

    printf("the factorial is %d", mul);
    return 0;
}