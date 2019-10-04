#include "menu.h"

int menu_main(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("                NOMINA DE EMPLEADOS\n");
    printf("=======================================================\n");
    printf("    1 - Alta de Empleado\n");
    printf("    2 - Modificar Empleado\n");
    printf("    3 - Baja de Empleado\n");
    printf("    4 - Informes de Empleado\n");
    printf("    5 - Salir\n");
    printf("=======================================================\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, MAIN_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_update(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("                MODIFICAR EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Modificar el Nombre\n");
    printf("    2 - Modificar el Apellido\n");
    printf("    3 - Modificar el salario\n");
    printf("    4 - Modificar el Sector\n");
    printf("    5 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, UPDATE_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}

int menu_printReports(int* option)
{
    int returnValue = -1;

    inputs_clearScreen();

    printf("=======================================================\n");
    printf("                INFORMES DE EMPLEADO\n");
    printf("=======================================================\n");
    printf("    1 - Listado ordenado de Empleados ascendente\n");
    printf("    2 - Listado ordenado de Empleados descendente\n");
    printf("    3 - Total y promedio de salarios de Empleados\n");
    printf("    4 - Empleados que superan el salario promedio\n");
    printf("    5 - Volver al menu principal\n");
    printf("=======================================================\n");

    if(!inputs_getInt(option, "Elija una opcion del menu: ",
        "Opcion incorrecta, ingrese nuevamente: ", OPTION_MIN, REPORT_MAX))
    {
        returnValue = 0;
    }

    return returnValue;
}
