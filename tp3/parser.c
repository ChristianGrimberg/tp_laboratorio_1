#include "parser.h"

/** \brief Convierte una cadena a entero validando
 *      incluso el cero.
 *
 * \param string[] char Cadena de caracteres a convertir.
 * \param integerValue int* Entero a escribir el valor convertido.
 * \return int
 *          [0] Si hubo un error en la conversion.
 *          [1] Si la conversion fue exitosa.
 *
 */
static int stringToInteger(char string[], int* integerValue);

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
               && stringToInteger(stringId, &id) && name != NULL
               && stringToInteger(stringWorkHours, &workHours) && stringToInteger(stringSalary, &salary))
            {
                aux = employee_newWithParameters(&id, name, &workHours, &salary);

                if(aux != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && ll_add(pArrayListEmployee, (sEmployee*)aux) == 0)
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

static int stringToInteger(char string[], int* integerValue)
{
    int returnValue = 0;

    if(string != NULL)
    {
        if(strcmp(string, "0") == 0)
        {
            *integerValue = 0;
            returnValue = 1;
        }
        else
        {
            *integerValue = atoi(string);
            returnValue = 1;
        }
    }

    return returnValue;
}
