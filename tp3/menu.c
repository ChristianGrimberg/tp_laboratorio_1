#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +===================================================================================+\n");
    printf(" |                                NOMINA DE EMPLEADOS                                |\n");
    printf(" +===================================================================================+\n");
    printf(" |  [1] Cargar los datos de los empleados desde el archivo data.csv (modo texto).    |\n");
    printf(" |  [2] Cargar los datos de los empleados desde el archivo data.csv (modo binario).  |\n");
    printf(" |  [3] Alta de empleado.                                                            |\n");
    printf(" |  [4] Modificar datos de empleado.                                                 |\n");
    printf(" |  [5] Baja de empleado.                                                            |\n");
    printf(" |  [6] Listar empleados.                                                            |\n");
    printf(" |  [7] Ordenar empleados.                                                           |\n");
    printf(" |  [8] Guardar los datos de los empleados en el archivo data.csv (modo texto).      |\n");
    printf(" |  [9] Guardar los datos de los empleados en el archivo data.csv (modo binario).    |\n");
    printf(" | [10] Salir del programa                                                           |\n");
    printf(" +-----------------------------------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
