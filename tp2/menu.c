#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    input_clearScreen();

    printf("=======================================================\n");
    printf("                NOMINA DE EMPLEADOS\n");
    printf("=======================================================\n");
    printf("    1 - Alta de Empleado\n");
    printf("    2 - Modificar Empleado\n");
    printf("    3 - Baja de Empleado\n");
    printf("    4 - Informes de Empleado\n");
    printf("    5 - Salir\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_create(int* option)
{
    int returnValue = -1;

    input_clearScreen();

    printf("=======================================================\n");
    printf("                ALTA DE EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Ingresar el Nombre\n");
    printf("    2 - Ingresar el Apellido\n");
    printf("    3 - Ingresar el salario\n");
    printf("    4 - Ingresar el Sector\n");
    printf("    5 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!input_getInt(option, "Elija una opcion del menu",
        "Opcion incorrecta, ingrese nuevamente", OPTION_MIN, MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}