#include <stdio.h>

// function prototype
int sum(int,int);

// function definition
int sum(int x,int y){

    // printf("The sum is %d\n", x+y);
    return x+y;
}

int main()
{
    int a = 1; 
    int b = 2;

    // int c = a + b;
    // printf("The sum is %d\n", c);
    int c = sum(1,2); // function call
    printf("The sum is %d\n", c);

    
    return 0;
}