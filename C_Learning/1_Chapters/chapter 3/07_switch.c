#include <stdio.h>

int main()
{
    int a;

    printf("Enter a: ");
    scanf("%d", &a);

    switch (a)
    {
        case 1:
        printf("You Entered 1\n");
            break; 

        case 2:
        printf("You Entered 2\n");
            break; 

        case 3:
        printf("You Entered 3\n");
            break;

        case 4:
        printf("You Entered 4\n");

        break;
    
        default:
        printf("Nothing matched");
        break;
    }
    return 0;
}