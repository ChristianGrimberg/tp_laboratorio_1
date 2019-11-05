#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "LinkedList.h"

#define ID_INIT_EMPLOYEE 0 /**< Valor inicial del ID de un Empleado. >*/
#define EMPLOYEE_MAX 1500 /**< Cantidad maxima de Empleados en un arreglo. >*/
#define EMPLOYEE_NAME_MAX 128 /**< Longitud maxima del Nombre de un Empleado. >*/
#define EMPLOYEE_WORKHOURS_MAX 750 /**< Cantidad de horas maximas trabajadas. >*/
#define EMPLOYEE_SALARY_MAX 500000 /**< Salario maximo de un Empleado. >*/

typedef struct
{
    int id;
    char name[EMPLOYEE_NAME_MAX];
    int workHours;
    int salary;
} sEmployee;

/** \brief Constructor que obtiene espacio en memoria
 *          requerido para una nueva estructura de Empleado.
 *
 * \param void No requiere parametros
 * \return sEmployee*
 *          [NULL] Si no se pudo reservar el espacio en memoria.
 *          Direccion de memoria dinamica obtenida
 *              con un Empleado con valores por defecto.
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
 * \param salary int* Direccion de memoria del Salario a cargar.
 * \return int
 *          [0] Si no pudo obtener el Salario.
 *          [1] Si pudo cargar el Salario.
 *
 */
int employee_getSalary(sEmployee* this, int* salary);

/** \brief Establece el salario a una estructura Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \param salary int Direccion de memoria del Salario a establecer.
 * \return int
 *          [0] Si no pudo establecer el Salario.
 *          [1] Si pudo establecer el Salario.
 *
 */
int employee_setSalary(sEmployee* this, int salary);

/** \brief Nueva estructura de Empleado ingresando los valores
 *          de sus campos por parametros.
 *
 * \param id int* Direccion de memoria del ID a cargar.
 * \param name[] char Direccion de memoria del Nombre a cargar.
 * \param workHours int* Direccion de memoria de las Horas Trabajadas a cargar.
 * \param salary int* Direccion de memoria del Salario a cargar.
 * \return sEmployee*
 *          [NULL] Si no se pudo reservar el espacio en memoria.
 *          Direccion de memoria dinamica obtenida
 *              con un Empleado con valores por parametro.
 *
 */
sEmployee* employee_newWithParameters(int* id, char name[], int* workHours, int* salary);

/** \brief Liberacion de memoria asignada a un Empleado.
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * \return void No retorna valores.
 *
 */
void employee_delete(sEmployee* this);

/** \brief Obtiene el proximo ID de Empleado de un arreglo LinkedList.
 *
 * \param pArrayListEmployee LinkedList* Arreglo de tipo LinkedList.
 * \return int Proximo ID de Empleado.
 *
 */
int employee_getNextId(LinkedList* pArrayListEmployee);

/** \brief Funcion que compara dos elementos casteados a Empleados por el ID.
 *
 * \param pElement1 void* Puntero a elemento generico.
 * \param pElement2 void* Puntero a elemento generico.
 * \return int
 *          [0] Si tienen el mismo ID.
 *          < 0 Si el primer ID es mayor que el segundo.
 *          > 0 Si el segundo ID es mayor que el primero.
 *
 */
int employee_compareByID(void* pElement1, void* pElement2);

/** \brief Funcion que compara dos elementos casteados a Empleados por el nombre.
 *
 * \param pElement1 void* Puntero a elemento generico.
 * \param pElement2 void* Puntero a elemento generico.
 * \return int
 *          [0] Si tienen el mismo nombre.
 *          < 0 Si el primer nombre esta primero en el diccionario.
 *          > 0 Si el segundo nombre esta primero en el diccionario.
 *
 */
int employee_compareByName(void* pElement1, void* pElement2);

/** \brief Funcion que compara dos elementos casteados a Empleados por el Horas Trabajadas.
 *
 * \param pElement1 void* Puntero a elemento generico.
 * \param pElement2 void* Puntero a elemento generico.
 * \return int
 *          [0] Si tienen la mismas carga de Horas Trabajadas.
 *          < 0 Si el primero tiene mas horas que el segundo.
 *          > 0 Si el segundo tiene mas horas que el primero.
 *
 */
int employee_compareByWorkHours(void* pElement1, void* pElement2);

/** \brief Funcion que compara dos elementos casteados a Empleados por el Salario.
 *
 * \param pElement1 void* Puntero a elemento generico.
 * \param pElement2 void* Puntero a elemento generico.
 * \return int
 *          [0] Si ambos tienen el mismo Salario.
 *          < 0 Si el primero tiene mejor Salario que el segundo.
 *          > 0 Si el segundo tiene mejor Salario que el primero.
 *
 */
int employee_compareBySalary(void* pElement1, void* pElement2);

#endif // EMPLOYEE_H_INCLUDED
