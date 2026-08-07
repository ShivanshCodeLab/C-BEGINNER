#include <stdio.h>

int main()
{
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("The value of i is: %d\n", i);
    }
    
    return 0;
}