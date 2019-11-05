#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "inputs.h"

#define MENU_MAIN_MAX 10 /**< Opcion maxima del menu principal. >*/
#define MENU_SORT_MAX 5 /**< Opcion maxima del menu de ordenamiento. >*/

/** \brief Funcion que imprime el menu principal del programa.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime el menu de ordenamiento del arreglo.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_sort(int* option);

#endif // MENU_H_INCLUDED
