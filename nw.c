#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretnumber, guess;
    int attempts = 0;
    int max_attempts = 7;
    char playAgain;

    srand(time(NULL));
    
    printf("\n");
    printf("========================================\n");
    printf("   THE WORLD IS MINE - NUMBER HUNT    \n");
    printf("========================================\n");
    printf("   Think smart, guess right, win big!  \n");
    printf("========================================\n\n");

    do {
        secretnumber = rand() % 100 + 1; // 1 to 100
        attempts = 0;
        
        printf("I have chosen a secret number between 1 and 100.\n");
        printf("You have %d lives to guess it!\n", max_attempts);
        printf("----------------------------------------\n");

        while (attempts < max_attempts) {
            printf("\n[Lives left: %d] Enter your guess: ", max_attempts - attempts);
            scanf("%d", &guess);
            attempts++;

            if (guess == secretnumber) {
                printf("\n*** CONGRATULATIONS! ***\n");
                printf("You guessed it! The number was %d\n", secretnumber);
                printf("You won in %d attempts!\n", attempts);
                
                if (attempts <= 3) printf("Rank: GENIUS!\n");
                else if (attempts <= 5) printf("Rank: SMART!\n");
                else printf("Rank: LUCKY WINNER!\n");
                break;
            } 
            else if (guess < secretnumber) {
                printf("-> Too LOW! Try higher. ");
                if (secretnumber - guess <= 5) printf("You are very close!");
            } 
            else {
                printf("-> Too HIGH! Try lower. ");
                if (guess - secretnumber <= 5) printf("You are very close!");
            }

            if (attempts == max_attempts) {
                printf("\n\n--- GAME OVER ---\n");
                printf("You ran out of lives. The number was %d\n", secretnumber);
                printf("The world is not yours today!\n");
            }
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        printf("\n========================================\n\n");

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Goodbye!\n");
    return 0;
}