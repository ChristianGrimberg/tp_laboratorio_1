#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "inputs.h"

#define EMPLOYEE_NAME_MAX 128 /**< Longitud maxima del Nombre de un Empleado. >*/
#define ID_INIT_EMPLOYEE 0 /**< Valor inicial del ID de un Empleado. >*/
#define EMPLOYEE_MAX 1000 /**< Cantidad maxima de Empleados en un arreglo. >*/

typedef struct
{
    int id;
    char name[EMPLOYEE_NAME_MAX];
    int workHours;
    float salary;
} sEmployee;

/** \brief Obtencion de espacio en memoria
 *          para una nueva estructura de Empleado.
 *
 * \param void No requiere parametros
 * \return sEmployee*
 *          Direccion de memoria dinamica obtenida
 *      con un Empleado con valores por defecto.
 *          [NULL] Si no se pudo reservar el espacio en memoria.
 *
 */
sEmployee* employee_new(void);

/** \brief Obtener el ID de una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param id int* Direccion de memoria del ID a cargar.
 * \return int
 *          [0] Si no pudo obtener el ID.
 *          [1] Si pudo cargar el ID.
 *
 */
int employee_getId(sEmployee* this, int* id);

/** \brief Establece el ID a una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param id int Direccion de memoria del ID a establecer.
 * \return int
 *          [0] Si no pudo establecer el ID.
 *          [1] Si pudo establecer el ID.
 *
 */
int employee_setId(sEmployee* this, int id);

/** \brief Obtiene el Nombre de una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param name[] char Direccion de memoria del Nombre a cargar.
 * \return int
 *          [0] Si no pudo obtener el Nombre.
 *          [1] Si pudo cargar el Nombre.
 *
 */
int employee_getName(sEmployee* this, char name[]);

/** \brief Establece el Nombre a una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param name[] char Direccion de memoria del Nombre a establecer.
 * \return int
 *          [0] Si no pudo establecer el Nombre.
 *          [1] Si pudo establecer el Nombre.
 *
 */
int employee_setName(sEmployee* this, char name[]);

/** \brief Obtiene las horas trabajadas de una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param workHours int* Direccion de memoria de las Horas Trabajadas a cargar.
 * \return int
 *          [0] Si no pudo obtener las Horas Trabajadas.
 *          [1] Si pudo cargar las Horas Trabajadas.
 *
 */
int employee_getWorkHours(sEmployee* this, int* workHours);

/** \brief Establece las Horas Trabajadas a una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param workHours int Direccion de memoria de las Horas Trabajadas a establecer.
 * \return int
 *          [0] Si no pudo establecer las Horas Trabajadas.
 *          [1] Si pudo establecer las Horas Trabajadas.
 *
 */
int employee_setWorkHours(sEmployee* this, int workHours);

/** \brief Obtiene el Salario de una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param salary float* Direccion de memoria del Salario a cargar.
 * \return int
 *          [0] Si no pudo obtener el Salario.
 *          [1] Si pudo cargar el Salario.
 *
 */
int employee_getSalary(sEmployee* this, float* salary);

/** \brief Establece el salario a una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param salary float Direccion de memoria del Salario a establecer.
 * \return int
 *          [0] Si no pudo establecer el Salario.
 *          [1] Si pudo establecer el Salario.
 *
 */
int employee_setSalary(sEmployee* this, float salary);

sEmployee* employee_newWithParameters(char* id, char* name, int* workHours, float* salary);

void employee_delete();

#endif // EMPLOYEE_H_INCLUDED
