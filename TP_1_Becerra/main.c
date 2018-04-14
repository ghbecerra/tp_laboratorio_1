#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion;
    float operando1;
    float operando2;
    int flag1=0;
    int flag2=0;
    float resultado;

    while(seguir=='s')
    {
        printf("\n     MENU DE LA CALCULADORA     \n");
        if(flag1==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }else{
            printf("1- Ingresar 1er operando (A=%.2f)\n",operando1);
            }
        if(flag2==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }else{
            printf("2- Ingresar 2do operando (B=%.2f)\n",operando2);
            }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("\nOpcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("\nIngresar 1er operando: ");
                fflush(stdin);
                scanf("%f",&operando1);
                system("cls");
                flag1=1;
                break;
            case 2:
                printf("\nIngresar 2do operando: ");
                fflush(stdin);
                scanf("%f",&operando2);
                system("cls");
                flag2=1;
                break;
            case 3:
                system("cls");
                if(flag1==1 && flag2==1)
                {
                    resultado=suma(operando1,operando2);
                    printf("La suma de los operandos (A+B) es: %.2f\n",resultado);
                }else{
                    printf("Por favor ingrese los operandos.\n");
                    }
                break;
            case 4:
                system("cls");
                if(flag1==1 && flag2==1)
                {
                    resultado=resta(operando1,operando2);
                    printf("La resta de los operandos (A-B) es: %.2f\n",resultado);
                }else{
                    printf("Por favor ingrese los operandos.\n");
                    }
                break;
            case 5:
                system("cls");
                if(flag1==1 && flag2==1)
                {
                    if(operando2!=0)
                    {
                        resultado=division(operando1,operando2);
                        printf("La division de los operandos (A/B) es: %f\n",resultado);
                    }else if(operando1==0&&operando2==0){
                        printf("Resultado indefinido.\n");
                        }else{
                            printf("ERROR: No se puede dividir entre cero.\n");
                            }
                }else{
                    printf("Por favor ingrese los operandos.\n");
                    }
                break;
            case 6:
                system("cls");
                if(flag1==1 && flag2==1)
                {
                    resultado=multiplicacion(operando1,operando2);
                    printf("La multiplicacion de los operandos (A*B) es: %.2f\n",resultado+0);
                }else{
                    printf("Por favor ingrese los operandos.\n");
                    }
                break;
            case 7:
                system("cls");
                if(flag1==1)
                {
                    if(operando1<0)
                    {
                    printf("Entrada no valida.\n");
                    }else{
                        resultado=factorial(operando1);
                        printf("El factorial (A!): %.2f\n",resultado);
                        }
                }else{
                    printf("Por favor ingrese el 1er operando.\n");
                    }

                break;
            case 8:
                system("cls");
                if(flag1==1 && flag2==1)
                {
                    resultado=suma(operando1,operando2);
                    printf("La suma de los operandos (A+B) es: %.2f\n",resultado);
                    resultado=resta(operando1,operando2);
                    printf("La resta de los operandos (A-B) es: %.2f\n",resultado);
                    if(operando2!=0)
                    {
                        resultado=division(operando1,operando2);
                        printf("La division de los operandos (A/B) es: %f\n",resultado);
                    }else if(operando1==0&&operando2==0){
                        printf("La division de los operandos (A/B) es: Resultado indefinido.\n");
                        }else{
                            printf("La division de los operandos (A/B) es: ERROR! No se puede dividir entre cero.\n");
                            }
                    resultado=multiplicacion(operando1,operando2);
                    printf("La multiplicacion de los operandos (A*B) es: %.2f\n",resultado+0);
                    if(operando1<0)
                    {
                        printf("El factorial (A!): Entrada no valida.\n");
                    }else{
                        resultado=factorial(operando1);
                        printf("El factorial (A!): %.2f\n",resultado);
                        }
                }else{
                    printf("Falta ingresar uno o ambos operandos.\n");
                    }
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}
