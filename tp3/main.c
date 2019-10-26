#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de ejecucion de cada menu. >*/
    int optionMenu; /**< Opcion elegida por el usuario de cada menu. >*/
    LinkedList* listaEmpleados = ll_newLinkedList();
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
                inputs_pauseScreen("No se pudo leer el archivo.");
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
