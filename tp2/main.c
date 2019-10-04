/***********************************************************************
 * Programa: Nomina de Empleados
 *
 * Objetivo:
 *      Se requiere administrar el ABM de una nomina de 1000 empleados.
 *
 * Versiones:
 *      v1.4 - Informes de Empleados
 *              [Fecha: 4 de octubre de 2019]
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
    int index; /**< Indice buscado. >*/
    int id; /**< ID elegido por el usuario. >*/
    int employeeCounter; /**< Valor para contador de Empleados. >*/

    float averageSalary; /**< Valor para el promedio salarial de Empleados. >*/

    sEmployee employees[EMPLOYEE_MAX]; /**< Arreglo de Empleados que se utiliza durante todo el ciclo de vida del programa. >*/
    sEmployee employeesExceedAverageSalary[EMPLOYEE_MAX]; /**< Arreglo de Empleados que superan el sueldo promedio. >*/
    sEmployee employeeAux; /**< Empleado auxiliar para uso de validacion. >*/

    sSector sectors[SECTOR_MAX]; /**< Arreglo de Sectores que se utiliza durante todo el ciclo de vida del programa. >*/

    if(!initEmployees(employees, EMPLOYEE_MAX))
    {
        /**< Opcion definida desde el pre-procesador para hacer uso del hardcoding y pausa para ver errores de compilacion. >*/
        if(WITH_HARDCODE == TRUE)
        {
            sector_hardcode(sectors, SECTOR_MAX, SECTOR_MAX);
            employee_hardocde(employees, EMPLOYEE_MAX, 8);
            inputs_pauseScreen("\n--->[DEBUG & HARDCODING MODE]<----\n");
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
                            ERROR_MESSAGE, 1, EMPLOYEE_NAME_MAX)
                        && !inputs_getString(employeeAux.lastName, "Ingrese el apellido: ",
                            ERROR_MESSAGE, 1, EMPLOYEE_LASTNAME_MAX)
                        && !inputs_getFloat(&employeeAux.salary, "Ingrese el salario [hasta $10.000.000]: ",
                            ERROR_MESSAGE, 1, SALARY_MAX)
                        && printSectors(sectors, SECTOR_MAX) > 0
                        && !inputs_getInt(&employeeAux.idSector, "Elija el ID del Sector: ",
                            ERROR_MESSAGE, (ID_INIT_SECTOR + 1), (ID_INIT_SECTOR + SECTOR_MAX))
                        && !addEmployee(employees, EMPLOYEE_MAX, getNewEmployeeId(),
                            employeeAux.name, employeeAux.lastName, employeeAux.salary, employeeAux.idSector))
                    {
                        printf("Empleado cargado con exito.\n");
                    }
                    break;
                case 2: // Opcion elegida: Modificar un Empleado.
                    inputs_clearScreen();
                    id = selectEmployee("Ingrese el ID del Empleado a modificar: ", ERROR_MESSAGE,
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
                                    ERROR_MESSAGE, 1, SECTOR_NAME_MAX))
                                {
                                    inputs_clearScreen();
                                    printf("Nombre modificado con exito:\n");
                                    printEmployee(employees[index], sectors, SECTOR_MAX);
                                }
                                break;
                            case 2: // Opcion elegida: Cambio del Apellido.
                                if(!inputs_getString(employees[index].lastName, "Ingrese el nuevo apellido: ",
                                    ERROR_MESSAGE, 1, SECTOR_NAME_MAX))
                                {
                                    inputs_clearScreen();
                                    printf("Apellido modificado con exito:\n");
                                    printEmployee(employees[index], sectors, SECTOR_MAX);
                                }
                                break;
                            case 3: // Opcion elegida: Cambio del salario.
                                if(!inputs_getFloat(&employees[index].salary,
                                    "Ingrese el nuevo salario [hasta $10.000.000]: ",
                                    ERROR_MESSAGE, 0, SALARY_MAX))
                                {
                                    inputs_clearScreen();
                                    printf("Salario modificado con exito:\n");
                                    printEmployee(employees[index], sectors, SECTOR_MAX);
                                }
                                break;
                            case 4: // Opcion elegida: Cambio del Sector.
                                inputs_clearScreen();
                                id = selectSector("Ingrese el ID del Sector a cambiar: ",
                                    ERROR_MESSAGE, sectors, SECTOR_MAX);

                                if(id != -1 && index != -1)
                                {
                                    inputs_clearScreen();
                                    employees[index].idSector = id;
                                    printf("Sector cambiado con exito:\n");
                                    printEmployee(employees[index], sectors, SECTOR_MAX);
                                }
                                break;
                        }

                        inputs_pauseScreen(CONTINUE_MESSAGE);
                    } while (!lifeCycle);
                    break;
                case 3: // Opcion elegida: Baja de un Empleado.
                    inputs_clearScreen();
                    id = selectEmployee("Ingrese el ID del Empleado a dar de baja: ", ERROR_MESSAGE,
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
                        if(currentEmployeeCounter(employees, EMPLOYEE_MAX) <= 0)
                        {
                            printf("No hay Empleados dados de alta en el sistema.\n");
                        }
                        else
                        {
                            switch (optionReportMenu)
                            {
                                case 1: // Opcion elegida: Listado ordenado de Empleados ascendente.
                                    inputs_clearScreen();
                                    sortEmployees(employees, EMPLOYEE_MAX, sectors, SECTOR_MAX, ASC);
                                    printEmployees(employees, EMPLOYEE_MAX, sectors, SECTOR_MAX);
                                    break;
                                case 2: // Opcion elegida: Listado ordenado de Empleados descendente.
                                    inputs_clearScreen();
                                    sortEmployees(employees, EMPLOYEE_MAX, sectors, SECTOR_MAX, DESC);
                                    printEmployees(employees, EMPLOYEE_MAX, sectors, SECTOR_MAX);
                                    break;
                                case 3: // Opcion elegida: Total y Promedio de Salarios.
                                    inputs_clearScreen();
                                    printTotalsAndAverageSalaries(employees, EMPLOYEE_MAX);
                                    break;
                                case 4: // Opcion elegida: Empleados que superan el sueldo promedio.
                                    inputs_clearScreen();
                                    averageSalary = sumEmployeeSalaries(employees, EMPLOYEE_MAX) / currentEmployeeCounter(employees, EMPLOYEE_MAX);
                                    if(!initEmployees(employeesExceedAverageSalary, EMPLOYEE_MAX))
                                    {
                                        employeeCounter = employeesFilterAboveValue(employees, employeesExceedAverageSalary, EMPLOYEE_MAX, averageSalary);
                                        
                                        if(employeeCounter > 0)
                                        {
                                            printf("Existen %d Empleados por encima del salario de $ %.2f.\n", employeeCounter, averageSalary);
                                            printEmployees(employeesExceedAverageSalary, EMPLOYEE_MAX, sectors, SECTOR_MAX);
                                        }
                                        else
                                        {
                                            printf("No hay Empleados con el sueldo por encima del promedio de $ %.2f.\n", averageSalary);
                                        }
                                    }
                                    break;
                            }
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
