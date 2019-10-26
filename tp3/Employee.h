#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "inputs.h"

#define EMPLOYEE_NAME_MAX 128 /**< Longitud maxima del Nombre de un Empleado. >*/
#define ID_INIT_EMPLOYEE 1000 /**< Valor inicial del ID de un Empleado. >*/

typedef struct
{
    int id;
    char name[EMPLOYEE_NAME_MAX];
    int workHours;
    float salary;
} sEmployee;

/** \brief Obtencion de espacio en memoria
 *          para una nueva estructura vacia.
 *
 * \param void No requiere parametros
 * \return sEmployee*
 *          Direccion de memoria dinamica obtenida
 *      de una estructura sin valores.
 *          [NULL] Si no se pudo reservar el espacio en memoria.
 *
 */
sEmployee* employee_new(void);

int employee_getId(sEmployee* this, int* id);
int employee_setId(sEmployee* this, int id);

int employee_getName(sEmployee* this, char* name);
int employee_setName(sEmployee* this, char* name);

int employee_getWorkHours(sEmployee* this, int* workHours);
int employee_setWorkHours(sEmployee* this, int workHours);

int employee_getSalary(sEmployee* this, float* salary);
int employee_setSalary(sEmployee* this, float salary);

sEmployee* employee_newWithParameters(char* id, char* name, int* workHours, float* salary);

void employee_delete();

#endif // EMPLOYEE_H_INCLUDED
