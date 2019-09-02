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
                switch(addOperands(operand1, operand2, &auxValue))
                {
                    case -1:
                        printf("El resultado es un desbordamiento\n");
                        break;
                    case 0:
                        printNumberByType("El resultado de A+B es:", auxValue);
                        break;
                    case 1:
                        printf("Los datos ingresados no estan dentro de los limites aceptados\n");
                        break;
                }
                break;
            case 4:
                switch(subtractOperands(operand1, operand2, &auxValue))
                {
                    case -1:
                        printf("El resultado es un desbordamiento\n");
                        break;
                    case 0:
                        printNumberByType("El resultado de A-B es:", auxValue);
                        break;
                    case 1:
                        printf("Los datos ingresados no estan dentro de los limites aceptados\n");
                        break;
                }
                break;
            case 5:
                switch(divideOperands(operand1, operand2, &auxValue))
                {
                    case -2:
                        printf("No es posible dividir por cero\n");
                        break;
                    case -1:
                        printf("El resultado es un desbordamiento\n");
                        break;
                    case 0:
                        printNumberByType("El resultado de A/B es:", auxValue);
                        break;
                    case 1:
                        printf("Los datos ingresados no estan dentro de los limites aceptados\n");
                        break;
                }
                break;
            case 6:
                switch(multiplyOperands(operand1, operand2, &auxValue))
                {
                    case -1:
                        printf("El resultado es un desbordamiento\n");
                        break;
                    case 0:
                        printNumberByType("El resultado de A*B es:", auxValue);
                        break;
                    case 1:
                        printf("Los datos ingresados no estan dentro de los limites aceptados\n");
                        break;
                }
                break;
            case 7:
                break;
        }

        menu_pauseScreen();
    } while(!lifeCycle);

    return 0;
}
