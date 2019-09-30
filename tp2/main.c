/*******************************************************************
 * Programa: Nomina de Empleados
 *
 * Objetivo:
 *      Se requiere administrar el ABM de una nomina de 1000 empleados.
 *
 * Versiones:
 *      v1.2 - Esqueleto de estructuras de Empleados
 *              [Fecha: 29 de septiembre de 2019]
 *      v1.1 - Ciclo de vida de menus en pantalla
 *              [Fecha: 13 de septiembre de 2019]
 *
 * Autor: Christian Grimberg
 *
 ********************************************************************/
#include "menu.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion >*/
    int optionReportMenu; /**< Opcion elegida por el usuario para el menu de reportes >*/

    do
    {
        lifeCycle = menu_main(&optionMainMenu);

        if(optionMainMenu == MAIN_MAX || optionMainMenu == OPTION_ERROR)
        {
            inputs_pauseScreen("Presione la tecla Enter para salir del programa...");
            break;
        }

        switch (optionMainMenu)
        {
            case 1: // Opcion elegida: Alta de Empleado.
                break;
            case 2: // Opcion elegida: Modificar un Empleado.
                do
                {
                    lifeCycle = menu_update(&optionUpdateMenu);

                    if(optionUpdateMenu == UPDATE_MAX || optionUpdateMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionUpdateMenu)
                    {
                        case 1: // Opcion elegida: Ingreso del Nombre.
                            /* code */
                            break;
                    }

                    inputs_pauseScreen("Presione la tecla Enter para continuar...");
                } while (!lifeCycle);
                break;
            case 3: // Opcion elegida: Baja de un Empleado.
                break;
            case 4: // Opcion elegida: Informes de la nomina de Empleados.
                do
                {
                    lifeCycle = menu_printReports(&optionReportMenu);

                    if(optionReportMenu == REPORT_MAX || optionReportMenu == OPTION_ERROR)
                    {
                        break;
                    }

                    switch (optionReportMenu)
                    {
                        case 1: // Opcion elegida: Listado ordenado de Empleados
                            /* code */
                            break;
                    }

                    inputs_pauseScreen("Presione la tecla Enter para continuar...");
                } while (!lifeCycle);
                break;
        }

        inputs_pauseScreen("Presione la tecla Enter para continuar...");
    } while (!lifeCycle);

    return 0;
}
