#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "menu.h"

#define ID_INIT_EMPLOYEE 0 /**< Valor inicial de un ID de Empleado. >*/
#define EMPLOYEE_MAX 1000 /**< Cantidad maxima de la nomina de Empleados para la Empresa. >*/
#define EMPLOYEE_NAME_MAX 51 /**< Cantidad de caracteres para el nombre de un Empleado. >*/
#define EMPLOYEE_LASTNAME_MAX 51 /**< Cantidad de caracteres para el apellido de un Empleado. >*/
#define SECTOR_NAME_MAX 51 /**< Cantidad de caracteres para el nombre del sector. >*/

/*! \struct sEmployee
    \brief Tipo de Dato de Empleado definido por el usuario.
*/
typedef struct
{
    int id; /**< Campo identificador univoco por Empleado. >*/
    char name[EMPLOYEE_NAME_MAX];  /**< Campo del Nombre del Empleado. >*/
    char lastName[EMPLOYEE_LASTNAME_MAX];  /**< Campo del Apellido del Empleado. >*/
    float salary; /**< Campo del salario del Empleado. >*/
    int idSector; /**< Campo ID externo del Sector del Empleado. >*/
    int isEmpty; /**< Campo del estado de alta o baja de un Empleado. >*/
} sEmployee;

typedef struct
{
    int idSector; /**< .Campo ID principal del Sector del Empleado. >*/
    char name[SECTOR_NAME_MAX]; /**< Campo del nombre del sector. >*/
} sSector;


/** \brief Funcion que blanquea todas las posiciones de un array de Empleados
 *          colocando la bandera isEmpty en TRUE.
 * 
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si hubo un error.
 *      [0] Si el blanqueo fue realizado con exito.
 *
 */
int initEmployees(sEmployee list[], int length);

/** \brief Funcion que agrega un Empleado
 *      con los valores cargados como parametros
 *      en el primer lugar vacio de la lista ingresada.
 * 
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \param id int ID del Empleado.
 * \param name[] char Nombre del Empleado.
 * \param lastName[] char Apellido del Empleado.
 * \param salary float Salario del Empleado.
 * \param sector int ID exteno del sector del Empleado.
 * \return int
 *      [-1] Si hubo un error en la carga del Empleado en la lista.
 *      [0] Si la carga del Empleado en la lista fue exitosa.
 *
 */
int addEmployee(sEmployee list[], int length, int id, char name[], char lastName[], float salary, int sector);

/** \brief Funcion que obtiene el indice del array de Empleados
 *          del ID ingresado como parametro.
 * 
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \param id int Campo ID del Empleado a buscar.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Encuentra el valor entero del ID del Empleado buscado.
 * 
 */
int findEmployeeById(sEmployee list[], int length, int id);

/** \brief Borra un Empleado de una lista mediante su ID
 *      e informando el campo isEmpty como vacio.
 *
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \param id int Campo ID del Empleado a borrar.
 * \return int
 *      [-1] Si hubo un error para borrar el Empleado de la lista.
 *      [0] Si el borrado del Empleado de la lista fue exitosa.
 *
 */
int removeEmployee(sEmployee list[], int length, int id);

/** \brief Funcion que ordena a los Empleados de la lista
 *      de forma Ascendente o Descendente.
 *
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \param order int [ASC] Orden Ascendente - [DESC] orden Descendente.
 * \return int
 *      [-1] Si hubo un error para ordenar los Empleados de la lista.
 *      [0] Si el ordenado de los Empleados de la lista fue exitosa.
 *
 */
int sortEmployees(sEmployee list[], int length, int order);

/** \brief Imprime en pantalla el contenido de la lista de Empleados.
 *
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array de Empleados.
 * \param listSectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param lengthSectors int Longitud del array de Sectores.
 * \return int La cantidad de elementos del array.
 *
 */
int printEmployees(sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors);

/** \brief Busca el nombre del Sector por el ID.
 *
 * \param sectorName char* Nombre encontrado del Sector.
 * \param list[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array.
 * \param idSector int ID del Sector a buscar.
 * \return char*
 *      [-1] Si no existe el ID.
 *      [0] Si el Sector fue encontrado con exito.
 *
 */
int findSectorById(char* sectorName, sSector list[], int length, int idSector);

#endif // ARRAYEMPLOYEES_H_INCLUDED
