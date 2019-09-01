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
#include "menu.h"

int main()
{
    /**< Operandos de entrada del usuario */
    float operand1 = 0;
    float operand2 = 0;
    int option; /**< Opcion para elegir del menu principal */
    int lifeCycle;

    do
    {
        lifeCycle = menu_main(&option, operand1, operand2);

        if(option == OPTION_MAX || option == OPTION_ERROR)
        {
            break;
        }

        switch(option)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
        }
    } while(lifeCycle == 0);

    return 0;
}
