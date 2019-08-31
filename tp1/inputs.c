#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

void menu_clearBuffer()
{
    char memoryBuffer = '\n';

    /**< Mientras que en el buffer no exista un Enter
    la funcion getchar toma sus valores */
    while (getchar() != memoryBuffer)
    {
        /**< No requiere implementacion */
    }
}

int getIntOfARange(int minNumber, int maxNumber)
{
    int userOption = 0;
    int numberOption;

    do
    {
        printf("Ingrese un valor del [%d al %d]: ", minNumber, maxNumber);
        numberOption = scanf("%d", &userOption);
        menu_clearBuffer();
    } while (!numberOption || (userOption < minNumber || userOption > maxNumber));

    return userOption;
}
