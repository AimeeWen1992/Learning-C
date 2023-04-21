/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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


// System Libraries
#include<stdio.h>

// User Libraries
#include"w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* inputIntNumber)
{
    int inputNumber;
    do {

        scanf("%d", &inputNumber);

        if (inputNumber <= 0) 
        {
            printf("ERROR: Enter a positive value: ");
        }

    } while (inputNumber <= 0);

    if (inputIntNumber != NULL)
    {
        *inputIntNumber = inputNumber;
    }
        return inputNumber;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* inputDoubleNumber)
{
    double inputNumber;
    do {

        scanf("%lf", &inputNumber);

        if (inputNumber <= 0.0)
        {
            printf("ERROR: Enter a positive value: ");
        }

    } while (inputNumber <= 0.0);

    if (inputDoubleNumber != NULL)
    {
        *inputDoubleNumber = inputNumber;
    }

    return inputNumber;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProduct)
{
    printf("Cat Food Cost Analysis\n"
           "======================\n");
    putchar('\n');
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProduct);
    printf("NOTE: A 'serving' is %dg\n",NUM_GRAMS);
    putchar('\n');
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
    struct CatFoodInfo catFoodInfo = { 0 };
   
    printf("Cat Food Product #%d\n"
           "--------------------\n", sequenceNum);

    printf("SKU           : ");
    catFoodInfo.sku = getIntPositive(&catFoodInfo.sku);


    printf("PRICE         : $");
    catFoodInfo.price = getDoublePositive(NULL);


    printf("WEIGHT (LBS)  : ");
    catFoodInfo.weight = getDoublePositive(NULL);
    
    printf("CALORIES/SERV.: ");
    catFoodInfo.calories = getIntPositive(&catFoodInfo.calories);

    return catFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories)
{   

    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo catFoodInfoArr[MAX_NUM_PRODUCT] = { {0} };
    int i;

    openingMessage(MAX_NUM_PRODUCT);
    
    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        catFoodInfoArr[i] = getCatFoodInfo(i+1);
        putchar('\n');
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        displayCatFoodData(catFoodInfoArr[i].sku, &catFoodInfoArr[i].price, &catFoodInfoArr[i].weight, catFoodInfoArr[i].calories);
    }
    putchar('\n');
}



