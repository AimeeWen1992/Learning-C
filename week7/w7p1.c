/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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
#define MULTIPLE_PATH_LENGTH 5

struct PlayerInfo
{
    char playerSynmbol;
    int lives;
    int treasure;
    int historyPosition[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int pathLength;
    int moveAllow;
    int bombPosition[MAX_PATH_LENGTH];
    int treasurePosition[MAX_PATH_LENGTH];
};


int main(void)
{
    struct PlayerInfo playerInfo = { '0',0,0,{0} };
    struct GameInfo gameInfo = { 0, 0, {0}, {0} };
    const int maxLives = 10;
    const float maxMoveRate = 0.75f;
    int maxMoves;
    int i, j, valid;

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
                MULTIPLE_PATH_LENGTH,MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &gameInfo.pathLength);

        if (gameInfo.pathLength % MULTIPLE_PATH_LENGTH != 0 || 
            gameInfo.pathLength > MAX_PATH_LENGTH || 
            gameInfo.pathLength < MIN_PATH_LENGTH)
        {
            valid = 0;
            printf("     Must be a multiple of %d and between %d-%d!!!\n", 
                   MULTIPLE_PATH_LENGTH, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }

    } while (!valid);

    maxMoves = gameInfo.pathLength * maxMoveRate;
    
    do
    {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gameInfo.moveAllow);

        if (gameInfo.moveAllow < playerInfo.lives || gameInfo.moveAllow > maxMoves)
        {
            valid = 0;
            printf("    Value must be between %d and %d\n", playerInfo.lives, maxMoves);
        }

    } while (!valid);
    putchar('\n');

    printf("BOMB Placement\n"
           "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
            MULTIPLE_PATH_LENGTH, gameInfo.pathLength);

    for (i = 0; i < gameInfo.pathLength; i += MULTIPLE_PATH_LENGTH)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE_PATH_LENGTH);

        for (j = 0; j < MULTIPLE_PATH_LENGTH; j++)
        {
            scanf("%d", &gameInfo.bombPosition[i + j]);
        }
    }

    printf("BOMB placement set\n");

    putchar('\n');

    printf("TREASURE Placement\n"
           "------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           MULTIPLE_PATH_LENGTH,gameInfo.pathLength);

    for (i = 0; i < gameInfo.pathLength; i += MULTIPLE_PATH_LENGTH)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE_PATH_LENGTH);
        for (j = 0; j < MULTIPLE_PATH_LENGTH; j++)
        {
            scanf("%d", &gameInfo.treasurePosition[i + j]);
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
    printf("   Symbol     : %c\n", playerInfo.playerSynmbol);
    printf("   Lives      : %d\n", playerInfo.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    putchar('\n');

    printf("Game:\n");
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
    putchar('\n');
    printf("====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n");

    return 0;
}
