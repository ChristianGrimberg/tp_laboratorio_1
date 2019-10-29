#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

/** \brief Parsea los datos de estructuras de tipo Empleado desde el archivo (modo texto)
 *          y los agrega a un arreglo de tipo LinkedList.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de estructuras de tipo Empleado desde el archivo (modo binario)
 *          y los agrega a un arreglo de tipo LinkedList.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
