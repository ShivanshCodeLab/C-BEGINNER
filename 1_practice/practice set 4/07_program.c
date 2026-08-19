#include <stdio.h>

int main()
{
    int product = 1;
    int n;
    printf("Enter N : ");
    scanf("%d", &n);

    // for (int i = 1; i <= n; i++)
    // {
    //     product *= i;
    // }
    
    int i = 1;
    while (i <= n)
    {
        product *= i;
        i++;
    }
    
    printf("product: %d\n", product);


    return 0;
}