#include <stdio.h>

    int main(){
        int radius;
        float area;

        printf("Enter radius : ");
        scanf("%d", &radius);

        area = 3.14*radius*radius;

        printf("the area of circle with radius %d is %f", radius, area);

    return 0;
}