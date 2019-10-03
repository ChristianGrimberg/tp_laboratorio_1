#include "arrayEmployees.h"

/** \brief Funcion para generar un nuevo ID de Sectores.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada Sector.
 *
 */
static int getNewSectorId(void);

/** \brief Funcion que imprime un Empleado formateado para impresion
 *      sin encabezado de tabla.
 *
 * \param employee sEmployee Tipo de Dato de Empleado.
 * \param list[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si no se pudo imprimir el Empleado.
 *      [0] Si el Empleado fue impreso con exito.
 *
 */
static int printEmployeeWithoutHeader(sEmployee employee, sSector list[], int length);

/** \brief Funcion que imprime un Sector formateado para impresion
 *      sin encabezado de tabla.
 *
 * \param sector sSector Tipo de Dato de Sector.
 * \return void No retorna valores.
 *
 */
static void printSectorWithoutHeader(sSector sector);

int initEmployees(sEmployee list[], int length)
{
    int returnValue = -1;
    int i = 0;

    if(list != NULL && length > 0 && length <= EMPLOYEE_MAX)
    {
        for( ; i < length; i++)
        {
            list[i].isEmpty = TRUE;
        }

        if(i == length)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}

int getNewEmployeeId(void)
{
    static int idEmployee = ID_INIT_EMPLOYEE;
    idEmployee++;
    return idEmployee;
}

static int getNewSectorId(void)
{
    static int idSector = ID_INIT_SECTOR;
    idSector++;
    return idSector;
}

int getEmptyIndexOfEmployees(sEmployee list[], int length)
{
    int returnValue = -1;

    if(list != NULL && length > 0 && length <= EMPLOYEE_MAX)
    {
        for (int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int findEmployeeById(sEmployee list[], int length, int id)
{
    int returnValue = -1;

    if(list != NULL && length > 0 && length <= EMPLOYEE_MAX)
    {
        for (int i = 0; i < length; i++)
        {
            if(list[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int findSectorNameById(char* sectorName, sSector list[], int length, int idSector)
{
    int returnValue = -1;

    if(list != NULL && length > 0 && length <= SECTOR_MAX)
    {
        for(int i = 0; i < length; i++)
        {
            if(list[i].idSector == idSector)
            {
                strcpy(sectorName, list[i].name);
                returnValue = 0;
                break;
            }
        }
    }

    return returnValue;
}

int addEmployee(sEmployee list[], int length, int id, char name[], char lastName[], float salary, int sector)
{
    int returnValue = -1;
    int emptyIndex;

    if(list != NULL && length > 0 && length <= EMPLOYEE_MAX
        && name != NULL && lastName != NULL)
    {
        if(findEmployeeById(list, length, id) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {
            emptyIndex = getEmptyIndexOfEmployees(list, length);

            if(emptyIndex != -1)
            {
                list[emptyIndex].id = id;
                strcpy(list[emptyIndex].name, name);
                strcpy(list[emptyIndex].lastName, lastName);
                list[emptyIndex].salary = salary;
                list[emptyIndex].idSector = sector;
                list[emptyIndex].isEmpty = FALSE;

                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int printEmployee(sEmployee employee, sSector list[], int length)
{
    int returnValue = -1;

    if(list != NULL && length > 0 && length <= SECTOR_MAX 
        && employee.isEmpty == FALSE)
    {
        printf("+======+===============+===============+=============+============================+\n");
        printf("|  ID  |    Nombre     |   Apellido    |   Salario   |           Sector           |\n");
        printf("+======+===============+===============+=============+============================+\n");
        printEmployeeWithoutHeader(employee, list, length);
        printf("+------+---------------+---------------+-------------+----------------------------+\n");

        returnValue = 0;
    }

    return returnValue;
}

void printSector(sSector sector)
{
    printf("+======+============================+\n");
    printf("|  ID  |           Sector           |\n");
    printf("+======+============================+\n");
    printSectorWithoutHeader(sector);
    printf("+------+----------------------------+\n");
}

int printEmployees(sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors)
{
    int itemsCounter = 0;
    int flagEmployees = 0;

    if(listEmployees != NULL && lengthEmployees > 0 && lengthEmployees <= EMPLOYEE_MAX)
    {
        for (int i = 0; i < lengthEmployees; i++)
        {
            if(listEmployees[i].isEmpty == FALSE)
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+======+===============+===============+=============+============================+\n");
                    printf("|  ID  |    Nombre     |   Apellido    |   Salario   |           Sector           |\n");
                    printf("+======+===============+===============+=============+============================+\n");
                }

                if(!printEmployeeWithoutHeader(listEmployees[i], listSectors, lengthSectors))
                {
                    flagEmployees = 1;
                }
                else
                {
                    flagEmployees = 0;
                    break;
                }
                
            }
        }

        if(flagEmployees == 1)
        {
            printf("+------+---------------+---------------+-------------+----------------------------+\n");
        }
    }

    if(flagEmployees == 0)
    {
        printf("No existen Empleados en el listado.\n");
    }

    return itemsCounter;
}

int printSectors(sSector sectors[], int length)
{
    int itemsCounter = 0;
    int flagSectors = 0;

    if(sectors != NULL && length > 0 && length <= SECTOR_MAX)
    {
        for (int i = 0; i < length; i++)
        {
            itemsCounter++;

            if(itemsCounter == 1)
            {
                printf("+======+============================+\n");
                printf("|  ID  |           Sector           |\n");
                printf("+======+============================+\n");
            }

            printSectorWithoutHeader(sectors[i]);
            flagSectors = 1;
        }

        if(flagSectors == 1)
        {
            printf("+------+----------------------------+\n");
        }
    }

    if(flagSectors == 0)
    {
        printf("No existen Sectores cargados en el listado.\n");
    }

    return itemsCounter;
}

void sector_hardcode(sSector list[], int length, int quantity)
{
    sSector auxSector[] = {
        {getNewSectorId(), "Finanzas"},
        {getNewSectorId(), "Sistemas"},
        {getNewSectorId(), "Recursos Humanos"},
        {getNewSectorId(), "Ventas"},
        {getNewSectorId(), "Compras"},
        {getNewSectorId(), "Atencion Clientes"},
        {getNewSectorId(), "Administracion"},
        {getNewSectorId(), "Ingenieria"}
    };

    if(list != NULL && quantity <= SECTOR_MAX && length >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            list[i] = auxSector[i];
        }
    }
}

void employee_hardocde(sEmployee list[], int length, int quantity)
{
    sEmployee auxEmployess[] = {
        {getNewEmployeeId(), "Marcelo", "Tinelli", 25500, 15, FALSE},
        {getNewEmployeeId(), "Susana", "Gimenez", 135400, 14, FALSE},
        {getNewEmployeeId(), "Ricardo", "Darin", 75600, 11, FALSE},
        {getNewEmployeeId(), "Moria", "Casan", 99400, 13, FALSE},
        {getNewEmployeeId(), "Marley", "Wieber", 55300, 12, FALSE},
        {getNewEmployeeId(), "Mirtha", "Legrand", 67400, 17, FALSE},
        {getNewEmployeeId(), "Veronica", "Lozano", 38700, 16, FALSE},
        {getNewEmployeeId(), "Pampita", "Ardohain", 32750, 13, FALSE}
    };

    if(list != NULL && quantity <= 8 && length >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            list[i] = auxEmployess[i];
        }
    }
}

static int printEmployeeWithoutHeader(sEmployee employee, sSector list[], int length)
{
    int returnValue = -1;
    char sectorName[SECTOR_NAME_MAX];

    if(list != NULL && length > 0 && length <= SECTOR_MAX
        && !findSectorNameById(sectorName, list, length, employee.idSector))
    {
        printf("| %4d | %13s | %13s | %11.2f | %26s |\n",
            employee.id, arrays_stringToCamelCase(employee.name, EMPLOYEE_NAME_MAX),
            arrays_stringToCamelCase(employee.lastName, EMPLOYEE_LASTNAME_MAX), employee.salary, sectorName);
        returnValue = 0;
    }

    return returnValue;
}

static void printSectorWithoutHeader(sSector sector)
{
    printf("| %4d | %26s |\n", sector.idSector, arrays_stringToCamelCase(sector.name, SECTOR_NAME_MAX));
}
