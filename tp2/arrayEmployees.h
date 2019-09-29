#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "menu.h"

#define EMPLOYEE_MAX 1000 /**< Cantidad maxima de la nomina de Empleados para la Empresa. >*/
#define EMPLOYEE_NAME_MAX 51 /**< Cantidad de caracteres para el nombre de un Empleado. >*/
#define EMPLOYEE_LASTNAME_MAX 51 /**< Cantidad de caracteres para el apellido de un Empleado. >*/
#define SECTOR_NAME_MAX 51 /**< Cantidad de caracteres para el nombre del sector. >*/

/*! \struct sEmployee
    \brief Tipo de Dato de Empleado definido por el usuario.
*/
struct
{
    int id; /**< Campo identificador univoco por Empleado. >*/
    char name[EMPLOYEE_NAME_MAX];  /**< Campo del Nombre del Empleado. >*/
    char lastName[EMPLOYEE_LASTNAME_MAX];  /**< Campo del Apellido del Empleado. >*/
    float salary; /**< Campo del salario del Empleado. >*/
    int idSector; /**< Campo ID externo del Sector del Empleado. >*/
    int isEmpty; /**< Campo del estado de alta o baja de un Empleado. >*/
}typedef sEmployee;

/*! \struct sSector
    \brief Tipo de Dato del Sector que pertenece un Empleado.
*/
struct
{
    int idSector; /**< .Campo ID principal del Sector del Empleado. >*/
    char name[SECTOR_NAME_MAX]; /**< Campo del nombre del sector. >*/
} typedef sSector;


/** \brief Funcion que blanquea todas las posiciones de un array de Empleados
 *          colocando la bandera isEmpty en TRUE.
 * 
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \return
 *      [-1] Si hubo un error.
 *      [0] Si el blanqueo fue realizado con exito.
 *
 */
int initEmployees(sEmployee list[], int length);

#endif // ARRAYEMPLOYEES_H_INCLUDED
