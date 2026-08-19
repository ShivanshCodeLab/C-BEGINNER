#include <stdio.h>

int main()
{
    int product = 1;
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    printf("product: %d\n", product);


    return 0;
}