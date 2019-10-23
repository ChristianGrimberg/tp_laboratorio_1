#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "Controller.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
