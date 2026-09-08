/* User se numbers input karo. Program tab tak chalta rahe jab tak n number tak count na ho.

Count karo:

Kitne even numbers aaye
Kitne odd numbers aaye */

#include <stdio.h>

int main()
{
    int i = 1;
    int count_even = 0;
    int count_odd = 0;
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    while (i <= n)
    {
        if (i % 2 == 0)
        {
            count_even++;
        }
        else
        {
            count_odd++;
        }

        i++;
    }

    printf("%d times even numbers came\n", count_even);
    printf("%d times odd numbers came\n", count_odd);

    return 0;
}