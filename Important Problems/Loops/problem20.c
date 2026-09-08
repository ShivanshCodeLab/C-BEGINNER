// given 2 numbers 'a' and 'b' , find 'a' raised to the power 'b'. 

#include <stdio.h>

int main()
{
    int a,b;
    int power = 1;
    int i = 1;

    printf("Enter base: ");
    scanf("%d", &a);

    printf("enter power: ");
    scanf("%d", &b);

    while (i<=b)
    {
        power = power * a;
        i++;
    }
    printf("%d raised to the power %d is %d", a,b, power);  
    
    return 0;
}