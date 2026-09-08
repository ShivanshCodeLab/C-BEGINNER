// Q3. User se number lo. Jab tak number 10 se chhota ya equal hai, input lete raho. Jaise hi number > 10 ho, program stop ho.

#include <stdio.h>

int main()
{
    int i;

    

    while (i>=0)
    {
        
        printf("Enter number: ");
        scanf("%d", &i);

        printf("The number is %d\n", i);


        if (i<=10)
        {
            printf("Enter another number\n");
            continue;
        }
        else if (i>10)
        {
            printf("thanks!!!\n");
            break;
        }
    }

    return 0;
}                                                                                                                   