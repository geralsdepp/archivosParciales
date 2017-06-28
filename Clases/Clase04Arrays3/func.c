#include <stdio.h>
#include <stdlib.h>
#include "func.h"

float promedio(int edad[], int cantidad)
{
    float retornoPromedio;
    int i, suma=0;

    for(i=0;i<cantidad;i++)
    {
        suma=suma+edad[i];
    }
    retornoPromedio=(float)suma/cantidad;

    return retornoPromedio;
}

void ordenar(int edad[],int cantidad)
{
    int i,j;
    int aux;

    for(i=0; i<cantidad-1;i++)
    {
        for(j=i+1; j<cantidad;j++)
        {
            if(edad[i]>edad[j])
            {
                aux = edad[i];
                edad[i] = edad[j];
                edad[j] = aux;
            }
        }
    }
}

int compactar(int array[],int indice, int size) // El indice es el que quiero eliminar
{
    int i,j;
    int aux;

    for( ;indice<size-1;indice++)
    {
        array[indice] = array[indice+1]; // Copio en el indice lo que sigue en el array
    }
    return size - 1; //Me devuelve el tamaño menos 1.
}

int minimo(int edad[],int cant)
{
    int menor;
    int flag = 0, indiceMinimo;
    int i;

    for(i=0; i<cant;i++)
    {
        if(flag == 0 || edad[i]<menor)
        {
            menor = edad[i];
            flag = 1;
        }
    }
    return indiceMinimo;
}

void sort_new(int array[],int size, int arrayOrdenado[])
{
    int i;
    int indiceMinimo;
    int sizeInicial = size;

    for(i=0;i<sizeInicial;i++)
    {
        indiceMinimo = minimo(array,size);
        arrayOrdenado[i] = array[indiceMinimo];
        size = compactar(array,size,indiceMinimo);
    }
}
