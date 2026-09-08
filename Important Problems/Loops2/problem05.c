/* Q 5. User se numbers lete raho aur unka sum calculate karo.

User se poochho:

Enter again? (y/n):*/

#include <stdio.h>

int main()
{
    int a = 0, sum = 0;
    char ch = 'y';

    while (a>=0)
    {
        printf("Enter number: ");
        scanf("%d", &a);

        printf("The number is: %d\n", a);

        printf("Enter number again? (y/n): ");
        scanf(" %c", &ch);

        sum+=a;
        printf("sum : %d\n", sum);


        if (ch == 'y')
        {
            continue;
        }
        else if (ch == 'n')
            printf("Thank you!!\n");
            break;


    }

    return 0;
}