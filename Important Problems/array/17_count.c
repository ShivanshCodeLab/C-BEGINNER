// count the number of elements in an given array greater than a given number x.

#include<stdio.h>

int main(){

    int arr[7] = {1,2,3,4,5,6,7};
    int x = 3;
    int count = 0;
    for(int i = 0; i < 7; i++){
        if(arr[i] > x) count++;}
    printf("Number of elements greater than %d: %d\n", x, count);
    return 0;


}