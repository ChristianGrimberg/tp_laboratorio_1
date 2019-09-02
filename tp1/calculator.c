#include "calculator.h"

int calculator_addOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult = 0;

    if((operand1 > -FLT_MAX && operand1 <= FLT_MAX)
        && (operand2 > -FLT_MAX && operand2 <= FLT_MAX))
    {
        auxResult = operand1 + operand2;
        
        if((operand1 > 0 && operand2 > 0 && auxResult < 0)
            || (operand1 < 0 && operand2 < 0 && auxResult > 0))
        {
            returnValue = -1;
        }
        else
        {
            *result = auxResult;
            returnValue = 0;
        }
    }

    return returnValue;
}

int calculator_subtractOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult = 0;

    if((operand1 > -FLT_MAX && operand1 <= FLT_MAX)
        && (operand2 > -FLT_MAX && operand2 <= FLT_MAX))
    {
        auxResult = operand1 - operand2;
        
        if((operand1 > operand2 && auxResult < 0)
            || (operand1 < operand2 && auxResult > 0))
        {
            returnValue = -1;
        }
        else
        {
            *result = auxResult;
            returnValue = 0;
        }
    }

    return returnValue;
}

int calculator_multiplyOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult = 0;

    if((operand1 > -FLT_MAX && operand1 <= FLT_MAX)
        && (operand2 > -FLT_MAX && operand2 <= FLT_MAX))
    {
        auxResult = operand1 * operand2;

        if((operand1 > 0 && operand2 > 0 && auxResult < 0)
            || (operand1 < 0 && operand2 < 0 && auxResult < 0)
            || (operand1 > 0 && operand2 < 0 && auxResult > 0)
            || (operand1 < 0 && operand2 > 0 && auxResult > 0))
        {
            returnValue = -1;
        }
        else
        {
            *result = auxResult;
            returnValue = 0;
        }
    }

    return returnValue;
}

int calculator_divideOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult = 0;

    if((operand1 > -FLT_MAX && operand1 <= FLT_MAX)
        && (operand2 > -FLT_MAX && operand2 <= FLT_MAX))
    {
        if(operand2 == 0)
        {
            returnValue = -2;
        }
        else
        {
            auxResult = operand1 / operand2;

            if((operand1 > 0 && operand2 > 0 && auxResult < 0)
                || (operand1 < 0 && operand2 < 0 && auxResult < 0)
                || (operand1 > 0 && operand2 < 0 && auxResult > 0)
                || (operand1 < 0 && operand2 > 0 && auxResult > 0))
            {
                returnValue = -1;
            }
            else
            {
                *result = auxResult;
                returnValue = 0;
            }
        }
    }

    return returnValue;
}

int calculator_factorialOperand(float operand, float* result)
{
    int returnValue = 1;
    int i;
    
    float auxResult = 0;
    
    *result = 0;

    if(input_getNumberType(operand) == 1)
    {
        if(operand > 0 && operand < INTERGER_FACTORIAL_MAX)
        {
            auxResult = 1;

            for(i = 1; i <= operand; i++)
            {
                auxResult = auxResult * i;
            }

            *result = auxResult;
            returnValue = 0;
        }
        else
        {
            if(operand == 0)
            {
                *result = 1;
                returnValue = 0;
            }
        }
    }

    return returnValue;
}
