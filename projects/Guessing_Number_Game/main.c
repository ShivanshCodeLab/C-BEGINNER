#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int random_number = rand() % 100 + 1;
    int no_of_guesses = 0;
    int guessed;

    printf("Welcome to the Number Guessing Game!\n");

    printf("Guess the number between 1 and 100: ");
    scanf("%d", &guessed);
    

    do
    {
        no_of_guesses++;
        if(guessed < 1 || guessed > 100)
        {
            printf("Please enter a number between 1 and 100!: ");
            scanf("%d", &guessed);
        }
        else if(guessed > random_number)
        {
            printf("Guess lower: ");
            scanf("%d", &guessed);
        }
        else if(guessed < random_number)
        {
            printf("Guess higher: ");
            scanf("%d", &guessed);
        }
    } while (guessed != random_number);

    printf("Congratulations!\nYou guessed the number in %d attempts.\n", no_of_guesses);

    

    return 0;
}