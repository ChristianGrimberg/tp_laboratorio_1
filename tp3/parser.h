#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "Employee.h"

/** \brief Parsea los datos de estructuras de tipo Empleado desde el archivo (modo texto)
 *          y los agrega a un arreglo de tipo LinkedList.
 *
 * \param pFile FILE* Puntero a archivo de texto.
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int Cantidad de estructuras de tipo Empleado parseadas desde archivo de texto.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de estructuras de tipo Empleado desde el archivo (modo binario)
 *          y los agrega a un arreglo de tipo LinkedList.
 *
 * \param pFile FILE* Puntero a archivo binario.
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int Cantidad de estructuras de tipo Empleado parseadas desde archivo binario.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
