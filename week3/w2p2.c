/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Rong-Yuan,Wen(Aimee)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    double smallSize = 0, medSize = 0, larSize = 0;
    int numPat = 0, numTom = 0, numSal = 0;
    int subTotal = 0, taxes = 0, total = 0;
    int sumOfsubtotal = 0, sumOftaxes = 0, sumOftotal = 0;
    int numToonies, numLoonies, numQuarters, numDimes, numNickels, numPennies = 0;
    int balance = 0;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallSize);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &medSize);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &larSize);
    
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
    scanf("%d", &numPat);
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numTom);
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numSal);
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    
    subTotal = (int)(smallSize * 100) * numPat; 
    sumOfsubtotal += subTotal; 
    taxes = (int)((TAX * subTotal)+ 0.5); 
    sumOftaxes = taxes; 
    total = subTotal + taxes;
    sumOftotal = total;

    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallSize, numPat, subTotal / 100.0, taxes / 100.0, total / 100.0);

    subTotal = (int)(medSize * 100) * numSal;
    sumOfsubtotal += subTotal;
    taxes = (int)((TAX * subTotal) + 0.5);
    sumOftaxes += taxes;
    total = subTotal + taxes;
    sumOftotal += total;

    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, medSize, numSal, subTotal / 100.0, taxes / 100.0, total / 100.0);

    subTotal = (int)(larSize * 100) * numTom;
    sumOfsubtotal += subTotal;
    taxes = (int)((TAX * subTotal) + 0.5);
    sumOftaxes += taxes;
    total = subTotal + taxes;
    sumOftotal += total;

    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, larSize, numTom, subTotal/100.0, taxes/100.0, total/100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", sumOfsubtotal / 100.0, sumOftaxes / 100.0, sumOftotal / 100.0);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", sumOfsubtotal / 100.0);

    balance = sumOfsubtotal;
    numToonies = balance / 200;
    balance = balance % 200;

    printf("Toonies  %3d %9.4lf\n", numToonies, balance / 100.0);

    numLoonies = balance / 100;
    balance = balance % 100;
 
    printf("Loonies  %3d %9.4lf\n", numLoonies, balance / 100.0);
 
    numQuarters = balance / 25;
    balance = balance % 25;
  
    printf("Quarters %3d %9.4lf\n", numQuarters, balance / 100.0);
    
    numDimes = balance / 10;
    balance = balance % 10;
    
    printf("Dimes    %3d %9.4lf\n", numDimes, balance / 100.0);
    
    numNickels =balance / 5;
    balance = balance % 5;
    
    printf("Nickels  %3d %9.4lf\n", numNickels, balance / 100.0);

    numPennies = balance / 1;
    balance = balance % 1;
    
    printf("Pennies  %3d %9.4lf\n", numPennies, balance / 100.0);
    printf("\nAverage cost/shirt: $%.4lf\n\n", ((((double)sumOfsubtotal / (double)(numPat + numSal + numTom))+0.005)/100.0));
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", sumOftotal/100.0);

    balance = sumOftotal;
    numToonies = balance / 200;
    balance = balance % 200;

    printf("Toonies  %3d %9.4lf\n", numToonies, balance / 100.0);

    numLoonies = balance / 100;
    balance = balance % 100;

    printf("Loonies  %3d %9.4lf\n", numLoonies, balance / 100.0);

    numQuarters = balance / 25;
    balance = balance % 25;

    printf("Quarters %3d %9.4lf\n", numQuarters, balance / 100.0);

    numDimes = balance / 10;
    balance = balance % 10;

    printf("Dimes    %3d %9.4lf\n", numDimes, balance / 100.0);

    numNickels = balance / 5;
    balance = balance % 5;

    printf("Nickels  %3d %9.4lf\n", numNickels, balance / 100.0);

    numPennies = balance / 1;
    balance = balance % 1;

    printf("Pennies  %3d %9.4lf\n", numPennies, balance / 100.0);
    printf("\nAverage cost/shirt: $%.4lf\n", ((((double)sumOftotal / (double)(numPat + numSal + numTom)) + 0.005) / 100.0));

    return 0;
}