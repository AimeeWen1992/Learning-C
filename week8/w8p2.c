/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include"w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_NUM_PRODUCT);
    printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* inputLbs, double* convertToKg)
{
    double outputLbsConverKg = *inputLbs / LBS_CONVER_KG;

    if (convertToKg != NULL)
    {
        *convertToKg =  outputLbsConverKg;
    }

    return outputLbsConverKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* inputLbs, int* convertToGrams)
{
    double convertLbsKgArgument = 0;
    int outputLbsConverGram = (int)(convertLbsKg(inputLbs, &convertLbsKgArgument) * 1000);

    if (convertToGrams != NULL)
    {
        *convertToGrams = outputLbsConverGram;
    }

    return outputLbsConverGram;
}

// 10. convert lbs: kg and g
void convertLbs(const double* inputLbs, double* convertToKg, int* convertToGram)
{
    double convertLbsKgArgument = 0;
    double outputLbsConverKg = *inputLbs / LBS_CONVER_KG;
    int outputLbsConverGram = (int)(convertLbsKg(inputLbs, &convertLbsKgArgument) * 1000);

    if (convertToKg != NULL && convertToGram != NULL)
    {
        *convertToKg = outputLbsConverKg;
        *convertToGram = outputLbsConverGram;
    }
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gram, const int totalGram, double* numberOfServing)
{
    double serving = ((double)totalGram) / gram;

    if (numberOfServing != NULL)
    {
        *numberOfServing = serving;
    }

    return serving;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* numberOfServing, double* result)
{
    double costPerServing =  (*price) / (*numberOfServing);

    if (result != NULL)
    {
        *result = costPerServing;
    }

    return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* numberOfcalories, double* result) 
{
    double costPerCal = (*price) / (*numberOfcalories);

    if (result != NULL)
    {
        *result = costPerCal;
    }

    return costPerCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catFoodInfo)
{
    struct ReportData reportData;
    double totalCalories;

    reportData.sku = catFoodInfo.sku;
    reportData.price = catFoodInfo.price;
    reportData.weightByLbs = catFoodInfo.weight;
    reportData.calories = catFoodInfo.calories;

    reportData.weightByKg = convertLbsKg(&reportData.weightByLbs, &reportData.weightByKg);
    reportData.weightByGram = convertLbsG(&reportData.weightByLbs, &reportData.weightByGram);
    reportData.costPerServing = calculateServings(NUM_GRAMS, reportData.weightByGram, &reportData.servings);

    totalCalories = reportData.calories * reportData.servings;

    reportData.costPerServing = calculateCostPerServing(&reportData.price, &reportData.servings, &reportData.costPerServing);

    reportData.costCaloriesPerServing = calculateCostPerCal(&reportData.price, &totalCalories, &reportData.costCaloriesPerServing);

    return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int productOption)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
        reportData.sku, reportData.price, reportData.weightByLbs, reportData.weightByKg,
        reportData.weightByGram, reportData.calories, reportData.servings,
        reportData.costPerServing, reportData.costCaloriesPerServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo) 
{   
    printf("Final Analysis\n"
           "--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n", catFoodInfo.sku, catFoodInfo.price);
    putchar('\n');
    printf("Happy shopping!\n");
    putchar('\n');
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    struct CatFoodInfo catFoodInfoArr[MAX_NUM_PRODUCT] = { {0} };
    struct ReportData reportDataArry[MAX_NUM_PRODUCT] = { {0} };
    int i, cheapestIndex = 0;
    double cheapestPrice = 0.0;

    openingMessage(MAX_NUM_PRODUCT);

    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        catFoodInfoArr[i] = getCatFoodInfo(i + 1);
        putchar('\n');
        reportDataArry[i] = calculateReportData(catFoodInfoArr[i]);
    }
    
    displayCatFoodHeader();

    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        displayCatFoodData(catFoodInfoArr[i].sku, &catFoodInfoArr[i].price, &catFoodInfoArr[i].weight, catFoodInfoArr[i].calories);
    }
    putchar('\n');

    cheapestPrice = reportDataArry[0].costPerServing;

    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        if (reportDataArry[i].costPerServing <= cheapestPrice)
        {
            cheapestPrice = reportDataArry[i].costPerServing;
            cheapestIndex = i;
        }
    }

    displayReportHeader();

    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        displayReportData(reportDataArry[i], cheapestIndex);

        if (cheapestIndex == i)
        {
            printf(" ***\n");
        }
        else
        {
            printf("\n");
        }
    }
    putchar('\n');

    for (i = 0; i < MAX_NUM_PRODUCT; i++)
    {
        if (i == cheapestIndex)
        {
            displayFinalAnalysis(catFoodInfoArr[i]);
        }
    }
}

