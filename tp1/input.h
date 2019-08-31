#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#define STRING_AS_INT32_MAX 10

/** \brief Funcion que limpia el buffer de entrada
 *
 * \param void No requiere parametros
 * \return void No retorna valores
 *
 */
void input_clearBuffer(void);

/** \brief
 *
 * \param minNumber int
 * \param maxNumber int
 * \return int
 *
 */
int getIntOfARange(int minNumber, int maxNumber);

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
int input_getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

#endif // INPUT_H_INCLUDED
