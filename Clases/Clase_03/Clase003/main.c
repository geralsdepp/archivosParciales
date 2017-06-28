#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    int edad;
    float peso;
    char letra;

    edad = obtenerInt("Ingrese edad: ","Debe ingresar una edad valida.\nDesea continuar? s/n: ",100,0);
    printf("La edad es: %d\n",edad);
    peso = obtenerFloat("Ingrese su peso: ","Debe ingresar un peso valido.\nDesea continuar? s/n: ",100,0);
    printf("El peso es: %f\n",peso);
    letra = obtenerChar("Ingrese la primer letra de su nombre: ","Debe ingresar una letra.\nDesea continuar? s/n: ",'Z','A');
    printf("La letra es: %c\n",letra);
    return 0;
}
