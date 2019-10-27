#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int i = 0;
    int id;
    int workHours;
    int salary;
    char stringId[25];
    char name[EMPLOYEE_NAME_MAX];
    char stringWorkHours[25];
    char stringSalary[25];
    sEmployee* aux;

    if(pFile != NULL
       && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", stringId, name, stringWorkHours, stringSalary) == 4
               && i > 0)
            {
                id = atoi(stringId);
                workHours = atoi(stringWorkHours);
                salary = atoi(stringSalary);

                aux = employee_newWithParameters(&id, name, &workHours, &salary);

                if(aux != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && !ll_add(pArrayListEmployee, (sEmployee*)aux))
                {
                    returnValue = 1;
                }
            }

            i++;
        }
    }

    return returnValue;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 0;
}
