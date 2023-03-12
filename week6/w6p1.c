/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Rong-Yuan,Wen
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

# define LIMITEDITEM 10
 
int main(void)
{
    const double minIncome = 500.00, maxImcome = 400000.00, minCost = 100.00;
    int itemNum;
    int goAgain,i;
    double income, totalCost;
    int priority[LIMITEDITEM] = { 0 };
    double cost[LIMITEDITEM] = { 0.0 };
    char financeOption[LIMITEDITEM] = { '0' };

    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n");
    putchar('\n');

    goAgain = 1;
    do 
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least "
                   "$%.2lf\n", minIncome);
        }
        else if (income > maxImcome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than "
                   "$%.2lf\n", maxImcome);
        }
        else
        {
            while (goAgain)
            {
                putchar('\n');
                printf("How many wish list items do you want to forecast?: ");
                scanf("%d", &itemNum);
                if (itemNum > LIMITEDITEM || itemNum < 1)
                {
                    printf("ERROR: List is restricted to between 1 and %d items.\n", LIMITEDITEM);
                }
                else
                {
                    goAgain = 0;
                }
            }
        }
        putchar('\n');
    } while (goAgain);

    for (i = 0; i < itemNum; i++)
    {
        printf("Item-%d Details:\n", i + 1);
            
        goAgain = 1;
        while (goAgain)
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n",minCost);
            }
            else
            {
                while (goAgain)
                {
                    printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
                    scanf("%d", &priority[i]);

                    if (priority[i] < 1 || priority[i] > 3)
                    {
                        printf("      ERROR: Value must be between 1 and 3\n");
                    }
                    else
                    {
                        while (goAgain)
                        {
                            printf("   Does this item have financing options? [y/n]: ");
                            scanf(" %c", &financeOption[i]);

                            if (!(financeOption[i] == 'y' || financeOption[i] == 'n'))
                            {
                                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                            }
                            else
                            {
                                goAgain = 0;
                            }
                        }
                    }
                }
            }
        }
        putchar('\n');
 
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    totalCost = 0.0;
    for (i = 0; i < itemNum; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, priority[i], financeOption[i], cost[i]);
        totalCost += cost[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n",totalCost);
    printf("Best of luck in all your future endeavours!\n");


    return 0;
}