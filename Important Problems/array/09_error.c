#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];

    for (int i = 1; i < size; i++) // initaialize i and change 1 to 0
    {
        scanf("%d", &arr[i]);
        printf("%d", arr[i]);

    }
    
    return 0;
}