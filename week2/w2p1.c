/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Rong-Yuan, Wen (Aimee)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    double smallSize =0, medSize=0, larSize=0;
    int numBuying;
    double total, taxes;

    
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallSize);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medSize);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &larSize);

    //make double type precise with twe decimals
    smallSize = smallSize * 100;
    smallSize = (int)smallSize / 100.0;
    medSize = medSize * 100;
    medSize = (int)medSize / 100.0;
    larSize = larSize * 100;
    larSize = (int)larSize / 100.0;

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", smallSize);
    printf("MEDIUM : $%.2lf\n", medSize);
    printf("LARGE  : $%.2lf\n", larSize);
    printf("\nPatty's shirt size is '%c'\n", patSize);


    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numBuying);
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numBuying);
    //cal subtotal
    total = numBuying * smallSize;

    printf("Sub-total: $%8.4lf\n", total);
    //cal only tax
    taxes = ((total * TAX)+0.005) * 100;
    taxes = (int) taxes / 100.0;

    printf("Taxes    : $%8.4lf\n", taxes);
    //cal total including taxes
    total += taxes;

    printf("Total    : $%8.4lf\n",total);


    return 0;
}