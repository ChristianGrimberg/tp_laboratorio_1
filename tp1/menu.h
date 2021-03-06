#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "calculator.h"

#define OPTION_MIN 1
#define OPTION_MAX 8
#define OPTION_ERROR -1

/** \brief Funcion que interrumpe la ejecucion del programa
 *      hasta que se presiona la tecla Enter
 *
 * \param void No requiere parametros
 * \return void No retorna valores
 *
 */
void menu_pauseScreen(void);

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario ingrese la opcion elegida
 *
 * \param option int* Opcion elegida del menu
 * \param x double Valor del primer operando
 * \param y double Valor del segundo operando
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_main(int* option, double x, double y);

/** \brief Funcion que imprime un numero
 *      en pantalla segun su tipo
 *
 * \param message[] char Mensaje a imprimir antes del numero
 * \param number float Numero con o sin decimales a imprimir
 * \return void No retorna valores
 *
 */
void menu_printNumberByType(char message[], float number);

#endif // MENU_H_INCLUDED
