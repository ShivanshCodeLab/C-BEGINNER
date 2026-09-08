// print inverted number of triangle.


#include <stdio.h>

int main()
{
    int r;

    printf("Enter how many rows needed: : ");
    scanf("%d", &r);

    for (int i = r; i>=1; i--){
       
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");   
    }

    return 0;
}
