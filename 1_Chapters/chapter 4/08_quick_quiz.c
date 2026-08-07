#include <stdio.h>

int main()
{
    int n, i = 0;

    printf("Enter N: ");
    scanf("%d", &n);
    do
    {
        if (i >= 1)
        {
            printf("The value of i is %d\n", i);
        }
        i++;
    } while (i <= n);
        
        
    return 0;
}