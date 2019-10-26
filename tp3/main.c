/***********************************************************************
 * Programa: Nomina de Empleados con LinkedList
 *
 * Objetivo:
 *      Se requiere administrar el ABM de una nomina de Empleados
 *      mediante la biblioteca de LinkedList.
 *
 * Versiones:
 *      v2.1 - Implementacion de funciones de Empleados
 *              [Fecha: 26 de octubre de 2019]
 *
 * Autor: Christian Grimberg
 *
 ************************************************************************/
#include "menu.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de ejecucion de cada menu. >*/
    int optionMenu; /**< Opcion elegida por el usuario de cada menu. >*/
    LinkedList* listaEmpleados = ll_newLinkedList(); /**< Invocacion de arreglo generico. >*/
    sEmployee* employee;
    char name[EMPLOYEE_NAME_MAX];

    do
    {
        lifeCycle = menu_main(&optionMenu);

        if(optionMenu == MENU_MAIN_MAX || optionMenu == -1)
        {
            inputs_pauseScreen(QUIT_MESSAGE);
            exit(EXIT_SUCCESS);
        }

        switch(optionMenu)
        {
        case 1: /**< Cargar los datos de los empleados desde el archivo data.csv (modo texto). >*/
            if(!controller_loadFromText("data.csv", listaEmpleados))
            {
                printf("No se pudo leer el archivo.\n");
            }
            break;
        case 3: /**< Alta de empleado. >*/
            employee = employee_new();
            if(employee_getName(employee, name))
            {
                printf("Nombre del Empleado: %s.\n", name);
            }
            break;
        }

        inputs_pauseScreen(CONTINUE_MESSAGE);
    }while(lifeCycle == 0);

    return 0;
}
