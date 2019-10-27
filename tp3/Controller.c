#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    FILE* file = fopen(path, "r");

    if(file != NULL
       && parser_EmployeeFromText(file, pArrayListEmployee))
    {
        returnValue = 1;
    }

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
    return 0;
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
    return 0;
}

