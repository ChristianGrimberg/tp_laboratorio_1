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
    int returnValue = 0;
    int id;
    int max;
    int index;
    int lifeCycle;
    int editMenu;
    sEmployee* beforeEdit = employee_new();
    sEmployee* afterEdit;

    if(pArrayListEmployee != NULL && beforeEdit != NULL)
    {
        max = employee_getNextId(pArrayListEmployee) - 1;

        if(max > 0 && !inputs_getInt(&id, "Ingrese el ID del Empleado que desea editar: ", ERROR_MESSAGE, 1, max))
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);

            if(index != -1)
            {
                beforeEdit = (sEmployee*)ll_get(pArrayListEmployee, index);

                if(beforeEdit != NULL)
                {
                    afterEdit = employee_newWithParameters(&beforeEdit->id, beforeEdit->name, &beforeEdit->workHours, &beforeEdit->salary);

                    do
                    {
                        inputs_clearScreen();

                        if(employee_print(afterEdit) == 0)
                        {
                            break;
                        }

                        lifeCycle = menu_edit(&editMenu);

                        switch(editMenu)
                        {
                        case 1: /**< Editar el Nombre. >*/
                            if(!inputs_getString(afterEdit->name, "Ingrese nuevo Nombre: ", ERROR_MESSAGE, 1, EMPLOYEE_NAME_MAX)
                               && employee_setName(afterEdit, afterEdit->name))
                            {
                                printf("Nombre cambiado, elija la opcion %d para aplicarlo.\n", MENU_EDIT_MAX);
                            }
                            break;
                        case 2: /**< Editar las Horas Trabajadas. >*/
                            if(!inputs_getInt(&afterEdit->workHours, "Ingrese las Horas Trabajadas: ", ERROR_MESSAGE, 0, EMPLOYEE_WORKHOURS_MAX)
                               && employee_setWorkHours(afterEdit, afterEdit->workHours))
                            {
                                printf("Horas Trabajadas cambiadas, elija la opcion %d para aplicarlo.\n", MENU_EDIT_MAX);
                            }
                            break;
                        case 3: /**< Editar el Salario. >*/
                            if(!inputs_getInt(&afterEdit->salary, "Ingresa el nuevo Salario: ", ERROR_MESSAGE, 0, EMPLOYEE_SALARY_MAX)
                               && employee_setSalary(afterEdit, afterEdit->salary))
                            {
                                printf("Salario cambiado, elija la opcion %d para aplicarlo.\n", MENU_EDIT_MAX);
                            }
                            break;
                        case 4: /**< Confirmar cambios y volver al menu principal. >*/
                            inputs_clearScreen();

                            printf("El siguiente Empleado:\n");
                            if(employee_print(beforeEdit))
                            {
                                printf("Sera modificado de la siguiente forma:\n");
                                if(employee_print(afterEdit)
                                   && inputs_userResponse("Acepta la modificacion? [S] o [N]: ")
                                   && ll_set(pArrayListEmployee, index, (sEmployee*)afterEdit) == 0)
                                {
                                    returnValue = 1;
                                }
                            }
                            lifeCycle = 1;
                            break;
                        }

                        if(editMenu < MENU_EDIT_MAX)
                        {
                            inputs_pauseScreen(ENTER_MESSAGE);
                        }
                    }while(lifeCycle == 0);
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

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int id;
    int index;
    int max;
    sEmployee* aux = employee_new();

    if(pArrayListEmployee != NULL && aux != NULL)
    {
        max = employee_getNextId(pArrayListEmployee) - 1;

        if(max > 0 && !inputs_getInt(&id, "Ingrese el ID del Empleado que desea dar de baja: ", ERROR_MESSAGE, 1, max))
        {
            index = getIndexByEmployeeID(pArrayListEmployee, id);

            if(index != -1)
            {
                aux = (sEmployee*)ll_get(pArrayListEmployee, index);

                if(aux != NULL
                   && employee_print(aux)
                   && inputs_userResponse("Desea dar de baja el Empleado? [S] o [N]: "))
                {
                    if(ll_remove(pArrayListEmployee, index) == 0)
                    {
                        returnValue = 1;
                        free(aux);
                        aux = NULL;
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
    int counter;
    int multiplier = 0;
    int employeeQty;
    int listMin = 0;
    int listMax = 0;
    sEmployee* aux;
    LinkedList* subList = ll_newLinkedList();

    if(pArrayListEmployee != NULL && subList != NULL)
    {
        employeeQty = ll_len(pArrayListEmployee);

        while(listMin < employeeQty)
        {
            inputs_clearScreen();

            multiplier++;

            if(employeeQty > (multiplier * CONTROLLER_LIST_MAX))
            {
                listMax = listMin + CONTROLLER_LIST_MAX;
            }
            else
            {
                listMax = employeeQty;
            }

            subList = ll_subList(pArrayListEmployee, listMin, listMax);

            for(counter = listMin; counter < listMax; counter++)
            {
                if(counter == listMin)
                {
                    printf("+=======+======================+=======+============+\n");
                    printf("|   ID  |        NOMBRE        | HORAS |   SALARIO  |\n");
                    printf("+=======+======================+=======+============+\n");
                }

                aux = (sEmployee*)ll_get(pArrayListEmployee, counter);

                if(aux != NULL)
                {
                    printf("| %5d | %20s | %5d | %10d |\n",
                           aux->id, arrays_stringToCamelCase(aux->name, EMPLOYEE_NAME_MAX),
                           aux->workHours, aux->salary);
                }
            }

            if(counter > 0 && counter == listMax)
            {
                printf("+-------+----------------------+-------+------------+\n");
            }

            listMin = counter;

            if(listMin < employeeQty)
            {
                inputs_pauseScreen(PAGE_MESSAGE);
            }
        }
    }
    return listMax;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int lifeCycle;
    int sortMenu;
    int sortOption;

    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            do
            {
                lifeCycle = menu_sort(&sortMenu);

                if((sortMenu >= 1 && sortMenu < MENU_SORT_MAX)
                   && !inputs_getInt(&sortOption, "Ingrese para ordenar: [1] Ascendente - [0] Descendente: ", ERROR_MESSAGE, 0, 1))
                {
                    printf("Aguarde unos instantes...\n");

                    switch(sortMenu)
                    {
                    case 1: /**< Ordenar por ID. >*/
                        if(ll_sort(pArrayListEmployee, employee_compareByID, sortOption) == 0)
                        {
                            printf("Ordenado por ID finalizado.\n");
                        }
                        break;
                    case 2: /**< Ordenar por Nombre. >*/
                        if(ll_sort(pArrayListEmployee, employee_compareByName, sortOption) == 0)
                        {
                            printf("Ordenado por Nombre finalizado.\n");
                        }
                        break;
                    case 3: /**< Ordenar por Horas Trabajadas. >*/
                        if(ll_sort(pArrayListEmployee, employee_compareByWorkHours, sortOption) == 0)
                        {
                            printf("Ordenado por Horas Trabajadas finalizado.\n");
                        }
                        break;
                    case 4: /**< Ordenar por Salario de forma Ascendente. >*/
                        if(ll_sort(pArrayListEmployee, employee_compareBySalary, sortOption) == 0)
                        {
                            printf("Ordenado por Salario finalizado.\n");
                        }
                        break;
                    }
                }
                else
                {
                    if(sortMenu == MENU_SORT_MAX)
                    {
                        returnValue = 1;
                        break;
                    }
                }
                inputs_pauseScreen(ENTER_MESSAGE);
            }while(lifeCycle == 0);
        }
    }

    return returnValue;
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
