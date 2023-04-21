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

#include<stdio.h>

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PRODUCT 3
#define NUM_GRAMS 64
#define LBS_CONVER_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    double weight;
    int calories;
};

struct ReportData
{
    int sku;
    double price;
    double weightByLbs;
    int calories;
    double weightByKg;
    int weightByGram;
    double servings;
    double costPerServing;
    double costCaloriesPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* inputIntNumber);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* inputDoubleNumber);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProduct);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const double* weight, const int calories);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* inputLbs, double* convertToKg);

// 9. convert lbs: g
int convertLbsG(const double* inputLbs, int* convertToGrams);

// 10. convert lbs: kg / g
void convertLbs(const double* inputLbs, double* convertToKg, int* convertToGram);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gram, const int totalGram, double* numberOfServing);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* numberOfServing, double* result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* numberOfcalories, double* result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int productOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

