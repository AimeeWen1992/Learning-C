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

# define LIMITED 10

int main(void)
{
    const double minIncome = 500.00, maxImcome = 400000.00, minCost = 100.00;
    int itemNum, selectionNum, priorityFilter;
    int months, years;
    int valid, i, countNote;
    double income, totalCost, priorityCost;
    int priority[LIMITED] = { 0 };
    double cost[LIMITED] = { 0.0 };
    char financeOption[LIMITED] = { '0' };


    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n");
    putchar('\n');


    do
    {
        valid = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < minIncome)
        {
            valid = 0;
            printf("ERROR: You must have a consistent monthly income of at least "
                "$%.2lf\n", minIncome);
        }
        else if (income > maxImcome)
        {
            valid = 0;
            printf("ERROR: Liar! I'll believe you if you enter a value no more than "
                "$%.2lf\n", maxImcome);
        }
        putchar('\n');
    } while (!valid);

    do
    {
        valid = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemNum);

        if (itemNum > LIMITED || itemNum < 1)
        {
            valid = 0;
            printf("ERROR: List is restricted to between 1 and %d items.\n", LIMITED);
        }
        putchar('\n');
    } while (!valid);


    for (i = 0; i < itemNum; i++)
    {
        printf("Item-%d Details:\n", i + 1);

        do{
            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);

            if (cost[i] < minCost)
            {
                valid = 0;
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
        }while (!valid);

        do{
            valid = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                valid = 0;
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (!valid);

        do{
            valid = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financeOption[i]);

            if (!(financeOption[i] == 'y' || financeOption[i] == 'n'))
            {
                valid = 0;
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!valid);
        
        putchar('\n');
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    totalCost = 0.0;
    for (i = 0; i < itemNum; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOption[i], cost[i]);
        totalCost += cost[i];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", totalCost);


    do
    {
        valid = 1;
        putchar('\n');
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n"
            " 2. By priority\n"
            " 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selectionNum);

        putchar('\n');

        switch (selectionNum)
        {
        case 0:
            break;

        case 1:
            valid = 0;
            break;

        case 2:
            do
            {
                valid = 1;
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityFilter);
                putchar('\n');
                if (priorityFilter < 1 || priorityFilter > 3)
                {
                    valid = 0;
                    printf("ERROR: Invalid filter selection.\n");
                }
            } while (!valid);

            valid = 0;
            break;

        default:
            valid = 0;
            printf("ERROR: Invalid menu selection.\n");
            break;
        }


        if (selectionNum == 1 || selectionNum == 2)
        {
            printf("====================================================\n");
            printf("Filter:   ");

            if (selectionNum == 1)
            {
                printf("All items\n");
            }
            else
            {
                printf("by priority (%d)\n", priorityFilter);
            }

            printf("Amount:   $");
            priorityCost = 0;
            countNote = 0;
            if (selectionNum == 1)
            {
                printf("%.2lf\n", totalCost);
                for (i = 0; i < itemNum; i++)
                {
                    if (financeOption[i] == 'y')
                    {
                        countNote++;
                    }
                }
            }
            else
            {
                for (i = 0; i < itemNum; i++)
                {
                    if (priority[i] == priorityFilter)
                    {
                        priorityCost += cost[i];
                        if (financeOption[i] == 'y')
                        {
                            countNote++;
                        }
                    }
                }
                printf("%.2lf\n", priorityCost);
            }

            if (selectionNum == 1)
            {
                years = ((((totalCost + 0.005) * 100) / ((income + 0.005) * 100))) / 12.0;

                if ((((totalCost + 0.005) * 100 / (income + 0.005) * 100)) / 12.0 - years > 0)
                {
                    months = ((((totalCost + 0.005) * 100) /
                            ((income + 0.005) * 100)) / 12.0 - years )* 12 + 1;
                }
                else
                {
                    months = ((((totalCost + 0.005) * 100) /
                            ((income + 0.005) * 100)) / 12.0 - years) * 12;
                }
               
            }
            else
            {
                years = ((((priorityCost + 0.005) * 100) / ((income + 0.005) * 100))) / 12.0;

                if ((((priorityCost + 0.005) * 100 / (income + 0.005) * 100)) / 12.0 - years > 0)
                {
                    months = ((((priorityCost + 0.005) * 100) /
                            ((income + 0.005) * 100)) / 12.0 - years) * 12 + 1;
                }
                else
                {
                    months = ((((priorityCost + 0.005) * 100) / 
                            ((income + 0.005) * 100)) / 12.0 - years) * 12;
                }
            }

            printf("Forecast: %d years, %d months\n", years, months);

            if (countNote > 0)
            {
                printf("NOTE: Financing options are available on some items.\n"
                    "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n");
        }
    }while (!valid);


        printf("Best of luck in all your future endeavours!\n");


        return 0;
}