#include <stdio.h>

void fun(int arr[])
{
    int temp;
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

int main()
{
    int arr[2] ={1,5};
    printf("Before swapping: arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);

    fun(arr);
    printf("After swapping: arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
    return 0;
}