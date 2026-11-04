// Calculate the sum of all the elements in the given array.

#include <stdio.h>

int main()
{
    int n;
    
    printf("Enter the size of array: "); scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int j = 0; j < n; j++) printf("%d", arr[j]);
    
    return 0;
}