#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "input.h"

#define MAIN_MIN 1
#define MAIN_MAX 5
#define OPTION_ERROR -1

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario ingrese la opcion elegida
 *
 * \param option int* Opcion elegida del menu
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_main(int* option);

#endif // MENU_H_INCLUDED