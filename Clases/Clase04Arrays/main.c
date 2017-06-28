#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD_EDADES 100

int main()
{
    int edad[CANTIDAD_EDADES];
    int i;
    char seguir = 'n';
    float promedio;

    do
    {
        for(i=0; i<CANTIDAD_EDADES; i++)
        {
            printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d",&edad[i]);

            printf("\nDesea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);

            if(seguir != 's')
                break;
        }
        system("cls");
    }while(seguir == 's');

    promedio = prom(edad,i+1);

    /*for(i=0;i<edad[i];i++)
    {

    }*/
    printf("El promedio es: %.2f\n",promedio);
    return 0;
}
