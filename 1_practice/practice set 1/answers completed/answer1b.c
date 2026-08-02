#include <stdio.h>

    int main(){
        int length, breadth, area;

        // User enter the length and breadth to get area
        printf("Enter length : ");
        scanf("%d", &length);

        printf("Enter breadth : ");
        scanf("%d", &breadth);

        area = length * breadth;

        printf("The area of rectangle is %d", area);
    
    return 0;
}