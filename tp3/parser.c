#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int id;
    int workHours;
    int salary;
    int counter = 0;
    char buffer[4][EMPLOYEE_NAME_MAX];
    sEmployee* aux;

    if(pFile != NULL
       && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4
               && inputs_stringToInteger(buffer[0], &id) && buffer[1] != NULL
               && inputs_stringToInteger(buffer[2], &workHours)
               && inputs_stringToInteger(buffer[3], &salary))
            {
                aux = employee_newWithParameters(&id, buffer[1], &workHours, &salary);

                if(aux != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && ll_add(pArrayListEmployee, (sEmployee*)aux) == 0)
                {
                    counter++;
                }
            }
        }
    }

    return counter;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int counter = 0;
    sEmployee auxStatic;
    sEmployee* auxDinamic = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((sEmployee*)&auxStatic, sizeof(sEmployee), 1, pFile) == 1)
            {
                auxDinamic = employee_newWithParameters(&(auxStatic.id), auxStatic.name, &(auxStatic.workHours), &(auxStatic.salary));

                if(auxDinamic != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && ll_add(pArrayListEmployee, (sEmployee*)auxDinamic) == 0)
                {
                    counter++;
                }
            }
        }
    }

    return counter;
}
