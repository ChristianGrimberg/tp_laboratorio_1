#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

#include <math.h>
#include <limits.h>
#include "arrays.h"

#define ENTER_CHARACTER '\n' /**< Caracter de tecla enter por teclado. >*/
#define YES 'S' /**< Respuesta SI por teclado. >*/
#define NO 'N' /**< Respuesta NO por teclado. >*/
#define ERROR_MESSAGE "Intente nuevamente: " /**< Mensaje de solicitud de error al usuario. >*/
/**< Mensaje en pantalla para presionar la tecla Enter y continuar. >*/
#define CONTINUE_MESSAGE "Presione la tecla Enter para continuar..."
/**< Mensaje en pantalla para presionar la tecla Enter y salir del programa. >*/
#define QUIT_MESSAGE "Presione la tecla Enter para salir del programa..."

/** \brief Funcion que limpia el buffer de entrada a posterior del ingreso por teclado.
 *
 * \param void No requiere parametros.
 * \return void No retorna valores.
 *
 */
void inputs_clearBufferAfter(void);

/** \brief Funcion que limpia la pantalla de la consola en los diferentes SO.
 *
 * \param void No requiere paramteros.
 * \return void No retorna valores.
 *
 */
void inputs_clearScreen(void);

/** \brief Funcion que interrumpe la ejecucion del programa
 *      hasta que se presiona la tecla Enter.
 *
 * \param message[] char Es el mensaje a ser mostrado.
 * \return void No retorna valores.
 *
 */
void inputs_pauseScreen(char message[]);

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero decimal.
 *
 * \param stringValue[] char Direccion de la cadena a evaluar.
 * \return int
 *      Si es un numero decimal retorna [1] si no [0].
 *
 */
int inputs_isNumber(char stringValue[]);

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero flontante.
 *
 * \param stringValue[] char Direccion de la cadena a evaluar.
 * \return int
 *      Si es un numero flotante retorna [1] si no [0].
 *
 */
int inputs_isFloat(char stringValue[]);

/** \brief Funcion ue evalua si una cadena ingresada por teclado
 *  es un numero telefonico. Ejemplo: +54 11 4200-0000.
 *      Acepta simbolos de:
 *          + [Codigo de Pais].
 *          - [Dividir areas].
 *          Espacios [Dividir areas].
 *      No acepta que se repitan simbolos de manera consecutiva.
 *
 * \param stringValue[] char Direccion de la cadena a evaluar.
 * \return int
 *      Si es un numero telefonico retorna [1] si no [0].
 */
int inputs_isPhone(char stringValue[]);

/** \brief Solicita un numero flotante al usuario e indica su tipo.
 *
 * \param number float Numero con o sin decimales a evaluar.
 * \return int
 *      Si devuelve [0] no puede reconocer el tipo.
 *      Si devuelve [1] el numero es de tipo entero.
 *      Si devuelve [2] el numero es de tipo flotante.
 *
 */
int inputs_getNumberType(float number);

/** \brief Solicita un numero al usuario y lo valida.
 *
 * \param input* int Se carga el numero ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Limite inferior a validar.
 * \param hiLimit int Limite superior a validar.
 * \return int
 *      Si obtuvo el numero devuelve [0] si no [-1].
 *
 */
int inputs_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief Solicita un numero flotante al usuario y lo valida.
 *
 * \param input* float Se carga el numero flotante ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit float Limite inferior a validar.
 * \param hiLimit float Limite superior a validar.
 * \return int
 *      Si obtuvo el numero devuelve [0] si no [-1].
 *
 */
int inputs_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit);

/** \brief Solicita un caracter al usuario y lo valida.
 *
 * \param input char* Se carga el caracter ingresado.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit char Limite inferior a validar.
 * \param hiLimit char Limite superior a validar.
 * \return int
 *      Si obtuvo el caracter devuelve [0] si no [-1].
 *
 */
int inputs_getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit);

/** \brief Solicita una cadena de caracteres al usuario y la valida.
 *
 * \param input char* Cadena de Caracteres a modificar.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Longitud minima de la cadena.
 * \param hiLimit int Longitud maxima de la cadena.
 * \return int
 *      Si obtuvo la cadena devuelve [0] si no [-1].
 *
 */
int inputs_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief Solicita la carga de una fecha en pantalla
 *      en formato latinoamericano DD/MM/AAAA.
 *
 * \param date sDate* Puntero para almacenar el tipo de dato de fecha.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param dateMin sDate Fecha minima a cubrir dentro del rango.
 * \param dateMax sDate Fecha maxima a cibir dentro del rango.
 * \return
 *      Si obtuvo una fecha devuelve [0] si no [-1].
 *
 */
int inputs_getDate(sDate* date, char message[], char eMessage[], sDate dateMin, sDate dateMax);

/** \brief Solicita una cadena de caracteres al usuario y lo valida
 *      como numero telefonico (Solo acepta numeros, guinones y el simbolo "+").
 *
 * \param input char* Cadena de Caracteres a modificar.
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param lowLimit int Longitud minima de la cadena.
 * \param hiLimit int Longitud maxima de la cadena.
 * \return int
 *      Si obtuvo la cadena devuelve [0] si no [-1].
 *
 */
int inputs_getPhone(char* input, char message[], char eMessage[], int lowLimit, int hiLimit);

/** \brief Funcion que imprime un numero en pantalla segun su tipo.
 *
 * \param message[] char Mensaje a imprimir antes del numero.
 * \param number float Numero con o sin decimales a imprimir.
 * \return void No retorna valores.
 *
 */
void inputs_printNumberByType(char message[], float number);

/** \brief Funcion que realiza una consulta booleana al usuario
 *      y devuelve la respuesta.
 *
 * \param message[] char Pregunta al usuario.
 * \return int
 *      Si la respuesta es [S] o [Y] devuelve [1]
 *      Si responde [N] devuelve [0].
 *
 */
int inputs_userResponse(char message[]);

#endif // INPUTS_H_INCLUDED
