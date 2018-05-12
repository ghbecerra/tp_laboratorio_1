#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
}ePersona;

/**
 * Mostrar en pantalla menu de opciones.
 * @param lista el array se pasa como parametro.
 * @return opcion elegida por el usuario
 */
int imprimirMenu(void);

/**
 * Inicializar estados.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima de array.
 */
void ePersona_init(ePersona listado[],int limite);

/**
 * Registrar datos en array.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima de array.
 */
void ePersona_alta(ePersona listado[],int limite);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima de array.
 * @return el primer indice disponible
 */
int ePersona_buscarLugarLibre(ePersona listado[],int limite);

/**
 * Imprimir en pantalla registro de individuos.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima del array.
 */
void ePersona_mostrarListado(ePersona listado[],int limite);

/**
 * Ordenar array de datos.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima del array.
 */
void ePersona_ordenar(ePersona listado[],int limite);

/**
 * Borrar individuo del array de datos.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima del array.
 */
void ePersona_borrar(ePersona listado[],int limite);

/**
 * Imprimir en pantalla grafico con edades de individuos cargados en array.
 * @param lista el array se pasa como parametro.
 * @param capacidad maxima del array.
 */
void ePersona_GraficoEdades(ePersona listado[],int limite);

#endif // FUNCIONES_H_INCLUDED
