// 11

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int MyRndom(int max)
{
    int x;
    x = rand() % max + 1;
    return x;
}

int main()
{
    int balance, bet, guess, dice;

    srand(getpid());

    balance = 1000;

    while (1)
    {
        printf("Make your bet: ");
        fflush(stdout);
        scanf("%d", &bet);

        printf("Make your guess (1-6, and 0 means quit): \n");
        scanf("%d", &guess);

        if (guess == 0)
            return 0;

        printf("Throwing the dice...\n");
        sleep(2);
        dice = MyRndom(6);
        printf("Dice results:  %d\n", dice);

        if (guess != dice)
        {
            balance -= bet;
            printf("Sorry, you lost!!\n");
        }
        else
        {
            bet *= 3;
            balance += bet;
            printf("You won - congratulations!\n");
        }

        if (balance == 0)
        {
            printf("GAME OVER\n");
            return 0;
        }

        printf("Balance: $%d\n", balance);
    }

    return 0;
}