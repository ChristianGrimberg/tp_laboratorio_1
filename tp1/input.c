#include "input.h"

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

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit >= INT32_MIN && hiLimit <= INT32_MAX
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
            convertedNumber = atoi(stringNumber);
            
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
