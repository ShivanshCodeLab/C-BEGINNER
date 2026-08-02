#include <stdio.h>

    int main(){
        int age;

        printf("Enter your age : ");
        scanf("%d", &age);

        if(age > 10){
            printf("your age is greater then 10");
        }
        if(age < 10){
            printf("your age is less then 10");
        }
        if(age == 10){
            printf("your age is equal to 10");
        }   
        return 0;

    
}