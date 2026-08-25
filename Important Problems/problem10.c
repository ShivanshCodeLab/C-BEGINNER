// display this AP - 100,50,25..... upto n.
#include <stdio.h>

int main()
{
    float a = 100;
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 1; i <=n; i++)
    {
        printf("%.2f\n", a);
        a = a/2.0;
    }
    
    return 0;
}