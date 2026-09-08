// print the sum of this series: 1-2+3-4+5-6.... upto 'n'.

#include <stdio.h>

int main()
{
    int i = 0;
    int n;
    int sum = 0;

    printf("Enter N: ");
    scanf("%d", &n);

    while (i<=n)
    {
        if (i % 2 != 0)
        {
            sum = i + sum;
        }
        else
        {
            sum = sum - i;
        }
        i++;
        
    }
    printf("the sum is %d\n", sum);
        
    return 0;
}