#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int soloNumeros(char str[])
{
    int i=0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if(str[i]<'0' || str[i]>'9')
            retorno = 0;
        i++;
    }
     return retorno;
}
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if((str[i]!= ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            retorno = 0;
        i++;
    }

    return retorno;
}
int alfanumerico(char str[])
{
    int i=0;
    int retorno = 1;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            retorno = 0;
        i++;
    }
    return retorno;
}
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    int retorno;

    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < '0' || str[i] > '9') && (str[i] != '-'))
            retorno = 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones == 1)
    {
        retorno = 1;
    }//VALIDO QUE EL TELEFRONO DEBE CONTENER UN SOLO GUION
    return retorno;
}
