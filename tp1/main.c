/*******************************************************************
 * Programa: Calculadora de aplicacion de consola de C
 *
 * Objetivo:
 *      Realizar una calculadora que realice operaciones de suma,
 *      resta, multiplicacion, division y factorial de dos numeros.
 *
 * Version: 0.1 - 25 de agosto de 2019
 * Autor: Christian Grimberg
 *
 ********************************************************************/
#include <stdio.h>
#include "menu.h"
#define TRUE 1

int main()
{
    /**< Operandos de entrada del usuario */
    float operand1 = 0;
    float operand2 = 0;
    int option; /**< Opcion para elegir del menu principal */

    do
    {
        option = mainMenu(operand1, operand2);

        if(option == OPTION_MAX)
        {
            break;
        }

        switch(option)
        {
            case 1:
                printf("Prueba con caso 1\n");
                break;
        }

        pauseScreen();

    }while(TRUE);

    return 0;
}
