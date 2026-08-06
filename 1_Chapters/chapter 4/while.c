#include <stdio.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    while(a < 100)
    {
        printf("Happy Birthday\n");
        a++;
    }
    return 0;
}