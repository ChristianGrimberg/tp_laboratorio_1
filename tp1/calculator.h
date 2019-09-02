#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <stdio.h>
#include "input.h"

/** \brief Funcion que calcula la suma de 2 operandos
 *      y devuelve el resultado
 * 
 * \param operand1 float
 * \param operand2 float
 * \param result float*
 * \return int
 *      Retorna [0] si la operacion fue exitosa
 *      Retorna [1] si los valores ingresados esta fuera de limite
 *      Retorna [-1] si el resultado es overflow
 *
 */
int addOperands(float operand1, float operand2, float* result);

#endif // CALCULATOR_H_INCLUDED