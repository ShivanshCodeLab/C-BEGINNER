#include <stdio.h>

int main()
{
    int radius, height;
    float volume;

    printf("Enter radius : ");
    scanf("%d", &radius);

    printf("Enter height : ");
    scanf("%d", &height);

    //     int r = 6;
    //     int h = 5;

    volume = 3.14 * radius * radius * height;

    printf("The volume of a cylinder with radius %d and height %d is %.2f",
            radius, height, volume);

    return 0;
}