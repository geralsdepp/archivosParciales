#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define MAXINPUT 100

int main()
{
    char buffer[MAXINPUT];
    int lenght;
    printf("Ingrese nombre, edad, direccion o telefono: ");
    gets(buffer);

    lenght = strlen(buffer);

    if(lenght > 0)
    {
        if(soloNumeros(buffer))
        {
            printf("Es numerico\n");
        }
        if(soloLetras(buffer))
        {
            printf("Son letras\n");
        }
        if(alfanumerico(buffer))
        {
            printf("Es alfanumerico\n");
        }
        if(esTelefono(buffer))
        {
            printf("Es telefono\n");
        }
    }
    return 0;
}
