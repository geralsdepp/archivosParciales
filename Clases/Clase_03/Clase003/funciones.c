#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <ctype.h>

int obtenerInt(char mensaje[],char mensajeError[],int maximo,int minimo)
{
    int buffer;
    char seguir = 's';

    do
    {
        printf(mensaje);
        scanf("%d",&buffer);
        if(buffer <= minimo || buffer >= maximo)
        {
             printf(mensajeError);
             fflush(stdin);
             scanf("%c",&seguir);
        }
        else
           seguir = 'n';

    }while(seguir == 's');

    return buffer;
}

float obtenerFloat(char mensaje[],char mensajeError[],float maximo, float minimo)
{
    float buffer;
    char seguir = 's';

    do
    {
        printf(mensaje);
        scanf("%f",&buffer);
        if(buffer <= minimo || buffer >= maximo)
        {
             printf(mensajeError);
             fflush(stdin);
             scanf("%c",&seguir);
        }
        else
           seguir = 'n';

    }while(seguir == 's');

    return buffer;
}
char obtenerChar(char mensaje[],char mensajeError[],char maximo,char minimo)
{
    char buffer;
    char seguir = 's';

    do
    {
        printf(mensaje);
        fflush(stdin);
        scanf("%c",&buffer);
        buffer = toupper(buffer);
        if(buffer <= minimo || buffer >= maximo)
        {
             printf(mensajeError);
             fflush(stdin);
             scanf("%c",&seguir);
        }
        else
           seguir = 'n';

    }while(seguir == 's');

    return buffer;
}
