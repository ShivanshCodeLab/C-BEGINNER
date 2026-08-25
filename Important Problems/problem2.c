// question -  print all the odd numbers from 1 to 100.

#include <stdio.h>

int main()
{
    int i;

    for (int i = 1; i <= 100; i+=2)
    {
        printf("%d\n", i);
    }
    
    return 0;
}