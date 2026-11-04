// Calculate the product of all the elements in the given array.
#include <stdio.h>

int main()
{
    int arr[5]= {1,2,3,4,5};
    int pro = 1;

    for (int i = 0; i < 5; i++)
    {
        pro = pro * arr[i];
    }
    printf("%d", pro);
    
    return 0;
}