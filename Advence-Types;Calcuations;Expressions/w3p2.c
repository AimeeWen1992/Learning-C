/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Rong-Yuan,Wen (Aimee)
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

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    //type,cream,bagWeight for staffs and customer for clients
    char type1 = 0, type2 = 0, type3 = 0, customerType = 0;
    char cream1 = 0, cream2 = 0, cream3 = 0, customerCream = 0;
    int bagWeight1 = 0, bagWeight2 = 0, bagWeight3 = 0, customerServing = 0;
    

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");

    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type1 == 'l' || type1 == 'L', type1 == 'm' || type1 == 'M', type1 == 'r' || type1 == 'R',
        bagWeight1, (bagWeight1 / GRAMS_IN_LBS),cream1 == 'y' || cream1 == 'Y');

    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        type2 == 'l' || type2 == 'L', type2 == 'm' || type2 == 'M', type2 == 'r' || type2 == 'R',
        bagWeight2, (bagWeight2 / GRAMS_IN_LBS), cream2 == 'y' || cream2 == 'Y');

    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        (type3 == 'l' || type3 == 'L'), (type3 == 'm' || type3 == 'M'), (type3 == 'r' || type3 == 'R'),
        bagWeight3, (bagWeight3 / GRAMS_IN_LBS), cream3 == 'y' || cream3 == 'Y');

    printf("\n");
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &customerServing);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n",
        ((type1 == 'l' || type1 == 'L') && (customerType == 'l' || customerType == 'L')) ||
        ((type1 == 'm' || type1 == 'M') && (customerType == 'm' || customerType == 'M')) ||
        ((type1 == 'r' || type1 == 'R') && (customerType == 'r' || customerType == 'R')),
        ((bagWeight1 == 250) && (customerServing > 0 && customerServing < 5)) ||
        ((bagWeight1 == 500) && (customerServing > 4 && customerServing < 10)) ||
        (bagWeight1 == 1000 && customerServing > 9),
        ((cream1 == 'y' || cream1 == 'Y') && (customerCream == 'y' || customerCream == 'Y')) ||
        ((cream1 == 'n' || cream1 == 'N') && (customerCream == 'n' || customerCream == 'N')));

    printf(" 2|       %d         |      %d      |   %d   |\n",
        (((type2 == 'l' || type2 == 'L') && (customerType == 'l' || customerType == 'L')) ||
        ((type2 == 'm' || type2 == 'M') && (customerType == 'm' || customerType == 'M')) ||
        ((type2 == 'r' || type2 == 'R') && (customerType == 'r' || customerType == 'R'))),
        ((bagWeight2 == 250) && (customerServing > 0 && customerServing < 5)) ||
        ((bagWeight2 == 500) && (customerServing > 4 && customerServing < 10)) ||
        (bagWeight2 == 1000 && customerServing > 9),
        ((cream2 == 'y' || cream2 == 'Y') && (customerCream == 'y' || customerCream == 'Y')) ||
        ((cream2 == 'n' || cream2 == 'N') && (customerCream == 'n' || customerCream == 'N')));

    printf(" 3|       %d         |      %d      |   %d   |\n",
        (((type3 == 'l' || type3 == 'L') && (customerType == 'l' || customerType == 'L')) ||
        ((type3 == 'm' || type3 == 'M') && (customerType == 'm' || customerType == 'M')) ||
        ((type3 == 'r' || type3 == 'R') && (customerType == 'r' || customerType == 'R'))),
        ((bagWeight3 == 250) && (customerServing > 0 && customerServing < 5)) ||
        ((bagWeight3 == 500) && (customerServing > 4 && customerServing < 10)) ||
        (bagWeight3 == 1000 && customerServing > 9),
        ((cream3 == 'y' || cream3 == 'Y') && (customerCream == 'y' || customerCream == 'Y')) ||
        ((cream3 == 'n' || cream3 == 'N') && (customerCream == 'n' || customerCream == 'N')));

    printf("\n");
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &customerServing);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");

    printf(" 1|       %d         |      %d      |   %d   |\n",
        ((type1 == 'l' || type1 == 'L') && (customerType == 'l' || customerType == 'L')) ||
        ((type1 == 'm' || type1 == 'M') && (customerType == 'm' || customerType == 'M')) ||
        ((type1 == 'r' || type1 == 'R') && (customerType == 'r' || customerType == 'R')),
        ((bagWeight1 == 250) && (customerServing > 0 && customerServing < 5)) ||
        ((bagWeight1 == 500) && (customerServing > 4 && customerServing < 10)) ||
        (bagWeight1 == 1000 && customerServing > 9),
        ((cream1 == 'y' || cream1 == 'Y') && (customerCream == 'y' || customerCream == 'Y')) ||
        ((cream1 == 'n' || cream1 == 'N') && (customerCream == 'n' || customerCream == 'N')));

    printf(" 2|       %d         |      %d      |   %d   |\n",
        (((type2 == 'l' || type2 == 'L') && (customerType == 'l' || customerType == 'L')) ||
        ((type2 == 'm' || type2 == 'M') && (customerType == 'm' || customerType == 'M')) ||
        ((type2 == 'r' || type2 == 'R') && (customerType == 'r' || customerType == 'R'))),
        ((bagWeight2 == 250) && (customerServing > 0 && customerServing < 5)) ||
        ((bagWeight2 == 500) && (customerServing > 4 && customerServing < 10)) ||
        (bagWeight2 == 1000 && customerServing > 9),
        ((cream2 == 'y' || cream2 == 'Y') && (customerCream == 'y' || customerCream == 'Y')) ||
        ((cream2 == 'n' || cream2 == 'N') && (customerCream == 'n' || customerCream == 'N')));

    printf(" 3|       %d         |      %d      |   %d   |\n",
        (((type3 == 'l' || type3 == 'L') && (customerType == 'l' || customerType == 'L')) ||
        ((type3 == 'm' || type3 == 'M') && (customerType == 'm' || customerType == 'M')) ||
        ((type3 == 'r' || type3 == 'R') && (customerType == 'r' || customerType == 'R'))),
        ((bagWeight3 == 250) && (customerServing > 0 && customerServing < 5)) ||
        ((bagWeight3 == 500) && (customerServing > 4 && customerServing < 10)) ||
        (bagWeight3 == 1000 && customerServing > 9),
        ((cream3 == 'y' || cream3 == 'Y') && (customerCream == 'y' || customerCream == 'Y')) ||
        ((cream3 == 'n' || cream3 == 'N') && (customerCream == 'n' || customerCream == 'N')));

    printf("\nHope you found a product that suits your likes!\n");

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/