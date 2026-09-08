// Q1. User se ek number input lo aur while loop se 1 se 10 tak uska multiplication table print karo.

#include <stdio.h>

int main()
{
    int i = 1, n;

    printf("Enter number: ");
    scanf("%d", &n);

    while (i<=10)
    {
        printf("%d x %d = %d\n", n, i, n*i);
        i++;
    }
    
    return 0;
}