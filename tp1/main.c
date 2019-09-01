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
#include "calculator.h"

int main()
{
    /**< Operandos de entrada del usuario */
    float operand1 = 0;
    float operand2 = 0;
    float auxValue = 0;

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
                if(!input_getFloat(&auxValue, "Ingrese el primer operando",
                    "Valor incorrecto, intente nuevamente", FLT_MIN, FLT_MAX))
                {
                    operand1 = auxValue;
                }
                break;
            case 2:
                if(!input_getFloat(&auxValue, "Ingrese el segundo operando",
                    "Valor incorrecto, intente nuevamente", FLT_MIN, FLT_MAX))
                {
                    operand2 = auxValue;
                }
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

        menu_pauseScreen();
    } while(!lifeCycle);

    return 0;
}
