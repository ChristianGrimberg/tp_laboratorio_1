#include "Controller.h"

/** \brief Busqueda de indice de Empledo en arreglo generico por ID.
 *
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \param id int ID del Empleado a buscar.
 * \return int
 *          [-1] Si no se pudo encontrar el ID.
 *          Indice del ID del Empleado buscado.
 *
 */
static int getIndexByEmployeeID(LinkedList* pArrayListEmployee, int id);

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int counter = 0;
    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
            counter = parser_EmployeeFromText(file, pArrayListEmployee);
        }
    }

    fclose(file);

    return counter;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int counter = 0;

    FILE* file = NULL;

    if(pArrayListEmployee != NULL)
    {
        file = fopen(path, "rb");

        if(file != NULL)
        {
            counter = parser_EmployeeFromBinary(file, pArrayListEmployee);
        }
    }

    return counter;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int id;
    int workHours;
    int salary;
    char name[EMPLOYEE_NAME_MAX];
    sEmployee* aux = NULL;

    if(pArrayListEmployee != NULL)
    {
        id = employee_getNextId(pArrayListEmployee);

        if(id != -1
           && !inputs_getString(name, "Ingrese el nombre del Empleado: ", ERROR_MESSAGE, 1, EMPLOYEE_NAME_MAX)
           && !inputs_getInt(&workHours, "Ingrese las Horas Trabajadas: ", ERROR_MESSAGE, 0, EMPLOYEE_WORKHOURS_MAX)
           && !inputs_getInt(&salary, "Ingrese el Salario: ", ERROR_MESSAGE, 0, EMPLOYEE_SALARY_MAX))
        {
            aux = employee_newWithParameters(&id, arrays_stringToCamelCase(name, EMPLOYEE_NAME_MAX), &workHours, &salary);

            if(aux != NULL
               && ll_add(pArrayListEmployee, (sEmployee*)aux) == 0)
            {
                returnValue = 1;
            }
        }
    }

    return returnValue;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 0;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int id;
    int index;
    int max;
    sEmployee* aux;
    LinkedList* sublist;

    if(pArrayListEmployee != NULL)
    {
        max = employee_getNextId(pArrayListEmployee) - 1;

        if(max > 0 && !inputs_getInt(&id, "Ingrese el ID del Empleado que desea dar de baja: ", ERROR_MESSAGE, 1, max))
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);

            if(index != -1)
            {
                sublist = ll_subList(pArrayListEmployee, index, index + 1);

                if(sublist != NULL && controller_ListEmployee(sublist) == 1
                   && inputs_userResponse("Desea dar de baja el Empleado? [S] o [N]: "))
                {
                    aux = (sEmployee*)ll_get(pArrayListEmployee, index);

                    if(aux != NULL
                       && ll_remove(pArrayListEmployee, index) == 0)
                    {
                        returnValue = 1;
                    }
                }
            }
            else
            {
                printf("No se encontro el Empleado ingresado.\n");
            }
        }
    }

    return returnValue;
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
    FILE* file = NULL;
    int returnValue = 0;
    int arrayLength;
    int i;
    sEmployee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        file = fopen(path, "w");

        if(file != NULL
           && arrayLength > 0 && arrayLength <= EMPLOYEE_MAX
           && fprintf(file, "id,nombre,horasTrabajadas,sueldo\n") != -1)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = (sEmployee*)ll_get(pArrayListEmployee, i);

                if(aux == NULL
                   || fprintf(file, "%d,%s,%d,%d\n", aux->id, aux->name, aux->workHours, aux->salary) == -1)
                {
                    break;
                }
            }
        }

        if(i > 0 && i == arrayLength)
        {
            returnValue = 1;
        }
    }

    fclose(file);

    return returnValue;
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

        if(i > 0 && i == arrayLength)
        {
            returnValue = 1;
        }
    }

    fclose(file);

    return returnValue;
}

static int getIndexByEmployeeID(LinkedList* pArrayListEmployee, int id)
{
    int returnValue = -1;
    int arrayLength;
    int i;
    sEmployee* aux;

    if(pArrayListEmployee != NULL)
    {
        arrayLength = ll_len(pArrayListEmployee);

        if(arrayLength > 0)
        {
            for(i = 0; i < arrayLength; i++)
            {
                aux = ll_get(pArrayListEmployee, i);

                if(aux != NULL
                   && aux->id == id)
                {
                    returnValue = i;
                    break;
                }
            }
        }
    }

    return returnValue;
}
