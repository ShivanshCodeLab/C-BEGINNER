#include <stdio.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    printf("The character is: %c\n", ch);
    printf("The value of character is: %d\n", ch);

    if (ch >= 97 && ch <= 122)
    {
        printf("The character is a lowercase letter.\n");
    }
    else
    {
        printf("The character is not a lowercase letter.\n");
    }

    return 0;
}