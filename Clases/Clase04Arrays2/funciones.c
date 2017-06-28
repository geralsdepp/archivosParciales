#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n1.Ingresar edad.\n2.Minimo.\n3.Maximo.\n4.Promedio\n5.Salir\nEliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int cargar_edad(int edad[],int cant)
{
    int i;
    char seguir = 's';

    for(i=0;i<cant;i++)
    {
        printf("Ingrese edad: ");
        scanf("%d",&edad[i]);
        printf("Desea continuar ingresando edades? s/n: ");
        fflush(stdin);
        scanf("%c",&seguir);

        if(seguir != 's')
            break;
    }

    return i;
}
int minimo(int edad[],int cant)
{
    int menor;
    int flag = 0;
    int i;

    for(i=0; i<cant;i++)
    {
        if(flag == 0 || edad[i]<menor)
        {
            menor = edad[i];
            flag = 1;
        }
    }
    return menor;
}

int maximo(int edad[],int cant)
{
    int mayor;
    int flag = 0;
    int i;

    for(i=0; i<cant;i++)
    {
        if(flag == 0 || edad[i]>mayor)
        {
            mayor = edad[i];
            flag = 1;
        }
    }
    return mayor;
}

float prom(int edad[],int cant)
{
    int promedio,i;
    int acum = 0;

    for(i = 0; i < cant;i++)
    {
        acum = acum + edad[i];
    }
    promedio = (float)acum / cant;

    return promedio;
}

