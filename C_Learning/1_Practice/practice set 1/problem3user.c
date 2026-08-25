#include <stdio.h>

    int main(){
        
        float celsius;
        printf("Enter celsius : ");
        scanf("%f", &celsius);

        float fahrenheit = celsius * 1.8 + 32;
        printf("Celsius into fahrenheit is %f is celsius %.2f is fahrenheit", celsius, fahrenheit);



    return 0;
}