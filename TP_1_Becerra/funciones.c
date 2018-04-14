#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma (float operando1, float operando2)
{
    float sumaRetorno;
    sumaRetorno=operando1+operando2;
    return sumaRetorno;
}

float resta (float operando1, float operando2)
{
    float restaRetorno;
    restaRetorno=operando1-operando2;
    return restaRetorno;
}

float division (float operando1, float operando2)
{
    float divisionRetorno;
    divisionRetorno=operando1/operando2;
    return divisionRetorno;
}

float multiplicacion (float operando1, float operando2)
{
    float multiplicacionRetorno;
    multiplicacionRetorno=operando1*operando2;
    return multiplicacionRetorno;
}

float factorial(float operando1)
{
    int factorialRetorno;
    if(operando1==0)
    {
        factorialRetorno=1;
    }else{
        factorialRetorno=operando1*factorial(operando1-1);
        }
    return factorialRetorno;
}
