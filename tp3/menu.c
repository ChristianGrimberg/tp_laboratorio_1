#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf(" +===================================================================================+\n");
    printf(" |                                NOMINA DE EMPLEADOS                                |\n");
    printf(" +===================================================================================+\n");
    printf(" |  [1] Cargar los datos de los Empleados desde el archivo data.csv (modo texto).    |\n");
    printf(" |  [2] Cargar los datos de los Empleados desde el archivo data.bin (modo binario).  |\n");
    printf(" |  [3] Alta de Empleado.                                                            |\n");
    printf(" |  [4] Modificar datos de Empleado.                                                 |\n");
    printf(" |  [5] Baja de Empleado.                                                            |\n");
    printf(" |  [6] Listar Empleados.                                                            |\n");
    printf(" |  [7] Ordenar Empleados.                                                           |\n");
    printf(" |  [8] Guardar los datos de los Empleados en el archivo data.csv (modo texto).      |\n");
    printf(" |  [9] Guardar los datos de los Empleados en el archivo data.bin (modo binario).    |\n");
    printf(" | [10] Salir del programa                                                           |\n");
    printf(" +-----------------------------------------------------------------------------------+\n\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ", ERROR_MESSAGE, 1, MENU_MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
