#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int input_getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int returnValue = -1;
    int convertedNumber;
    int counter = 0;
    char stringNumber[STRING_AS_INT32_MAX];

    if(hiLimit >= lowLimit && input != NULL && message != NULL && eMessage != NULL)
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
        
        if(convertedNumber != 0)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}
