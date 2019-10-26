#include "Employee.h"

sEmployee* employee_new()
{
    sEmployee* aux;

    aux = (sEmployee*)malloc(sizeof(sEmployee));

    if(aux != NULL)
    {
        aux->id = -1;
        strcpy(aux->name, "NULL");
        aux->salary = 0.0f;
    }

    return aux;
}

int employee_getId(sEmployee* this, int* id)
{
    int returnValue = 0;

    if(this != NULL)
    {
        *id = this->id;
        returnValue = 1;
    }

    return returnValue;
}

int employee_setId(sEmployee* this, int id)
{
    int returnValue;

    if(this != NULL
       && id > ID_INIT_EMPLOYEE)
    {
        this->id = id;
        returnValue = 1;
    }

    return returnValue;
}

int employee_getName(sEmployee* this, char* name)
{
    int returnValue = 0;

    if(this != NULL
       && this->name !=NULL)
    {
        strcpy(name, this->name);
        returnValue = 1;
    }

    return returnValue;
}

int employee_setName(sEmployee* this, char* name)
{
    int returnValue;

    if(this != NULL
       && this->name !=NULL
       && name != NULL)
    {
        strcpy(this->name, name);
        returnValue = 1;
    }

    return returnValue;
}

int employee_getWorkHours(sEmployee* this, int* workHours)
{
    int returnValue = 0;

    if(this != NULL)
    {
        workHours = &(this->workHours);
        returnValue = 1;
    }

    return returnValue;
}

int employee_setWorkHours(sEmployee* this, int workHours)
{
    int returnValue;

    if(this != NULL
       && workHours >= 0)
    {
        this->workHours = workHours;
        returnValue = 1;
    }

    return returnValue;
}

int employee_getSalary(sEmployee* this, float* salary)
{
    int returnValue = 0;

    if(this != NULL)
    {
        salary = &(this->salary);
        returnValue = 1;
    }

    return returnValue;
}

int employee_setSalary(sEmployee* this, float salary)
{
    int returnValue;

    if(this != NULL
       && salary >= 0)
    {
        this->salary = salary;
        returnValue = 1;
    }

    return returnValue;
}

sEmployee* employee_newWithParameters(char* id, char* name, int* workHours, float* salary)
{
    sEmployee* aux;

    aux = employee_new();

    if(aux != NULL
       && employee_setId(aux, *id)
       && employee_setName(aux, name)
       && employee_setWorkHours(aux, *workHours)
       && employee_setSalary(aux, *salary))
    {
        printf("Empleado cargado con exito.\n");
    }

    return aux;
}
