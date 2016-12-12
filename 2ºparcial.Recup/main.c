#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "validaciones.h"
#include "parserEmployee.h"
#include "misFunciones.h"

int main()
{
    int i;
    FILE *pArchivo,*pArchivo2, *pArchivo3;

    ArrayList *listUsuarios;
    //ArrayList *listMensajes;
    //ArrayList *listFeed;

    Usuario *pUsuario;
    //Post *pMensaje;
    //Feed* pFeed;

    int cant,longi = 255;
    char texto[4000];
    char *buffer[4000];

    listUsuarios = al_newArrayList();
    //listMensajes = al_newArrayList();
    //listFeed = al_newArrayList();


   // listFeed = listUsuarios;
    //listFeed = listMensajes;

    pArchivo = fopen("usuarios.csv","r"); //abro el archivo para leerlo
    //pArchivo2 = fopen("mensajes.csv","r"); //abro el archivo para leerlo
    //pArchivo3 = fopen("feed.csv", "a"); //abro el archivo para agregar datos


    fgets(texto, sizeof(texto), pArchivo); //leo linea por linea
    *buffer = strtok(texto, ",");

    parserUsuario(pArchivo, listUsuarios);
//    parserPost(pArchivo2, listMensajes);

    //ahora recorro mi lista de usuarios

    for(i=0; i<al_len(listUsuarios);i++ )  //al_len  me retorna el tamaño del arraylist
    {
        pUsuario = al_get(listUsuarios, i); //al_get me retorna el puntero al elemento especificado
    }

    al_sort(listUsuarios, ordenar_numeros,0); //ordena los elementos del array

    for(i=al_len(listUsuarios)-20; i>0; i--)
    {
        usuario_delete(al_pop(listUsuarios,0));
    }

    for(i=0; i<al_len(listUsuarios);i++)
    {
        pUsuario = al_get(listUsuarios,i);
        printf("%d--%s--%d\n", usuario_getId(pUsuario), usuario_getnick(pUsuario),usuario_getSeguidores(pUsuario));
    }

    fclose(pArchivo);



    return 0;
}
