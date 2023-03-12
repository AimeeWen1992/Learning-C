/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Rong-Yuan,Wen
Student ID#: 114556228
Email      : rwen1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0;
    int pickNumber = 0, shoppingAgain = 0;


    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (apples < 0);
        putchar('\n');

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (oranges < 0);
        putchar('\n');

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (pears < 0);
        putchar('\n');

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (tomatoes < 0);
        putchar('\n');

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }

        } while (cabbages < 0);
        putchar('\n');

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        putchar('\n');


        if (apples != 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &pickNumber);

                if (pickNumber > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                }
                else if (pickNumber <= apples && pickNumber > 0)
                {
                    if (pickNumber < apples)
                    {
                        printf("Looks like we still need some APPLES...\n");
                        apples -= pickNumber;
                    }
                    else
                    {
                        apples -= pickNumber;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (apples != 0);

            printf("Great, that's the apples done!\n");
            putchar('\n');
        }

        if (oranges != 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickNumber);

                if (pickNumber > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                }
                else if (pickNumber <= oranges && pickNumber > 0)
                {
                    if (pickNumber < oranges)
                    {
                        printf("Looks like we still need some ORANGES...\n");
                        oranges -= pickNumber;
                    }
                    else
                    {
                        oranges -= pickNumber;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (oranges != 0);

            printf("Great, that's the oranges done!\n");
            putchar('\n');
        }

        if (pears != 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickNumber);

                if (pickNumber > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else if (pickNumber <= pears && pickNumber > 0)
                {
                    if (pickNumber < pears)
                    {
                        printf("Looks like we still need some PEARS...\n");
                        pears -= pickNumber;
                    }
                    else
                    {
                        pears -= pickNumber;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (pears != 0);

            printf("Great, that's the pears done!\n");
            putchar('\n');
        }

        if (tomatoes != 0)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickNumber);

                if (pickNumber > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else if (pickNumber <= tomatoes && pickNumber > 0)
                {
                    if (pickNumber < tomatoes)
                    {
                        printf("Looks like we still need some TOMATOES...\n");
                        tomatoes -= pickNumber;
                    }
                    else
                    {
                        tomatoes -= pickNumber;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (tomatoes != 0);

            printf("Great, that's the tomatoes done!\n");
            putchar('\n');
        }

        if (cabbages != 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickNumber);

                if (pickNumber > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else if (pickNumber <= cabbages && pickNumber > 0)
                {
                    if (pickNumber < cabbages)
                    {
                        printf("Looks like we still need some CABBAGES...\n");
                        cabbages -= pickNumber;
                    }
                    else
                    {
                        cabbages -= pickNumber;
                    }
                }
                else
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            } while (cabbages != 0);

            printf("Great, that's the cabbages done!\n");
            putchar('\n');
        }

        printf("All the items are picked!\n");
        putchar('\n');
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shoppingAgain);
        putchar('\n');

    } while (shoppingAgain!=0);

    printf("Your tasks are done for today - enjoy your free time!\n");


    return 0;
}