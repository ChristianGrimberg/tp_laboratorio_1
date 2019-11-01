#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    FILE* file = fopen(path, "r");

    if(file != NULL
       && pArrayListEmployee != NULL
       && parser_EmployeeFromText(file, pArrayListEmployee))
    {
        returnValue = 1;
    }

    fclose(file);

    return returnValue;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 0;
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
    int i;
    sEmployee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        for(i = 0; i < arrayLength; i++)
        {
            if((pArrayListEmployee + i) != NULL)
            {
                aux = (sEmployee*)ll_get(pArrayListEmployee, i);
                printf("| %5d | %20s | %5d | %10d |\n", aux->id, aux->name, aux->workHours, aux->salary);
            }
        }

        counter = i;
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
    int returnValue = 0;
    FILE* file = fopen(path, "wb");
    int arrayLength;
    int i;

    if(file != NULL
       && pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        for(i = 0; i < arrayLength; i++)
        {
            if((&pArrayListEmployee + i) == NULL)
            {
                continue;
            }
            else
            {
                if(fwrite((sEmployee*)(&pArrayListEmployee + i), sizeof(sEmployee), 1, file) != 1)
                {
                    break;
                }
            }
        }

        if(i > 0
           && i == arrayLength)
        {
            returnValue = 1;
        }
    }

    fclose(file);

    return returnValue;
}

