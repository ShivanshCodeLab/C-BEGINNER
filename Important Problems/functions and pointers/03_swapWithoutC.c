#include <stdio.h>

int main(void)
{
    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("after swap a is %d and b is %d\n", a, b);

    return 0;
}