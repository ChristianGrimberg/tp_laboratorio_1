/*******************************************************************
 * Programa: Nomina de Empleados
 *
 * Objetivo:
 *      Se requiere administrar el ABM de una nomina de 100 empleados.
 *
 * Version:
 *      v1.1 - 7 de septiembre de 2019
 *
 * Autor: Christian Grimberg
 *
 ********************************************************************/
#include "menu.h"

int main()
{
    int lifeCycle;
    int option;

    do
    {
        lifeCycle = menu_main(&option);

        if(option == MAIN_MAX || option == OPTION_ERROR)
        {
            break;
        }

        switch (option)
        {
            case 1:
                /* code */
                break;
        }

        input_pauseScreen();
    } while (!lifeCycle);

    return 0;
}
