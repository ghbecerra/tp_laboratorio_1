#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TPERSONA 20

int main()
{
    char seguir='s';
    int opcion=0;
    ePersona listadoPersonas[TPERSONA];
    ePersona_init(listadoPersonas,TPERSONA);
    while(seguir=='s')
    {
        opcion=imprimirMenu();
        switch(opcion)
        {
            case 1:
                ePersona_alta(listadoPersonas,TPERSONA);
                break;
            case 2:
                ePersona_mostrarListado(listadoPersonas,TPERSONA);
                ePersona_borrar(listadoPersonas,TPERSONA);
                break;
            case 3:
                ePersona_ordenar(listadoPersonas,TPERSONA);
                ePersona_mostrarListado(listadoPersonas,TPERSONA);
                break;
            case 4:
                ePersona_GraficoEdades(listadoPersonas,TPERSONA);
                break;
            case 5:
                seguir='n';
                break;
        }
    }
    return 0;
}
