#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float prom(int array_edad[],int cant)
{
    int promedio,i;
    int acum = 0;

    for(i = 0; i < cant;i++)
    {
        acum = acum + array_edad[i];
    }
    promedio = (float)acum / cant;

    return promedio;
}
