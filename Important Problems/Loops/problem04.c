// print the table of 'n'. here 'n' is a integer which user will input.

#include <stdio.h>

int main()
{
    int n;
    int i;

    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i*n);
    }
    


    return 0;
}