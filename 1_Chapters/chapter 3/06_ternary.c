#include <stdio.h>

int main()
{
    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    a>b?printf("A is greater"):printf("B is greater");
    return 0;
}