#include "arrayEmployees.h"

/** \brief Funcion para generar un nuevo ID de Empleados.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada Empleado.
 *
 */
static int getNewIdEmployee(void);

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

int printEmployees(sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors)
{
    int itemsCounter = 0;
    char sectorName[SECTOR_NAME_MAX];
    int flagEmployees = 0;

    if(listEmployees != NULL && lengthEmployees > 0 && lengthEmployees <= EMPLOYEE_MAX)
    {
        for (int i = 0; i < lengthEmployees; i++)
        {
            if(listEmployees[i].isEmpty == FALSE && !findSectorById(sectorName, listSectors, lengthSectors, listEmployees[i].idSector))
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+======+===============+===============+=============+==============+\n");
                    printf("|  ID  |    Nombre     |   Apellido    |   Salario   |    Sector    |\n");
                    printf("+======+===============+===============+=============+==============+\n");
                }
                
                printf("| %4d | %13s | %13s | %9.2f | %13s |",
                    listEmployees[i].id, listEmployees[i].name, listEmployees[i].lastName,
                    listEmployees[i].salary, sectorName);
                flagEmployees = 1;
            }
        }

        if(flagEmployees == 1)
        {
            printf("+------+---------------+---------------+-------------+--------------+\n");
        }
    }

    return itemsCounter;
}

int findSectorById(char* sectorName, sSector list[], int length, int idSector)
{
    int returnValue = -1;

    return returnValue;
}

static int getNewIdEmployee(void)
{
    static int id = ID_INIT_EMPLOYEE;
    id++;
    return id;
}

static sEmployee newEmployee(char name[], char lastName[], float salary, int idSector)
{
    sEmployee auxEmployee;

    if(name != NULL && lastName != NULL)
    {
        auxEmployee.id = getNewIdEmployee();
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
