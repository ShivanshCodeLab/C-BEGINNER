#include <stdio.h>

int main()
{
    int income, tax=0;

    printf("Enter income: ");
    scanf("%d", &income);

    if(income < 250000)
    {
        tax = 0;
    }
    else if(income > 250000 && income < 500000)
    {
        tax = 0.05*(income-250000);
    } 
    else if(income > 500000 && income < 1000000)
    {
        tax = 0.2*(income-500000);
    } 
    else if(income > 1000000)
    {
        tax = 0.3*(income-1000000);
    }
    printf("Your tax amount is: %d\n", tax);

    return 0; 

    // incomplte code because we have not print the tax amount
}