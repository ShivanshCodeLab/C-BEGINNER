// find the difference between the sum of elements at even indices to the sum of elements at odd indices.

#include<stdio.h>
 int main(){

    int arr[6] = {1,3,5,7,9,11};
    int evenSum = 0, oddSum = 0;
    for(int i = 0; i < 6; i++){
        if(i % 2 == 0) evenSum += arr[i];
        else oddSum += arr[i];}
    printf("Difference: %d\n", evenSum - oddSum);
    return 0;
 }