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
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal >*/
    int optionCreateMenu; /**< Opcion elegida por el usuario del menu de alta >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario del menu de modificacion >*/
    int optionDeleteMenu; /**< Opcion elegida por el usuario del menu de eliminacion >*/

    do
    {
        lifeCycle = menu_main(&optionMainMenu);

        if(optionMainMenu == MAIN_MAX || optionMainMenu == OPTION_ERROR)
        {
            input_pauseScreen("Presione la tecla Enter para salir del programa");
            break;
        }

        switch (optionMainMenu)
        {
            case 1: // Opcion elegida: Alta de Empleado
                do
                {
                    lifeCycle = menu_create(&optionCreateMenu);

                    if(optionCreateMenu == CREATE_MAX || optionCreateMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionCreateMenu)
                    {
                        case 1: // Opcion elegida: Ingreso del Nombre
                            /* code */
                            break;
                    }

                    input_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
            case 2: // Opcion elegida: Modificar un Empleado
                do
                {
                    lifeCycle = menu_update(&optionUpdateMenu);

                    if(optionUpdateMenu == UPDATE_MAX || optionUpdateMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionUpdateMenu)
                    {
                        case 1: // Opcion elegida: Ingreso del Nombre
                            /* code */
                            break;
                    }

                    input_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
            case 3:
                do
                {
                    lifeCycle = menu_delete(&optionDeleteMenu);

                    if(optionDeleteMenu == DELETE_MAX || optionUpdateMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionDeleteMenu)
                    {
                        case 1: // Opcion elegida: Ingreso del ID a dar de baja
                            /* code */
                            break;
                    }

                    input_pauseScreen("Presione la tecla Enter para continuar");
                } while (!lifeCycle);
                break;
        }

        input_pauseScreen("Presione la tecla Enter para continuar");
    } while (!lifeCycle);

    return 0;
}
