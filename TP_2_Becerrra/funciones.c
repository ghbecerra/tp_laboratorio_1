#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 1
#define OCUPADO 0

int imprimirMenu(void)
{
    int retorno=0;
    do
    {
        system("cls");
        printf("MENU\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");
        printf("Opcion: ");
        fflush(stdin);
        scanf("%d", &retorno);
    }while(retorno<1 || retorno>5);
    return retorno;
}

void ePersona_init(ePersona listado[],int limite)
{
    int i;
    if(limite>0 && listado!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            listado[i].estado=LIBRE;
        }
    }
}

void ePersona_alta(ePersona listado[],int limite)
{
    int indice;
    if(limite>0 && listado!=NULL)
    {
        indice=ePersona_buscarLugarLibre(listado,limite);
        if(indice>=0)
        {
            system("cls");
            printf("ALTA DE PERSONA\n");
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(listado[indice].nombre);
            printf("Ingrese edad: ");
            scanf("%d", &listado[indice].edad);
            printf("Ingrese dni: ");
            scanf("%d", &listado[indice].dni);
            listado[indice].estado=OCUPADO;
        }else{
            system("cls");
            printf("No hay espacio libre para cargar personas.\n\n");
            system("pause");
        }
    }
}

int ePersona_buscarLugarLibre(ePersona listado[],int limite)
{
    int retorno;
    int i;
    if(limite>0 && listado!=NULL)
    {
        retorno=-2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado==LIBRE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

void ePersona_mostrarListado(ePersona listado[],int limite)
{
    int i;
    if(limite>0 && listado!=NULL)
    {
        system("cls");
        printf("PERSONAS:\n");
        printf("Nombre\tEdad\tDNI\n");
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                printf("%s", listado[i].nombre);
                printf(" ");
                printf("\t%d", listado[i].edad);
                printf(" ");
                printf("\t%d\n", listado[i].dni);
            }
        }
        system("pause");
    }
}

void ePersona_ordenar(ePersona listado[],int limite)
{
    char auxNombre[50];
    int auxEdad;
    int auxDni;
    int i;
    int j;
    for(i=0;i<limite-1;i++)
    {
        for(j=i+1;j<limite;j++)
        {
            if(listado[i].estado==OCUPADO && listado[j].estado==OCUPADO)
            {
                if(strcmp(listado[i].nombre,listado[j].nombre)>0)
                {
                    strcpy(auxNombre,listado[i].nombre);
                    strcpy(listado[i].nombre,listado[j].nombre);
                    strcpy(listado[j].nombre,auxNombre);
                    auxEdad=listado[i].edad;
                    listado[i].edad=listado[j].edad;
                    listado[j].edad=auxEdad;
                    auxDni=listado[i].dni;
                    listado[i].dni=listado[j].dni;
                    listado[j].dni=auxDni;
                }
            }
        }
    }
}

void ePersona_borrar(ePersona listado[],int limite)
{
    int dni;
    int i;
    int flag=0;
    char resp;
    printf("\nIngrese DNI de la persona a borrar: ");
    scanf("%d",&dni);
    for(i=0;i<limite;i++)
    {
        if(listado[i].dni==dni)
        {
            flag=-1;
            printf("\nDesea dar de baja a %s dni:%d ?", listado[i].nombre, listado[i].dni);
            printf("\nIngrese 's' para confirmar, cualquier otra tecla para cancelar: ");
            fflush(stdin);
            scanf("%c",&resp);
            if(resp=='s')
            {
                listado[i].estado=LIBRE;
                printf("\nBaja exitosa.\n");
                system("pause");
                system("break");
            }else{
                printf("\nBaja cancelada por el usuario.\n");
                system("pause");
            }
        }
    }
    if(i==limite && flag==0)
        {
            printf("\nNo existe la persona ingresada\n");
            system("pause");
        }
}

void ePersona_GraficoEdades(ePersona listado[],int limite)
{
    int i;
    int menor=0;
    int medio=0;
    int mayor=0;
    for(i=0;i<limite;i++)
    {
        if(listado[i].estado!=LIBRE)
        {
            if(listado[i].edad<=18)
            {
                menor++;
            }else if(listado[i].edad>18 && listado[i].edad<35){
                medio++;
            }else{
                mayor++;
            }
        }
    }
    if(menor!=0 || medio!=0 || mayor!=0)
    {
        system("cls");
        printf(" Grafico de edades: \n\n");
        for(i=limite;i>=0;i--)
        {
            if((menor-i)>0)
            {
                printf(" *  |");
            }else{
                printf("    |");
            }
            if((medio-i)>0)
            {
                printf("   *   |");
            }else{
                printf("       |");
            }
            if((mayor-i)>0)
            {
                printf("  *");
            }
            printf("\n");
        }
        printf("<18   19-35   >35\n");
        system("pause");
    }else{
        system("cls");
        printf("Grafico edades: \n");
        printf("Aun no hay personas cargadas.\n");
        system("pause");
    }
}
