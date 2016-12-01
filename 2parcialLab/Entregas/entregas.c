#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entregas.h"
#include "ArrayList.h"
#include "validaciones.h"

Entregas* entrega_new()
{
    Entregas* returnAux = NULL;
    returnAux=(Entregas*)malloc(sizeof(Entregas*));
    return returnAux;
}

int entrega_urgente_alta(ArrayList* pListEntregas)
{
    int retorno = -1;
    Entregas* auxEntregas = NULL;
    if(entregas_urgente_getData(auxEntregas) == 0)
    {
        //printf("Nª despacho: %d -- Cliente: %s -- Direccion: %s\n", auxEntregas->despacho, auxEntregas->cliente, auxEntregas->address);
        //No se puede acceder  a memoria
        pListEntregas->add(pListEntregas, auxEntregas);
        printf("%d",pListEntregas->len(pListEntregas));
        retorno = 0;
    }
    return retorno;
}

Entregas* entregas_urgente_saveData (int despacho, char cliente[], char direccion[])
{
    Entregas* auxEntregas = entrega_new();
    //int despacho = 0;
    if(auxEntregas != NULL)
    {
        strcpy(auxEntregas->cliente,cliente);
        strcpy(auxEntregas->address,direccion);
        auxEntregas->despacho = despacho;
    }
    return auxEntregas;
}

int entregas_urgente_getData (Entregas* auxEntregas)
{
    int retorno = 0, flag = 0;
    int despacho = 0;
    char buffer[400], cliente[51], direccion[51];
    system("cls");
    if(flag == 0 && getStringLetras("Ingrese cliente: ", buffer, 51))
    {
        strncpy(cliente, buffer,51);
        printf("%s\n", cliente);
        flag = 0;
    }
    else
    {
        flag = 1;
    }

    if(flag == 0 && getString("Ingrese la direccion: ", buffer, 51))
    {
        strncpy(direccion, buffer,51);
        printf("%s\n", direccion);
        flag = 0;
    }
    else
    {
        flag = 1;
    }
    if(flag == 0)
    {
        despacho++;
        printf("El numero de despacho es: %d\n",despacho);
        flag = 0;
    }

    if(flag == 0)
    {
        entregas_urgente_saveData(despacho, cliente, direccion);
        retorno = 0;
    }
    return retorno;
}
/*
int entregas_getId(ArrayList* pListEntregas)
{
    int i;
    int indiceMaximo = 0;
    Entregas* pauxEntrega;
    for (i=0; i<pListEntregas->size; i++)
    {
        pauxEntrega = pListEntregas->get(pListEntregas, i);
        if (pauxEntrega->despacho > indiceMaximo);
        indiceMaximo = pauxEntrega->despacho;
    }
    return indiceMaximo;
}*/

/*void entregas_list (ArrayList* pListEntregas)
{
    int i = 0;
    Entregas* pauxEntrega;
    // pauxEntrega = Entregas_new();
    //pauxEntrega =(Entregas*) pListEntregas->get(pListEntregas, i);
// printf("Id: %d -- Nombre: %s -- Carrera: %s -- Clases: %d -- Horas: %d\n", pauxEntrega->id, pauxEntrega->name, pauxEntrega->carrera, pauxEntrega->clases, pauxEntrega->horas);
    for(i=0; i<pListEntregas->len(pListEntregas); i++)
    {
        if(pauxEntrega != NULL)
        {
            pauxEntrega =(Entregas*) pListEntregas->get(pListEntregas, i);
            printf("Nª despacho: %d -- Cliente: %s -- Direccion: %s\n", pauxEntrega->despacho, pauxEntrega->cliente, pauxEntrega->address);
        }
    }
}*/

/*int entregas_modificar(ArrayList* pListEntregas)
{
    char mensaje = "Ingrese el Id de la materia que desea modificar: \n";
    char buffer[4000];
    int index, retorno = -1;
    if(getInt(mensaje, buffer))
    {
        index = atoi(buffer);
        if(pListEntregas->contains(pListEntregas, pListEntregas->get(pListEntregas, index))==1);
        retorno = 0;
    }
    return retorno;
}*/
