#include "arrayEmployees.h"

/** \brief Funcion similar a tipo constructor de un objeto
 *      que carga los parametros a un Empleado y lo devuelve.
 *
 * \param name[] char Nombre para un Empleado.
 * \param lastName[] char Apellido para un Empleado.
 * \param salary float Valor del salario para un Empleado.
 * \param idSector int ID externo de un Sector.
 * \return sEmployee
 *      Nuevo Empleado con los parametros agregados en sus campos.
 *
 */
static sEmployee newEmployee(char name[], char lastName[], float salary, int idSector);

/** \brief Funcion para generar un nuevo ID de Empleados.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada Empleado.
 *
 */
static int getNewEmployeeId(void);

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
 * \return void No retorna valores.
 *
 */
static void printEmployeeWithoutHeader(sEmployee employee, sSector list[], int length);

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

int printEmployee(sEmployee employee, sSector list[], int length)
{
    int returnValue = -1;

    if(employee.isEmpty == FALSE)
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

                printEmployeeWithoutHeader(listEmployees[i], listSectors, lengthSectors);
                flagEmployees = 1;
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

static sEmployee newEmployee(char name[], char lastName[], float salary, int idSector)
{
    sEmployee auxEmployee;

    if(name != NULL && lastName != NULL)
    {
        auxEmployee.id = getNewEmployeeId();
        strcpy(auxEmployee.name, name);
        strcpy(auxEmployee.lastName, lastName);
        auxEmployee.salary = salary;
        auxEmployee.idSector = idSector;
        auxEmployee.isEmpty = FALSE;
    }
    else
    {
        auxEmployee.isEmpty = TRUE;
    }

    return auxEmployee;
}

static int getNewEmployeeId(void)
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

static void printEmployeeWithoutHeader(sEmployee employee, sSector list[], int length)
{
    char sectorName[SECTOR_NAME_MAX];

    if(list != NULL && length > 0 && length <= SECTOR_MAX
        && !findSectorNameById(sectorName, list, length, employee.idSector))
    {
        printf("| %4d | %13s | %13s | %11.2f | %26s |\n",
            employee.id, employee.name, employee.lastName, employee.salary, sectorName);
    }
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
