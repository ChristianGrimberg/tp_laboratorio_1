#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#define STRING_AS_NUMBER_MAX 64 /**< Buffer de entrada maximo para cadenas numericas */
#define EXIT_BUFFER '\0' /**< Valor de terminacion de cadena de caracteres. */

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

/** \brief Solicita un numero flotante al usuario e indica su tipo
 * 
 * \param number float Numero con o sin decimales a evaluar
 * \return int
 *      Si devuelve [0] no puede reconocer el tipo
 *      Si devuelve [1] el numero es de tipo entero
 *      Si devuelve [2] el numero es de tipo flotante
 *
 */
int input_getNumberType(float number);

#endif // INPUT_H_INCLUDED
