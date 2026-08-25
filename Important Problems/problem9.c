// display this AP - 100,97,94..... upto all terms which no are positive.
#include <stdio.h>

int main()
{
    int a = 100;
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 1; a>0; i++)
    {
        printf("%d\n", a);
        a = a-3;
    }
    
    return 0;
}