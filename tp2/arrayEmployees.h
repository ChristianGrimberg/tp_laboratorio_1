#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "menu.h"

#define ID_INIT_EMPLOYEE 1000 /**< Valor inicial de un ID de Empleado. >*/
#define EMPLOYEE_MAX 1000 /**< Cantidad maxima de la nomina de Empleados para la Empresa. >*/
#define EMPLOYEE_NAME_MAX 51 /**< Cantidad de caracteres para el nombre de un Empleado. >*/
#define EMPLOYEE_LASTNAME_MAX 51 /**< Cantidad de caracteres para el apellido de un Empleado. >*/
#define ID_INIT_SECTOR 10 /**< Valor inicial de un ID de Sectores. >*/
#define SECTOR_MAX 8 /**< Cantidad maxima de Sectores que gestiona la aplicacion. >*/
#define SECTOR_NAME_MAX 51 /**< Cantidad de caracteres para el nombre del sector. >*/
#define SALARY_MAX 10000000 /**< Salario maximo definido para el programa. >*/
#define ERROR_MESSAGE "Error, intente nuevamente: " /**< Mensaje de error por defecto. >*/
#define WITH_HARDCODE FALSE /**< Opcion para precargar las estructuras con datos de ejemplo. >*/
#define ASC 1 /**< Metodo para ordenar de forma Ascendente. >*/
#define DESC 0 /**< Metodo para ordenar de forma Descendente. >*/

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

/** \brief Funcion para generar un nuevo ID de Empleados.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada Empleado.
 *
 */
int getNewEmployeeId(void);

/** \brief Funcion que compara dos Empleados por ID unicos.
 * 
 * \param employee1 sEmployee Tipo de Dato de Empleado.
 * \param employee2 sEmployee Tipo de Dato de Empleado.
 * \return int
 *      [0] Se retorna cuando al menos sus ID son iguales.
 *      [1] Se retorna cuando el Empleado 1 tiene ID mayor.
 *      [-1] Se retorna cuando el Empleado 2 tiene ID mayor.
 *      [-2] Se retorna cuando hubo un error.
 * 
 */
int compareEmployees(sEmployee employee1, sEmployee employee2);

/** \brief Funcion que intercambia dos Empleados por ID unicos.
 * 
 * \param employee1 sEmployee Tipo de Dato de Empleado.
 * \param employee2 sEmployee Tipo de Dato de Empleado.
 * \return int
 *      [0] Si el intercambio fue realizado y verificado con exito.
 *      [-1] Si hubo un error al hacer el intercambio.
 * 
 */
int swapEmployees(sEmployee* employee1, sEmployee* employee2);

/** \brief Funcion que obtiene el primer indice vacio de un arreglo de Empleados.
 * 
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si no hay ninguna posicion libre del arreglo.
 *      Indice del arreglo donde se encuentra un lugar vacio.
 * 
 */
int getEmptyIndexOfEmployees(sEmployee list[], int length);

/** \brief Funcion que obtiene el indice del array de Empleados
 *          del ID ingresado como parametro.
 * 
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \param id int Campo ID del Empleado a buscar.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Encuentra el indice del Empleado buscado.
 * 
 */
int findEmployeeById(sEmployee list[], int length, int id);

/** \brief Funcion que obtiene el indice del array de Sectores
 *          del ID ingresado como parametro.
 * 
 * \param list[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array.
 * \param id int Campo ID del Empleado a buscar.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Encuentra el indice del Empleado buscado.
 * 
 */
int findSectorById(sSector list[], int length, int id);

/** \brief Busca el nombre del Sector por el ID.
 *
 * \param sectorName char* Nombre encontrado del Sector.
 * \param list[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array.
 * \param idSector int ID del Sector a buscar.
 * \return int
 *      [-1] Si no existe el ID.
 *      [0] Si el Sector fue encontrado con exito.
 *
 */
int findSectorNameById(char* sectorName, sSector list[], int length, int idSector);

/** \brief Funcion para obtener un Empleado consultando
 *      al usuario por pantalla.
 * 
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array de Empleados.
 * \param listSectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param lengthSectors int Longitud del array de Sectores.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Devuelve el ID del Empleado seleccionado.
 * 
 */
int selectEmployee(char message[], char eMessage[], sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors);

/** \brief Funcion para obtener un Sector consultando
 *      al usuario por pantalla.
 * 
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param listSectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param lengthSectors int Longitud del array de Sectores.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Devuelve el ID del Sector seleccionado.
 * 
 */
int selectSector(char message[], char eMessage[], sSector listSectors[], int lengthSectors);

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

/** \brief Borra un Empleado de una lista mediante su ID
 *      informando el campo isEmpty como vacio.
 *
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array de Empleados.
 * \param listSectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param lengthSectors int Longitud del array de Sectores.
 * \param id int Campo ID del Empleado a borrar.
 * \return int
 *      [-1] Si hubo un error para borrar el Empleado de la lista.
 *      [0] Si el borrado del Empleado de la lista fue exitosa.
 *
 */
int removeEmployee(sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors, int id);

/** \brief Funcion que ordena a los Empleados de la lista
 *      por apellido y sector de forma Ascendente o Descendente.
 *
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array de Empleados.
 * \param listSectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param lengthSectors int Longitud del array de Sectores.
 * \param order int [ASC] Orden Ascendente - [DESC] orden Descendente.
 * \return int
 *      [-1] Si hubo un error para ordenar los Empleados de la lista.
 *      [0] Si el ordenado de los Empleados de la lista fue exitosa.
 *
 */
int sortEmployees(sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors, int order);

/** \brief Funcion que calcula la cantidad de Empleados dados de alta.
 * 
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param lengthEmployees int Longitud del array de Empleados.
 * \return int Cantidad de Empleados dados de alta.
 * 
 */
int currentEmployeeCounter(sEmployee listEmployees[], int lengthEmployees);

/** \brief Funcion que calcula el total de los salarios de los Empleados.
 * 
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param lengthEmployees int Longitud del array de Empleados.
 * \return float Total de los salarios de los Empleados.
 * 
 */
float sumEmployeeSalaries(sEmployee listEmployees[], int lengthEmployees);

/** \brief Funcion que obtiene una lista filtrada de Empleados con sueldos que superen el promedio.
 * 
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param filteredEmployeeList[] sEmployee Direccion de memoria del inicio del array de Empleados a filtrar.
 * \param lengthEmployees int Longitud del array de Empleados.
 * \return int Cantidad de Empleados que superan el promedio.
 * 
 */
int employeesFilterAboveValue(sEmployee listEmployees[], sEmployee filteredEmployeeList[], int lengthEmployees, float value);

/** \brief Funcion que imprime un Empleado formateado para impresion
 *      con encabezado de tabla.
 *
 * \param employee sEmployee Tipo de Dato de Empleado.
 * \param list[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si hubo un error para imprimir al Empleado.
 *      [0] Si el Empleado fue impreso con exito.
 *
 */
int printEmployee(sEmployee employee, sSector list[], int length);

/** \brief Funcion que imprime un Sector formateado para impresion
 *      con encabezado de tabla.
 *
 * \param sector sSector Tipo de Dato de Sector.
 * \return void No retorna valores.
 *
 */
void printSector(sSector sector);

/** \brief Imprime en pantalla el contenido de la lista de Empleados.
 *
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param lengthEmployees int Longitud del array de Empleados.
 * \param listSectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param lengthSectors int Longitud del array de Sectores.
 * \return int La cantidad de elementos impresos del array.
 *
 */
int printEmployees(sEmployee listEmployees[], int lengthEmployees, sSector listSectors[], int lengthSectors);

/** \brief Imprime en pantalla el contenido de un arreglo de Sectores.
 *
 * \param sectors[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array de Sectores.
 * \return int La cantidad de elementos impresos del array.
 *
 */
int printSectors(sSector sectors[], int length);

/** \brief Funcion que imprime el total y el promedio de salarios de los Empleados.
 * 
 * \param listEmployees[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param lengthEmployees int Longitud del array de Empleados.
 * \return void No retorna valores.
 * 
 */
void printTotalsAndAverageSalaries(sEmployee listEmployees[], int lengthEmployees);

/** \brief Funcion que carga valores de muestra a un vector de Sectores
 *      dependiendo de la cantidad definida como parametro.
 *
 * \param list[] sSector Direccion de memoria del inicio del array de Sectores.
 * \param length int Longitud del array.
 * \param quantity unt Cantidad de valores a cargar en el arreglo.
 * \return void No retorna valores.
 *
 */
void sector_hardcode(sSector list[], int length, int quantity);

/** \brief Funcion que carga valores de muestra a un vector de Empleados
 *      dependiendo de la cantidad definida como parametro.
 *
 * \param list[] sEmployee Direccion de memoria del inicio del array de Empleados.
 * \param length int Longitud del array.
 * \param quantity unt Cantidad de valores a cargar en el arreglo.
 * \return void No retorna valores.
 *
 */
void employee_hardocde(sEmployee list[], int length, int quantity);

#endif // ARRAYEMPLOYEES_H_INCLUDED
