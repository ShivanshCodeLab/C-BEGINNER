// print star triangle inverted

#include <stdio.h>

int main()
{
    int r;

    printf("Enter rows: ");
    scanf("%d", &r);

    for (int i = r; i>=1; i--){
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");   
        
    }

    return 0;
}
