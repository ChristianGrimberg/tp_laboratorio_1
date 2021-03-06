#include "input.h"

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero decimal.
 *
 * \param stringValue char* Direccion de la cadena a evaluar
 * \return int Si es un numero decimal retorna [0] si no [-1]
 *
 */
static int isNumber(char* stringValue);

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero flontante.
 *
 * \param stringValue char* Direccion de la cadena a evaluar
 * \return int Si es un numero flotante retorna [0] si no [-1]
 *
 */
static int isFloat(char* stringValue);

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
    int numberIndicator = -1;
    int convertedNumber;

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit > INT_MIN && hiLimit < INT_MAX
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

            if(!numberIndicator)
            {
                convertedNumber = atoi(stringNumber);
            }
        } while(numberIndicator ||
            (!numberIndicator && ((convertedNumber < lowLimit || convertedNumber > hiLimit))));

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
    int numberIndicator = -1;

    float convertedNumber;

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit >= -FLT_MAX && hiLimit <= FLT_MAX
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
            numberIndicator = isFloat(stringNumber);

            if(!numberIndicator)
            {
                convertedNumber = atof(stringNumber);
            }
        } while(numberIndicator ||
            (!numberIndicator && (convertedNumber < lowLimit || convertedNumber > hiLimit)));

        if(convertedNumber >= lowLimit && convertedNumber <= hiLimit)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getNumberType(float number)
{
    int returnEvaluation = 0; /**< Se almacena el tipo numerico */
    float auxNumber; /**< Se almacena la parte entera de un numero */

    auxNumber = (float)((int)number); /**< Se obtiene la parte entera del numero */

    /**< Diferencias en un numero con decimales y su parte entera */
    if (number == auxNumber)
    {
        returnEvaluation = 1; /**< Indica tipo de dato entero */
    }
    else
    {
        if (number - auxNumber != 0.0f)
        {
            returnEvaluation = 2; /**< Indica tipo de dato flotante */
        }
    }

    return returnEvaluation;
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

static int isFloat(char* stringValue)
{
    int returnValue = -1;
    int pointerCounter = 0;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        if(i == 0 && ((int)stringValue[0] == (int)'-'
        || (int)stringValue[0] == (int)'+'))
        {
            i = 1;
        }

        if(stringValue[i] == '.')
        {
            pointerCounter++;
        }
        else
        {
            if((int)stringValue[i] >= (int)'0'
                && (int)stringValue[i] <= (int)'9' && pointerCounter <= 1)
            {
                returnValue = 0;
            }
            else
            {
                returnValue = -1;
                break;
            }
        }
        i++;
    }

    return returnValue;
}
