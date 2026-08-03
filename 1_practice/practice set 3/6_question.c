#include <stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int d;

    printf("Enter A : ");
    scanf("%d", &a);
    printf("Enter B : ");
    scanf("%d", &b);
    printf("Enter C : ");
    scanf("%d", &c);
    printf("Enter D : ");
    scanf("%d", &d);

    if (a>b && a>c && a>d)
    {
        printf("a is the largest number.\n");
    }
    else if (b>a && b>c && b>d)
    {
        printf("b is the largest number.\n");
    }
    else if (c>a && c>b && c>d)
    {
        printf("c is the largest number.\n");
    }
    else
    {
        printf("d is the largest number.\n");
    }

    return 0;
}