#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL
           && parser_EmployeeFromText(file, pArrayListEmployee))
        {
            returnValue = 1;
        }
    }

    fclose(file);

    return returnValue;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;

    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "rb");

        if(file != NULL
           && parser_EmployeeFromBinary(file, pArrayListEmployee))
        {
            returnValue = 1;
        }
    }

    return returnValue;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 0;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 0;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 0;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int counter = 0;
    int arrayLength;
    sEmployee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        for(counter = 0; counter < arrayLength; counter++)
        {
            if(counter == 0)
            {
                printf("+=======+======================+=======+============+\n");
                printf("|   ID  |        NOMBRE        | HORAS |   SALARIO  |\n");
                printf("+=======+======================+=======+============+\n");
            }

            aux = (sEmployee*)ll_get(pArrayListEmployee, counter);

            if(aux != NULL)
            {
                printf("| %5d | %20s | %5d | %10d |\n", aux->id, aux->name, aux->workHours, aux->salary);
            }
        }

        if(counter > 0 && counter == arrayLength)
        {
            printf("+-------+----------------------+-------+------------+\n");
        }
    }
    return counter;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 0;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 0;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;
    int returnValue = 0;
    int arrayLength;
    int i;
    sEmployee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        file = fopen(path, "wb");

        if(file != NULL && arrayLength > 0 && arrayLength <= EMPLOYEE_MAX)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = (sEmployee*)ll_get(pArrayListEmployee, i);

                if(aux == NULL
                   || fwrite((sEmployee*)aux, sizeof(sEmployee), 1, file) != 1)
                {
                    break;
                }
            }
        }

        if(i == arrayLength)
        {
            returnValue = 1;
        }
    }

    fclose(file);

    return returnValue;
}
