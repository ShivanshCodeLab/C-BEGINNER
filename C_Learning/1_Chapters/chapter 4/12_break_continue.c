#include <stdio.h>

int main()
{
    for(int i = 0; i<15; i++)
    {
        if(i == 5)
        {
            break; //stop all iterations of the loop when i is equal to 5
            // continue; skip the current iteration of the loop when i is equal to 5
        }
        printf("%d\n ", i);
    }
    return 0;
}   