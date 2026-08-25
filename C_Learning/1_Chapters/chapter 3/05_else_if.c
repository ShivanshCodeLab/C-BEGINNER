#include <stdio.h>

int main()
{
    int age;

    printf("Enter age: ");
    scanf("%d", &age);

    if(age>60){
        printf("You can drive and you are senior citizen");
    }
    else if(age>18){
        printf("You can drive");
    }
    else if(age>45){
        printf("You can drive and you are elder");
    }
    else{
        printf("You cannot drive");
    }
    return 0;
}