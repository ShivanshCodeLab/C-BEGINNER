// Q2. User se numbers input lete raho jab tak user 0 enter na kare. Har number ko print karo.

#include <stdio.h>

int main()
{
    int i,n;

    
    while (i>=0)
    {
        printf("Enter number: ");
        scanf("%d", &i);


        printf("the number is %d\n", i);

        if (i >= 1)
        {
            printf("input another number\n");
            continue;
            
        }
        else if(i == 0)
        {
            printf("Congratulations!!!\n");
            break;
        }

        
    }
    
    return 0;
}