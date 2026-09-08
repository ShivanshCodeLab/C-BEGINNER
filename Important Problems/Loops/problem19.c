// print first 'n' fibonacci numbers.

#include <stdio.h>

int main()
{
    int n = 1, i = 3;
    int sum = 1;
    int a = 1, b = 1;
    
    printf("Enter Number: ");
    scanf("%d", &n);

    printf("1st fibonacci is %d\n", a);
    printf("2nd fibonacci is %d\n", b);



    while (i<=n)
    {
        sum = a+b;
        a = b;
        b = sum;

        if (i == 3)
            printf("%drd fibonacci is %d\n", i, sum);
        else
            printf("%dth fibonacci is %d\n", i, sum);
        
        i++;
    }

    
    
    return 0;
}