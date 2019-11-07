#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "inputs.h"

#define MENU_MAIN_MAX 10 /**< Opcion maxima del menu principal. >*/
#define MENU_SORT_MAX 5 /**< Opcion maxima del menu de ordenamiento. >*/
#define MENU_EDIT_MAX 4 /**< Opcion maxima del menu de edicion. >*/

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

/** \brief Funcion que imprime el menu de edicion
 *      para un Empleado en un arreglo de LinkedList.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_edit(int* option);

#endif // MENU_H_INCLUDED
