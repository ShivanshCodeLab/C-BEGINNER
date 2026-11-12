// find the second largest element in the given array.

#include "stdio.h"
#include <limits.h>

int main(){
    int max = INT_MIN , smax = INT_MIN;
    int arr[7] = {1,2,3,4,5,6,7};

    for(int i = 0; i<7 ; i++){
        if(arr[i]>max){
            smax = max;
            max = arr[i];
        }
        else if(arr[i]>smax && arr[i]!=max){
            smax = arr[i];
        }
    }
    printf("Second largest element in the array is: %d\n", smax);
    return 0;
}









