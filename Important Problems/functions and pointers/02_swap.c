#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int c;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("after swap a is %d and b is %d\n", a, b);

    return 0;
}