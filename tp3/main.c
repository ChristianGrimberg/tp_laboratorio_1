/***********************************************************************
 * Programa: Nomina de Empleados con LinkedList
 *
 * Objetivo:
 *      Se requiere administrar el ABM de una nomina de Empleados
 *      mediante la biblioteca de LinkedList.
 *
 * Versiones:
 *      v2.2 - Implementacion de funciones de gestion de archivos
 *              [Fecha: 4 de noviembre de 2019]
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
    char textPath[PATH_MAX] = "data.csv"; /**< Path del archivo de texto a trabajar. >*/
    char binaryPath[PATH_MAX] = "data.bin"; /**< Path del archivo binario a trabajar. >*/

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
            employeeQty = controller_loadFromText(textPath, listaEmpleados);

            if(employeeQty > 0)
            {
                printf("Se cargaron %d Empleados desde el archivo de texto.\n", employeeQty);
            }
            else
            {
                printf("No se puede cargar Empleados.\n");
            }
            break;
        case 2: /**< Cargar los datos de los empleados desde el archivo data.bin (modo binario). >*/
            employeeQty = controller_loadFromBinary(binaryPath, listaEmpleados);

            if(employeeQty > 0)
            {
                printf("Se cargaron %d Empleados desde el archivo binario.\n", employeeQty);
            }
            else
            {
                printf("No se puede cargar Empleados.\n");
            }
            break;
        case 6:
            employeeQty = 0;

            while(employeeQty < ll_len(listaEmpleados))
            {
                inputs_clearScreen();

                employeeQty += controller_ListEmployee(ll_subList(listaEmpleados, employeeQty, employeeQty + CONTROLLER_LIST_MAX));

                if(employeeQty == 0)
                {
                    printf("No hay Empleados cargados en el sistema.\n");
                    break;
                }

                if(employeeQty < ll_len(listaEmpleados))
                {
                    inputs_pauseScreen("Presione Enter para ver la siguiente pagina.");
                }
            }
            break;
        case 8: /**< Guardar los datos de los empleados en el archivo data.csv (modo texto). >*/
            if(!controller_saveAsText(textPath, listaEmpleados))
            {
                printf("No se pudo guardar el archivo de texto.\n");
            }
            else
            {
                printf("Archivo de texto guardado correctamente.\n");
            }
            break;
        case 9: /**< Guardar los datos de los empleados en el archivo data.bin (modo binario). >*/
            if(!controller_saveAsBinary(binaryPath, listaEmpleados))
            {
                printf("No se pudo guardar el archivo binario.\n");
            }
            else
            {
                printf("Archivo binario guardado correctamente.\n");
            }
            break;
        }
        inputs_pauseScreen(CONTINUE_MESSAGE);
    }while(lifeCycle == 0);

    return 0;
}
