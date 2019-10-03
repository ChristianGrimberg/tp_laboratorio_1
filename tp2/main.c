/***********************************************************************
 * Programa: Nomina de Empleados
 *
 * Objetivo:
 *      Se requiere administrar el ABM de una nomina de 1000 empleados.
 *
 * Versiones:
 *      v1.3 - Funciones ABM de Empleados
 *              [Fecha: 3 de octubre de 2019]
 *      v1.2 - Esqueleto de estructuras de Empleados
 *              [Fecha: 29 de septiembre de 2019]
 *      v1.1 - Ciclo de vida de menus en pantalla
 *              [Fecha: 13 de septiembre de 2019]
 *
 * Autor: Christian Grimberg
 *
 ************************************************************************/
#include "arrayEmployees.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu. >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal. >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion. >*/
    int optionReportMenu; /**< Opcion elegida por el usuario para el menu de reportes. >*/
    int index; /**< Indice del Empleado buscado. >*/
    int id; /**< ID del Empleado elegido por el usuario. >*/

    sEmployee employees[EMPLOYEE_MAX]; /**< Arreglo de Empleados que se utiliza durante todo el ciclo de vida del programa. >*/
    sEmployee employeeAux; /**< Empleado auxiliar para uso de validacion. >*/
    sSector sectors[SECTOR_MAX]; /**< Arreglo de Sectores que se utiliza durante todo el ciclo de vida del programa. >*/

    if(!initEmployees(employees, EMPLOYEE_MAX))
    {
        if(WITH_HARDCODE == TRUE) // Opcion definida desde el pre-procesador para hacer uso del hardcodeo de Empleados y Sectores.
        {
            sector_hardcode(sectors, SECTOR_MAX, SECTOR_MAX);
            employee_hardocde(employees, EMPLOYEE_MAX, 8);
        }

        do
        {
            lifeCycle = menu_main(&optionMainMenu);

            if(optionMainMenu == MAIN_MAX || optionMainMenu == OPTION_ERROR)
            {
                inputs_pauseScreen(EXIT_MESSAGE);
                break;
            }

            switch (optionMainMenu)
            {
                case 1: // Opcion elegida: Alta de Empleado.
                    if(!inputs_getString(employeeAux.name, "Ingrese el nombre: ",
                            "Error, intente nuevamente: ", 1, EMPLOYEE_NAME_MAX)
                        && !inputs_getString(employeeAux.lastName, "Ingrese el apellido: ",
                            "Error, intente nuevamente: ", 1, EMPLOYEE_LASTNAME_MAX)
                        && !inputs_getFloat(&employeeAux.salary, "Ingrese el salario [hasta $10.000.000]: ",
                                "Error, intente nuevamente: ", 1, 10000000)
                        && printSectors(sectors, SECTOR_MAX) > 0
                        && !inputs_getInt(&employeeAux.idSector, "Elija el ID del Sector: ",
                            "Error, intente nuevamente: ", (ID_INIT_SECTOR + 1), (ID_INIT_SECTOR + SECTOR_MAX))
                        && !addEmployee(employees, EMPLOYEE_MAX, getNewEmployeeId(),
                            employeeAux.name, employeeAux.lastName, employeeAux.salary, employeeAux.idSector))
                    {
                        printf("Empleado cargado con exito.\n");
                    }
                    break;
                case 2: // Opcion elegida: Modificar un Empleado.
                    inputs_clearScreen();
                    id = selectEmployee("Ingrese el ID del Empleado a modificar: ", "Error, intente nuevamente: ",
                        employees, EMPLOYEE_MAX, sectors, SECTOR_MAX);
                    index = findEmployeeById(employees, EMPLOYEE_MAX, id);

                    do
                    {
                        lifeCycle = menu_update(&optionUpdateMenu);

                        if(optionUpdateMenu == UPDATE_MAX || optionUpdateMenu == OPTION_ERROR)
                        {
                            break;
                        }

                        switch (optionUpdateMenu)
                        {
                            case 1: // Opcion elegida: Cambio del Nombre.
                                if(!inputs_getString(employees[index].name, "Ingrese el nuevo nombre: ",
                                    "Error, intente nuevamente: ", 1, SECTOR_NAME_MAX))
                                {
                                    inputs_clearScreen();
                                    printf("Nombre modificado con exito:\n");
                                    printEmployee(employees[index], sectors, SECTOR_MAX);
                                }
                                break;
                            case 2: // Opcion elegida: Cambio del Apellido.
                                if(!inputs_getString(employees[index].lastName, "Ingrese el nuevo apellido: ",
                                    "Error, intente nuevamente: ", 1, SECTOR_NAME_MAX))
                                {
                                    inputs_clearScreen();
                                    printf("Apellido modificado con exito:\n");
                                    printEmployee(employees[index], sectors, SECTOR_MAX);
                                }
                                break;
                            case 3: // Opcion elegida: Cambio del salario.
                                /* code */
                                break;
                            case 4: // Opcion elegida: Cambio del Sector.
                                /* code */
                                break;
                        }

                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    } while (!lifeCycle);
                    break;
                case 3: // Opcion elegida: Baja de un Empleado.
                    inputs_clearScreen();
                    id = selectEmployee("Ingrese el ID del Empleado a dar de baja: ", "Error, intente nuevamente: ",
                        employees, EMPLOYEE_MAX, sectors, SECTOR_MAX);

                    if(id != -1 && !removeEmployee(employees, EMPLOYEE_MAX, sectors, SECTOR_MAX, id))
                    {
                        printf("Empleado dado de baja con exito.\n");
                    }
                    else
                    {
                        printf("Operacion cancelada.\n");
                    }
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
                                inputs_clearScreen();
                                printEmployees(employees, EMPLOYEE_MAX, sectors, SECTOR_MAX);
                                break;
                        }

                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    } while (!lifeCycle);
                    break;
            }

            inputs_pauseScreen(CONTINUE_MESSAGE);
        } while (!lifeCycle);
    }
    else
    {
        printf("Hubo un error al inicializar el listado de alumnos.\n");
        inputs_pauseScreen(EXIT_MESSAGE);
    }

    return 0;
}
