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
    int employeeQty = 0; /**< Cantidad de Empleados cargados en el arreglo. >*/
    LinkedList* listaEmpleados = ll_newLinkedList(); /**< Invocacion de arreglo generico. >*/
    char path[PATH_MAX] = "data.csv"; /**< Path del archivo a trabajar. >*/

    if(listaEmpleados == NULL)
    {
        inputs_pauseScreen("No hay espacio en la memoria del sistema.");
        exit(EXIT_FAILURE);
    }

    do
    {
        lifeCycle = menu_main(&optionMenu);

        if(optionMenu == MENU_MAIN_MAX || optionMenu == -1)
        {
            if(ll_clear(listaEmpleados) == 0
               && ll_len(listaEmpleados) == 0
               && ll_deleteLinkedList(listaEmpleados) == 0)
            {
                inputs_pauseScreen(QUIT_MESSAGE);
                exit(EXIT_SUCCESS);
            }
            else
            {
                inputs_pauseScreen("Error al limpiar la memoria del sistema.");
                exit(EXIT_FAILURE);
            }
        }

        switch(optionMenu)
        {
        case 1: /**< Cargar los datos de los empleados desde el archivo data.csv (modo texto). >*/
            employeeQty = ll_len(listaEmpleados);

            if(employeeQty < EMPLOYEE_MAX
               && controller_loadFromText(path, listaEmpleados))
            {
                employeeQty = ll_len(listaEmpleados) - employeeQty;
                printf("Se cargaron %d Empleados desde el archivo de texto.\n", employeeQty);
            }
            else
            {
                if(employeeQty >= EMPLOYEE_MAX)
                    printf("La nomina de Empleados a llegado a su limite de %d Empleados.\n", employeeQty);
                else
                    printf("No se puede obtener Empleados desde el archivo de texto.\n");
            }
            break;
        case 2: /**< Cargar los datos de los empleados desde el archivo data.csv (modo binario). >*/
            if(!controller_loadFromBinary(path, listaEmpleados))
            {
                printf("No se pudo leer el archivo binario.\n");
            }
            break;
        case 8: /**< Guardar los datos de los empleados en el archivo data.csv (modo texto). >*/
            if(!controller_saveAsText("data.csv", listaEmpleados))
            {
                printf("No se pudo guardar el archivo de texto.\n");
            }
            break;
        case 9: /**< Guardar los datos de los empleados en el archivo data.csv (modo binario). >*/
            if(!controller_saveAsBinary("data.csv", listaEmpleados))
            {
                printf("No se pudo guardar el archivo binario.\n");
            }
            break;
        }
        inputs_pauseScreen(CONTINUE_MESSAGE);
    }while(lifeCycle == 0);

    return 0;
}
