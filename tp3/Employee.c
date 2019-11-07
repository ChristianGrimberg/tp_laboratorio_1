#include "Employee.h"

sEmployee* employee_new()
{
    sEmployee* aux;

    aux = (sEmployee*)malloc(sizeof(sEmployee));

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
    int returnValue = 0;

    if(this != NULL
       && id > ID_INIT_EMPLOYEE
       && id <= EMPLOYEE_MAX)
    {
        this->id = id;
        returnValue = 1;
    }

    return returnValue;
}

int employee_getName(sEmployee* this, char name[])
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

int employee_setName(sEmployee* this, char name[])
{
    int returnValue = 0;

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
        *workHours = this->workHours;
        returnValue = 1;
    }

    return returnValue;
}

int employee_setWorkHours(sEmployee* this, int workHours)
{
    int returnValue = 0;

    if(this != NULL
       && workHours >= 0
       && workHours <= EMPLOYEE_WORKHOURS_MAX)
    {
        this->workHours = workHours;
        returnValue = 1;
    }

    return returnValue;
}

int employee_getSalary(sEmployee* this, int* salary)
{
    int returnValue = 0;

    if(this != NULL)
    {
        *salary = this->salary;
        returnValue = 1;
    }

    return returnValue;
}

int employee_setSalary(sEmployee* this, int salary)
{
    int returnValue = 0;

    if(this != NULL
       && salary >= 0
       && salary <= EMPLOYEE_SALARY_MAX)
    {
        this->salary = salary;
        returnValue = 1;
    }

    return returnValue;
}

sEmployee* employee_newWithParameters(int* id, char name[], int* workHours, int* salary)
{
    sEmployee* aux = employee_new();

    if(aux != NULL
       && (!employee_setId(aux, *id)
       || !employee_setName(aux, name)
       || !employee_setWorkHours(aux, *workHours)
       || !employee_setSalary(aux, *salary)))
    {
        free(aux);
        aux = NULL;
    }

    return aux;
}

void employee_delete(sEmployee* this)
{
    free(this);
    this = NULL;
}

int employee_print(sEmployee* this)
{
    int returnValue = -1;
    int id;
    char name[EMPLOYEE_NAME_MAX];
    int workHours;
    int salary;

    if(this != NULL
       && employee_getId(this, &id)
       && employee_getName(this, name)
       && employee_getWorkHours(this, &workHours)
       && employee_getSalary(this, &salary))
    {
        printf("+=======+======================+=======+============+\n");
        printf("|   ID  |        NOMBRE        | HORAS |   SALARIO  |\n");
        printf("+=======+======================+=======+============+\n");
        printf("| %5d | %20s | %5d | %10d |\n",
               id, arrays_stringToCamelCase(name, EMPLOYEE_NAME_MAX), workHours, salary);
        printf("+-------+----------------------+-------+------------+\n");

        returnValue = 1;
    }

    return returnValue;
}

int employee_getNextId(LinkedList* pArrayListEmployee)
{
    int maxValue = -1;
    int arrayLength = 0;
    int i;
    int counter = 0;
    sEmployee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = (sEmployee*)ll_get(pArrayListEmployee, i);

                if(aux != NULL)
                {
                    if(counter == 0)
                    {
                        maxValue = aux->id;
                    }
                    else
                    {
                        if(aux->id > maxValue
                           && aux->id < EMPLOYEE_MAX)
                        {
                            maxValue = aux->id;
                        }
                    }

                    counter++;
                }
            }
        }

        if(counter > 0)
        {
            maxValue++;
        }
        else
        {
            maxValue = 1;
        }
    }

    return maxValue;
}

int employee_compareByID(void* pElement1, void* pElement2)
{
    int compare;
    int result;
    sEmployee* aux1 = (sEmployee*)pElement1;
    sEmployee* aux2 = (sEmployee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->id - aux2->id;

        if(result > 0)
        {
            compare = 1;
        }
        else
        {
            if(result < 0)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}

int employee_compareByName(void* pElement1, void* pElement2)
{
    int compare;
    sEmployee* aux1 = (sEmployee*)pElement1;
    sEmployee* aux2 = (sEmployee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        compare = strcmp(arrays_stringToCamelCase(aux1->name, EMPLOYEE_NAME_MAX), arrays_stringToCamelCase(aux2->name, EMPLOYEE_NAME_MAX));
    }

    return compare;
}

int employee_compareByWorkHours(void* pElement1, void* pElement2)
{
    int compare;
    int result;
    sEmployee* aux1 = (sEmployee*)pElement1;
    sEmployee* aux2 = (sEmployee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->workHours - aux2->workHours;

        if(result > 0)
        {
            compare = 1;
        }
        else
        {
            if(result < 0)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}

int employee_compareBySalary(void* pElement1, void* pElement2)
{
    int compare;
    int result;
    sEmployee* aux1 = (sEmployee*)pElement1;
    sEmployee* aux2 = (sEmployee*)pElement2;

    if(aux1 != NULL && aux2 != NULL)
    {
        result = aux1->salary- aux2->salary;

        if(result > 0)
        {
            compare = 1;
        }
        else
        {
            if(result < 0)
            {
                compare = -1;
            }
            else
            {
                compare = 0;
            }
        }
    }

    return compare;
}
