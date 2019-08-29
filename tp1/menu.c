#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void clearBuffer(void)
{
    char memoryBuffer = '\n';

    /**< Mientras que en el buffer no exista un Enter, la funcion getchar toma sus valores */
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
        clearBuffer();
    } while (!numberOption || (userOption < minNumber || userOption > maxNumber));

    return userOption;
}

/** \brief
 *
 * \param void
 * \return void
 *
 */
void clearScreen(void)
{
    #if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
    {
        system("clear");
    }
    #else
    {
        system("cls");
    }
    #endif
}

void pauseScreen(void)
{
    printf("Presione la tecla Enter para continuar...");
    /**< Metodo de vaciado de buffer de entrada del teclado para diferentes SO */
    setbuf(stdin, NULL);
    getchar();
}

int mainMenu(double x, double y)
{
    int option;

    clearScreen();

    /**< Impresion del menu con los valores dentro */
    printf("===================================\n");
    printf("1- Ingresar 1er operando (A=%.2f)\n", x);
    printf("2- Ingresar 2do operando (B=%.2f)\n", y);
    printf("3- Calcular la suma (%.2f + %.2f)\n", x, y);
    printf("4- Calcular la resta (%.2f - %.2f)\n", x, y);
    printf("5- Calcular la division (%.2f / %.2f)\n", x, y);
    printf("6- Calcular la multiplicacion (%.2f * %.2f)\n", x, y);
    printf("7- Calcular el factorial (%.2f!)\n", x);
    printf("8- Calcular el factorial (%.2f!)\n", y);
    printf("9- Salir\n");
    printf("===================================\n");

    option = getIntOfARange(OPTION_MIN, OPTION_MAX);

    return option;
}


