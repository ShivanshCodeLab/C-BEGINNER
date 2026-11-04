// Find the number of pairs in the array whose sum is equal to the given value x.

#include <stdio.h>

int main(){
    int x=12, arr[8]={1,2,3,4,5,6,7,8}, count=0;
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if(arr[i]+arr[j]==x){ count++;
            printf("Pair found: (%d, %d)\n", arr[i], arr[j]);}
        }
    }
    printf("Number of pairs with sum %d: %d\n", x, count);
    return 0;
}