#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "inputs.h"

#define OPTION_MIN 1 /**< Opcion minima en comun de cada menu. >*/
#define MAIN_MAX 5 /**< Opcion maxima del menu principal. >*/
#define UPDATE_MAX 5 /**< Opcion maxima de menu para modificar un Empleado. >*/
#define REPORT_MAX 5 /**< Opcion maxima de menu para mostrar informes de Empleados. */
#define OPTION_ERROR -1 /**< Opcion de retorno de error de cada menu. >*/

/**< Mensaje en pantalla para presionar la tecla Enter y continuar. >*/
#define CONTINUE_MESSAGE "Presione la tecla Enter para continuar..."
/**< Mensaje en pantalla para presionar la tecla Enter y salir del programa. >*/
#define EXIT_MESSAGE "Presione la tecla Enter para salir del programa..."

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario ingrese la opcion elegida.
 *
 * \param option int* Opcion elegida del menu.
 * \return int Retorna la opcion elegida en el menu.
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario modifique la carga de un Empleado.
 *
 * \param option int* Opcion elegida del menu.
 * \return int Retorna la opcion elegida en el menu.
 *
 */
int menu_update(int* option);

/** \brief Funcion que imprime un menu en pantalla
 *      para seleccionar el informe de Empleados a imprimir.
 *
 * \param option int* Opcion elegida del menu.
 * \return int Retorna la opcion elegida en el menu.
 *
 */
int menu_printReports(int* option);

#endif // MENU_H_INCLUDED
