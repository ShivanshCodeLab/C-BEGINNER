// Q4. User se number input karo, phir poochho: Enter number: Enter again? (y/n):

#include <stdio.h>

int main()
{
    int a = 1;
    char ch = 'y';

    while (10 >= a)
    {
        printf("Enter number: ");
        scanf("%d", &a);

        printf("The number is: %d\n", a);

        printf("Enter number again? (y/n): ");
        scanf(" %c", &ch);

        if (ch == 'y')
            continue;
        else if (ch == 'n')
            printf("Thank you!!\n");
            break;
    }

    return 0;
}