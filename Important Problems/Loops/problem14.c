// infinite loop.

#include <stdio.h>

int main()
{
    int n = 5;
    int i = 10;
    while (i > n)
    {
       printf("%d\n", i);
       i++;
    }
    
    return 0;
}