#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 100

int main()
{
    int i=5;
    int edad[MAX] = {22,11,33,55,66};
    int aux[MAX];
    char respuesta;
    int buffer;
    int menor;
    int sizeEdad = 5;

    ordenar(edad,5);
    for(i=0; i<5-1;i++)
    {
        printf("La edad es: %d\n",edad[i]);
    }

    menor = minimo(edad,sizeEdad);
    printf("El indice 1 es: %d\nEl indice 2 es: %d\nEl indice 3 es: %d\nEl indice 4 es: %d\nEl indice 5 es: %d\n",edad[0],edad[1],edad[2],edad[3],edad[4]);
    sizeEdad = sort_new(aux,5,edad[i]);

    printf("Aplicando la funcion compactar queda: %d",sizeEdad);

    return 0;
}

    /*for(i=0; i<MAX;i++)
    {
        printf("\nIngrese la edad de la persona %d: ", i);
        scanf("%d", &edad[i]);

        printf("\n\nDesea seguir ingresando? [s/n]");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta!='s'&&respuesta!='S')
        {
            break;
        }
        system("cls");
    }*/

    //printf("\nEl promedio de las edades ingresadas es %.2f", promedio(edad, i+1));
