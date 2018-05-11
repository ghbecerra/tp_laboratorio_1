#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
}ePersona;

int imprimirMenu(void);
void ePersona_init(ePersona listado[],int limite);
void ePersona_alta(ePersona listado[],int limite);
int ePersona_buscarLugarLibre(ePersona listado[],int limite);
void ePersona_mostrarListado(ePersona listado[],int limite);
void ePersona_ordenar(ePersona listado[],int limite);
void ePersona_borrar(ePersona listado[],int limite);
void ePersona_GraficoEdades(ePersona listado[],int limite);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
//int obtenerEspacioLibre(ePersona listado[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
//int buscarPorDni(ePersona listado[], int dni);

#endif // FUNCIONES_H_INCLUDED
