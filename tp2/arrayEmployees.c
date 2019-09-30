#include "arrayEmployees.h"

static sEmployee newEmployee(int id, char name[], char lastName[], float salary, int idSector);

static sEmployee newEmployee(int id, char name[], char lastName[], float salary, int idSector)
{
    sEmployee auxEmployee;

    if(name != NULL && lastName != NULL)
    {
        auxEmployee.id = id;
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