#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define OPTION_MIN 1
#define OPTION_MAX 9

/** \brief Funcion que interrumpe la ejecucion del programa
 * hasta que se presiona la tecla Enter
 *
 * \param void No requiere parametros
 * \return void No retorna valores
 *
 */
void menu_pauseScreen(void);

/** \brief Funcion que imprime un menu en pantalla
 * para que el usuario ingrese la opcion elegida
 *
 * \param x double Valor del primer operando
 * \param y double Valor del segundo operando
 * \return int Retorna la opcion elegida en el menu
 *
 */
int menu_main(double x, double y);

#endif // MENU_H_INCLUDED
