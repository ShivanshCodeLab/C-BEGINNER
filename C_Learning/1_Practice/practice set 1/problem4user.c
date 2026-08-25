#include <stdio.h>

int main()
{
    // int p = 500;
    // float r = 5;
    // int t = 2;

    int p, t;
    float r;

    printf("Enter p : ");
    scanf("%d", &p);

    printf("Enter r : ");
    scanf("%f", &r);

    printf("Enter t : ");
    scanf("%d", &t);

    printf("Simple interest is %f", (p + r + t) / 100);

    return 0;
}