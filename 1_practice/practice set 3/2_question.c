#include <stdio.h>

int main()
{
    int marks1, marks2, marks3;

    printf("Enter marks 1: ");
    scanf("%d", &marks1);
    
    printf("Enter marks 2: ");
    scanf("%d", &marks2);
    
    printf("Enter marks 3: ");
    scanf("%d", &marks3);
    
    printf("The marks are: %d, %d, %d\n", marks1, marks2, marks3);

    if(marks1 < 33 || marks2 < 33 || marks3 < 33)
    {
        printf("You are failed due to low marks.\n");
        return 1; // Exit the program with an error code
    }
    else if((marks1 + marks2 + marks3) / 3 < 40)
    {
        printf("You are failed due to low average marks.\n");
        return 1; // Exit the program with an error code
    }
    else
    {
        printf("Congratulations! You have passed.\n");
    }

    return 0;
}