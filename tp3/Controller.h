#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "parser.h"

#define CONTROLLER_LIST_MAX 20 /**< Maxima cantidad de estructuras a mostrar en el listado. >*/

/** \brief Carga los datos de las estructuras desde el archivo (modo texto).
 *
 * \param path char* Path de ubicacion del archivo de texto.
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int Cantidad de Empleados cargados en memoria dinamica.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de las estructuras desde el archivo (modo binario).
 *
 * \param path char* Path de ubicacion del archivo binario.
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int Cantidad de Empleados cargados en memoria dinamica.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar arreglo dinamico de estructuras en pantalla.
 *
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int Cantidad de estructuras impresas en pantalla.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de las estructuras en el archivo (modo texto).
 *
 * \param path char* Path de ubicacion del archivo de texto.
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int
 *          [0] si hubo un error al persistir a archivo de texto.
 *          [1] si se pudo guardar a archivo de texto correctamente.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de las estructuras en el archivo (modo binario).
 *
 * \param path char* Path de ubicacion del archivo binario.
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int
 *          [0] si hubo un error al persistir a archivo binario.
 *          [1] si se pudo guardar a archivo binario correctamente.
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
