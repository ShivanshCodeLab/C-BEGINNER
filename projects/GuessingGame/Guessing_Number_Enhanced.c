#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playAgain;

    srand(time(0));

    do
    {
        int choice, max, attemptsLeft;
        int random_number, guessed;
        int no_of_guesses = 0;
        int score;

        printf("\n===== NUMBER GUESSING GAME =====\n");
        printf("1. Easy   (1 - 50, 10 attempts)\n");
        printf("2. Medium (1 - 100, 7 attempts)\n");
        printf("3. Hard   (1 - 500, 5 attempts)\n");
        printf("Choose difficulty: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                max = 50;
                attemptsLeft = 10;
                break;

            case 2:
                max = 100;
                attemptsLeft = 7;
                break;

            case 3:
                max = 500;
                attemptsLeft = 5;
                break;

            default:
                printf("Invalid choice! Medium selected.\n");
                max = 100;
                attemptsLeft = 7;
        }

        random_number = rand() % max + 1;

        printf("\nI have chosen a number between 1 and %d.\n", max);

        while (attemptsLeft > 0)
        {
            printf("Enter your guess: ");
            scanf("%d", &guessed);

            no_of_guesses++;
            attemptsLeft--;

            if (guessed < 1 || guessed > max)
            {
                printf("Please enter a number between 1 and %d!\n", max);
                attemptsLeft++;
                no_of_guesses--;
            }
            else if (guessed == random_number)
            {
                score = attemptsLeft * 10 + 10;

                printf("\n🎉 Congratulations! You guessed the number.\n");
                printf("Attempts used: %d\n", no_of_guesses);
                printf("Score: %d\n", score);
                break;
            }
            else if (guessed < random_number)
            {
                printf("Too low! Guess higher.\n");
                printf("Attempts left: %d\n", attemptsLeft);
            }
            else
            {
                printf("Too high! Guess lower.\n");
                printf("Attempts left: %d\n", attemptsLeft);
            }
        }

        if (attemptsLeft == 0 && guessed != random_number)
        {
            printf("\nGame Over! You ran out of attempts.\n");
            printf("The correct number was: %d\n", random_number);
        }

        printf("\nDo you want to play again?\n");
        printf("1 = Yes, 0 = No : ");
        scanf("%d", &playAgain);

    } while (playAgain == 1);

    printf("\nThanks for playing!\n");

    return 0;
}


