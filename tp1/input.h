#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define STRING_AS_NUMBER_MAX 64 /**< Buffer de entrada maximo para cadenas numericas */

/** \brief Funcion que limpia el buffer de entrada
 *
 * \param void No requiere parametros
 * \return void No retorna valores
 *
 */
void input_clearBuffer(void);

/** \brief Solicita un numero al usuario y lo valida
 *
 * \param input* int Se carga el numero ingresado
 * \param message[] char Es el mensaje a ser mostrado
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error
 * \param lowLimit int Limite inferior a validar
 * \param hiLimit int Limite superior a validar
 * \return int Si obtuvo el numero [0] si no [-1]
 *
 */
int input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief Solicita un numero flotante al usuario y lo valida
 * 
 * \param input* float Se carga el numero flotante ingresado
 * \param message[] char Es el mensaje a ser mostrado
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error
 * \param lowLimit float Limite inferior a validar
 * \param hiLimit float Limite superior a validar
 * \return int Si obtuvo el numero [0] si no [-1]
 *
 */
int input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit);

#endif // INPUT_H_INCLUDED
