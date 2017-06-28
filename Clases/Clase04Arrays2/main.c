#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT_EDAD 100

int main()
{
    int opcion;
    char seguir = 's';
    int edad[CANT_EDAD];
    int menor,mayor,promedio;
    int indice;

    do
    {
        opcion = menuOpcion();
        system("cls");
        switch(opcion)
        {
        case 1:
            indice = cargar_edad(edad,CANT_EDAD);
            break;
        case 2:
            menor = minimo(edad,indice+1);
            printf("El minimo es: %d\n",menor);
            break;
        case 3:
            mayor = maximo(edad,indice+1);
            printf("El maximo es: %d\n",mayor);
            break;
        case 4:
            promedio = prom(edad,indice+1);
            printf("El promedio es: %d\n",promedio);
        case 5:
            seguir = 'n';
            break;
        }
    }while(seguir == 's');
    return 0;
}
