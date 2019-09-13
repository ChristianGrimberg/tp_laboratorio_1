#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "input.h"

#define NAME_MAX 51 /**< Cantidad de caracteres para el nombre de un Empleado >*/
#define LASTNAME_MAX 51 /**< Cantidad de caracteres para el apellido de un Empleado >*/

/*! \struct sEmployee
    \brief Tipo de Dato de Empleado definido por el usuario.
*/
struct
{
    int id; /**< Campo identificador univoco por Empleado >*/
    char name[NAME_MAX];  /**< Campo del Nombre del Empleado >*/
    char lastName[LASTNAME_MAX];  /**< Campo del Apellido del Empleado >*/
    float salary; /**< Campo del salario del Empleado >*/
    int sector; /**< Campo del Sector del Empleado >*/
    int isEmpty; /**< Campo del estado de alta o baja de un Empleado >*/
}typedef sEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED