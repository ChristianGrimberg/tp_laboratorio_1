#include "input.h"

static int isNumber(char* stringValue);

void input_clearBuffer()
{
    char memoryBuffer = '\n';

    /**< Mientras que en el buffer no exista un Enter
    la funcion getchar toma sus valores */
    while (getchar() != memoryBuffer)
    {
        /**< No requiere implementacion */
    }
}

int input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int returnValue = -1;
    int counter = 0;
    int convertedNumber;
    int numberIndicator = -1;

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit >= INT32_MIN && hiLimit <= INT32_MAX
        && input != NULL && message != NULL && eMessage != NULL)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s: ", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s: ", eMessage);
                }
            }

            scanf("%s", stringNumber);
            numberIndicator = isNumber(stringNumber);

            if(numberIndicator == 0)
            {
                convertedNumber = atoi(stringNumber);
            }
        } while(numberIndicator != 0 ||
            (numberIndicator == 0 && (convertedNumber < lowLimit || convertedNumber > hiLimit)));

        if(convertedNumber >= lowLimit && convertedNumber <= hiLimit)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    int returnValue = -1;
    int counter = 0;

    float convertedNumber;

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit >= FLT_MIN && hiLimit <= FLT_MAX
        && input != NULL && message != NULL && eMessage != NULL)
    {
        do
        {
            if(counter == 0)
            {
                printf("%s: ", message);
            }
            else
            {
                printf("%s: ", eMessage);
            }

            scanf("%s", stringNumber);
            convertedNumber = atof(stringNumber);

            counter++;
        } while (convertedNumber < lowLimit || convertedNumber > hiLimit);
        
        if(counter > 0)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

static int isNumber(char* stringValue)
{
    int returnValue = -1;
    char charAux;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        charAux = stringValue[i];
        if(i == 0 && (charAux == '-' || charAux == '+'))
        {
            i = 1;
        }
        
        if((int)charAux >= (int)'0' && (int)charAux <= (int)'9')
        {
            returnValue = 0;
        }
        else
        {
            returnValue = -1;
            break;
        }
        i++;
    }

    return returnValue;
}
