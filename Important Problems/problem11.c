// program to find out if given no is prime no or not.

#include <stdio.h>

int main()
{
    int n;
    int isPrime = 1;

    printf("Enter the number: ");
    scanf("%d", &n);

    if (n<=1)
    {
        isPrime = 0;
    }
    

    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            isPrime = 0;
            break;
        }
    }


    if (isPrime == 1)
        printf("the number is prime\n");
    else
        printf("the number is not prime\n");
    

    return 0;
}