/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Rong-Yuan, Wen
Student ID#: 114556228
Email      : rwen1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10

struct PlayerInfo
{
    char playerSynmbol;
    int lives;
    int treasureNum;
    int historyPosition[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int pathLength;
    int movesAllowed;
    int bombPosition[MAX_PATH_LENGTH];
    int treasurePosition[MAX_PATH_LENGTH];
};


int main(void)
{
    struct PlayerInfo playerInfo = { '0',0,0,{0} };
    struct GameInfo gameInfo = { 0, 0, {0}, {0} };
    const int maxLives = 10;
    const int multiplePathLength = 5;
    int maxMoves, remindMoves, nextStep = 0;
    int i, j, valid;
    int isGameOver = 0;

    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n");
    putchar('\n');
    printf("PLAYER Configuration\n"
           "--------------------\n");
    
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &playerInfo.playerSynmbol);

    do
    {
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &playerInfo.lives);

        if (playerInfo.lives > maxLives || playerInfo.lives < 1)
        {
            valid = 0;
            printf("     Must be between 1 and %d!\n", maxLives);
        }

    } while (!valid);

    printf("Player configuration set-up is complete\n");
    putchar('\n');
    printf("GAME Configuration\n"
           "------------------\n");

    do
    {
        valid = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ",
            multiplePathLength, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &gameInfo.pathLength);

        if (gameInfo.pathLength % multiplePathLength != 0 ||
            gameInfo.pathLength > MAX_PATH_LENGTH ||
            gameInfo.pathLength < MIN_PATH_LENGTH)
        {
            valid = 0;
            printf("     Must be a multiple of %d and between %d-%d!!!\n",
                multiplePathLength, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }

    } while (!valid);

    maxMoves = gameInfo.pathLength * 0.75;

    do
    {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameInfo.movesAllowed);

        if (gameInfo.movesAllowed < playerInfo.lives || gameInfo.movesAllowed > maxMoves)
        {
            valid = 0;
            printf("    Value must be between %d and %d\n", playerInfo.lives, maxMoves);
        }

    } while (!valid);

    // :::::::::
    remindMoves = gameInfo.movesAllowed;

    putchar('\n');
    printf("BOMB Placement\n"
           "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
        "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
        multiplePathLength, gameInfo.pathLength);
/*
    for (i = 0; i < gameInfo.pathLength; i)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (j = 0; j < multiplePathLength; j++)
        {
            scanf("%d", &gameInfo.bombPosition[i]);
            i++;

        }
    }
*/


    for (i = 0; i < gameInfo.pathLength / multiplePathLength; i++)
    {
        printf("   Positions [%2d-%2d]: ", 1 * (i + 1), (i + multiplePathLength)*i);
        scanf("%d", &gameInfo.bombPosition[i]);
         
    }


    printf("BOMB placement set\n");
    putchar('\n');

    printf("TREASURE Placement\n"
        "------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
        multiplePathLength, gameInfo.pathLength);

    for (i = 0; i < gameInfo.pathLength; i)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        for (int j = 0; j < multiplePathLength; j++)
        {
            scanf("%d", &gameInfo.treasurePosition[i]);
            i++;

        }
    }

    printf("TREASURE placement set\n");
    putchar('\n');
    printf("GAME configuration set-up is complete...\n");
    putchar('\n');
    printf("------------------------------------\n"
        "TREASURE HUNT Configuration Settings\n"
        "------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol   : %c\n", playerInfo.playerSynmbol);
    printf("   Lives    : %d\n", playerInfo.lives);
    printf("   Treasure : [ready for gameplay]\n");
    printf("   History  : [ready for gameplay]\n");
    putchar('\n');
    printf("   Game:\n");
    printf("   Path Length: %d\n", gameInfo.pathLength);
    printf("   Bombs      : ");

    for (i = 0; i < gameInfo.pathLength; i++)
    {
        printf("%d", gameInfo.bombPosition[i]);
    }
    putchar('\n');

    printf("   Treasure   : ");

    for (i = 0; i < gameInfo.pathLength; i++)
    {
        printf("%d", gameInfo.treasurePosition[i]);
    }
    putchar('\n');

    printf("====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n");


//part-2-----------------------------------------------------------------

    while (isGameOver == 0)
    {
        // Record what's the player's position
        printf("  ");

        for (i = 0; i < gameInfo.pathLength; i++)
        {
            if (gameInfo.movesAllowed - remindMoves != 0 && nextStep - 1 == i)
            {
                printf("%c", playerInfo.playerSynmbol);
            }
            else
            {
                printf(" ");
            }
        }
        putchar('\n');
        
        // Reveal history position and check what's hidden behind
        printf("  ");

        for (i = 0; i < gameInfo.pathLength; i++)
        {
            if (playerInfo.historyPosition[i] != 0)
            {
                if (gameInfo.bombPosition[i] == 1)
                {
                    if (gameInfo.treasurePosition[i] == 1)
                    {
                        printf("&");
                    }
                    else
                    {
                        printf("!");
                    }
                }
                else if (gameInfo.bombPosition[i] == 0)
                {
                    if (gameInfo.treasurePosition[i] == 0)
                    {
                        printf(".");
                    }
                    else
                    {
                        printf("$");
                    }
                }
            }
            else
            {
                printf("-");
            }
        }
        putchar('\n');


        // Position ruler (major), promot evey 10 postions..
        printf("  ");

        for (i = 0; i < gameInfo.pathLength; i++)
        {
            if ((i+1) % 10 == 0)
            {
                printf("%d", (i+1) / 10);
            }
            else
            {
                printf("|");
            }
        }
        putchar('\n');
        
        // Position ruler(minor), starting from 1 to 9..
        printf("  ");

        for (i = 0; i < gameInfo.pathLength; i++)
        {
            printf("%d", (i+1) % 10);
        }

        

//-------------------------------------------------------------------------------



        putchar('\n');
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  | Moves Remaining: %2d\n",
                 playerInfo.lives, playerInfo.treasureNum, remindMoves);
        printf("+---------------------------------------------------+\n");

        if (playerInfo.lives == 0 || remindMoves == 0)
        {
            isGameOver = 1;
        }

        if (isGameOver == 0)
        {

            do
            {
                valid = 1;
                printf("Next Move [1-%d]: ", gameInfo.pathLength);
                scanf("%d", &nextStep);

                if (nextStep < 1 || nextStep > gameInfo.pathLength)
                {
                    valid = 0;
                    printf("  Out of Range!!!\n");
                }

            } while (!valid);

            putchar('\n');

            printf("===============> ");

            if (playerInfo.historyPosition[nextStep - 1] == 1)
            {
                printf(" Dope! You've been here before!\n");
            }
            else
            {
                playerInfo.historyPosition[nextStep - 1] = 1;

                if (gameInfo.bombPosition[nextStep - 1] == 0)
                {
                    if (gameInfo.treasurePosition[nextStep - 1] == 0)
                    {
                        printf("[.] ...Nothing found here... [.]\n");
                    }
                    else
                    {
                        printf("[$] $$$ Found Treasure! $$$ [$]\n");
                        playerInfo.treasureNum++;
                    }
                }
                else
                {
                    printf("[!] !!! BOOOOOM !!! [!]\n");
                    playerInfo.lives--;

                    if (gameInfo.treasurePosition[nextStep - 1] == 1)
                    {
                        printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                        playerInfo.treasureNum++;
                    }
                }
                remindMoves--;
            }
            putchar('\n');

            if (playerInfo.lives < 1)
            {
                printf("No more LIVES remaining!\n");
                putchar('\n');
            }
            else if (remindMoves < 1)
            {
                printf("No more MOVES remaing!\n");
                putchar('\n');
            }

        }
    }

    putchar('\n');
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    putchar('\n');
    printf("You should play again and try to beat your score!\n");

    return 0;
}
