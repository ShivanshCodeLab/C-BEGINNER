#include <stdio.h>

int factorial(int);
 
int factorial(int n){ 
    if(n == 1 || n == 0){ // Base condition
        return 1;
    }
    // Factorial(n) = Factorial(n-1) X n
    return n * factorial(n-1);
}

int main(){
    int a = 6;
    printf("The factorial of %d is %d", a, factorial(a));
    return 0;
}