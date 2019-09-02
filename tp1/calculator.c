#include "calculator.h"

int addOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult;

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

int subtractOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult;

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

int multiplyOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult;

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

int divideOperands(float operand1, float operand2, float* result)
{
    int returnValue = 1;
    float auxResult;

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
