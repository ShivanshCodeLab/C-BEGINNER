#include <stdio.h>
#include <stdlib.h>
#include <time.h>

    int main(){
        int random; 
        int guess;
        int no_of_guess = 0;

        srand(time(NULL));
        random = rand() % 100 + 1;

        printf("Welcome to the Guessing number game!\n");
        
        printf("Guess the number between 1-100 : ");

        do
        {    
            scanf("%d", &guess);
            
            no_of_guess++;

            if(guess < 1 || guess > 100){
            printf("Enter number betwwen 1-100 : ");
            }
            else if(guess > random){
            printf("Guess a smaller number : ");
            }
            else if(guess < random){
            printf("Guess a larger number : ");
            }
            else {
            printf("Congratulations !!!\nYou have successfully guessed the number in %d attempts\n", no_of_guess);
            }
        }   while (guess != random);
        
    system("pause");   
    return 0;
}