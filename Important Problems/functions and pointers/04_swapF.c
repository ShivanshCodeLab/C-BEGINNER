#include <stdio.h>

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;

    return;
}

int main()
{
    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    swap(&a, &b);

    printf("after swap a is %d and b is %d\n", a, b);

    return 0;
}