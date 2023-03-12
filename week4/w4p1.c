/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    int count = 0;
    int inputNumber = 0;
    char inputChar = 0;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    putchar('\n');

    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &inputChar, &inputNumber);

        if (inputChar == 'D')
        {
            if (inputNumber > 2 && inputNumber < 21)
            {
                count = 0;
                printf("DO-WHILE: ");

                do
                {
                    putchar('D');
                    count++;
                } while (count < inputNumber);
                putchar('\n');
                putchar('\n');
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

        else if (inputChar == 'W')
        {
            if (inputNumber > 2 && inputNumber < 21)
            {
                count = 0;
                printf("WHILE   : ");

                while (count < inputNumber)
                {
                    putchar('W');
                    count++;
                }
                putchar('\n');
                putchar('\n');
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

        else if (inputChar == 'F')
        {
            if (inputNumber > 2 && inputNumber < 21)
            {
                printf("FOR     : ");

                for (count = 0; count < inputNumber; count++)
                {
                    putchar('F');
                }
                putchar('\n');
                putchar('\n');
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

        else if (inputChar == 'Q' && (inputNumber > 0 || inputNumber < 0))
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
            putchar('\n');
        }

        else
        {
            if (!(inputChar == 'Q' && inputNumber == 0))
            {
                printf("ERROR: Invalid entered value(s)!\n");
                putchar('\n');
            }
        }

    } while (!(inputChar == 'Q' && inputNumber == 0));

    putchar('\n');
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}