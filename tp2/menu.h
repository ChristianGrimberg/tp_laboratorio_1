#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "input.h"

#define OPTION_MIN 1 /**< Opcion minima en comun de cada menu >*/
#define MAIN_MAX 5 /**< Opcion maxima del menu principal >*/
#define CREATE_MAX 5 /**< Opcion maxima de menu de creacion de Empleado >*/
#define OPTION_ERROR -1 /**< Opcion de retorno de error de cada menu >*/

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario ingrese la opcion elegida
 *
 * \param option int* Opcion elegida del menu
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario ingrese el alta de un Empleado
 *
 * \param option int* Opcion elegida del menu
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_create(int* option);

#endif // MENU_H_INCLUDED