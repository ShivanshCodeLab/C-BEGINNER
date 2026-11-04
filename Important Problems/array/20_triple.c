// count the number of triplets in the array whose sum is equal to the given value x.

#include <stdio.h>

int main(){
    int x=12, arr[8]={1,2,3,4,5,6,7,8}, count=0;
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            for(int k=j+1; k<8; k++){
                if(arr[i]+arr[j]+arr[k]==x){ count++;
                printf("Triplet found: (%d, %d, %d)\n", arr[i], arr[j], arr[k]);}
            }
        }
    }
    printf("Number of triplets with sum %d: %d\n", x, count);
    return 0;
}