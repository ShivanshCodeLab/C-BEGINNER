// print the nth fibonacci number.

#include <stdio.h>

int main()
{
    int n = 1, i = 1;
    int sum = 1;
    int a = 1, b = 1;
    
    printf("Enter Number: ");
    scanf("%d", &n);


    while (i<=n-2)
    {
        sum = a+b;
        a = b;
        b = sum;

        i++;
    }

    printf("the %dth fibonacci is %d",n ,sum);
    
    return 0;
}