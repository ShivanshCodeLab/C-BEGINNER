#include <stdio.h>

int main()
{
    int arr[7] = {11,4,2,8,19,5,12};
    int min = arr[6];

    for (int i = 6; i >= 0; i--) 
        if(min>arr[i]) 
            min = arr[i];

    
printf("%d", min);

return 0;
}