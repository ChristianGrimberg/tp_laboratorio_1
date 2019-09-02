#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include "input.h"

/** \brief Funcion que calcula la suma de 2 operandos
 *      y devuelve el resultado
 * 
 * \param operand1 float Primer operando
 * \param operand2 float Segundo operando
 * \param result float* Variable donde se carga el resultado
 * \return int
 *      Retorna [0] si la operacion fue exitosa
 *      Retorna [1] si los valores ingresados esta fuera de limite
 *      Retorna [-1] si el resultado es overflow
 *
 */
int addOperands(float operand1, float operand2, float* result);

/** \brief Funcion que calcula la resta de 2 operandos
 *      y devuelve el resultado
 * 
 * \param operand1 float Primer operando
 * \param operand2 float Segundo operando
 * \param result float* Variable donde se carga el resultado
 * \return int
 *      Retorna [0] si la operacion fue exitosa
 *      Retorna [1] si los valores ingresados esta fuera de limite
 *      Retorna [-1] si el resultado es overflow
 *
 */
int subtractOperands(float operand1, float operand2, float* result);

/** \brief Funcion que calcula la multiplicacion de 2 operandos
 *      y devuelve el resultado
 * 
 * \param operand1 float Primer operando
 * \param operand2 float Segundo operando
 * \param result float* Variable donde se carga el resultado
 * \return int
 *      Retorna [0] si la operacion fue exitosa
 *      Retorna [1] si los valores ingresados esta fuera de limite
 *      Retorna [-1] si el resultado es overflow
 *
 */
int multiplyOperands(float operand1, float operand2, float* result);

/** \brief Funcion que calcula la division de 2 operandos
 *      y devuelve el resultado
 * 
 * \param operand1 float Primer operando
 * \param operand2 float Segundo operando
 * \param result float* Variable donde se carga el resultado
 * \return int
 *      Retorna [0] si la operacion fue exitosa
 *      Retorna [1] si los valores ingresados esta fuera de limite
 *      Retorna [-1] si el resultado es overflow
 *      Retorna [-2] si no se puede dividir por cero
 *
 */
int divideOperands(float operand1, float operand2, float* result);

#endif // CALCULATOR_H_INCLUDED