// print factorial of first n numbers;

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
        
        printf("the factorial of %d is %d\n",n, mul);
        n++;
    }

    return 0;
}