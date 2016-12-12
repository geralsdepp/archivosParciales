#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "misFunciones.h"
#include "parserEmployee.h"

int parserUsuario(FILE* pArchivo , ArrayList* usuarios)
{
    int retorno=-1;
    int firstTime=1;
    Usuario *pUsuario;
    char id_usuario[256], seguidores[256];
    char nick[256];
    if(pArchivo != NULL && usuarios != NULL)
    {
        retorno = 0;
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",id_usuario,nick,seguidores);
            if(firstTime){firstTime=0;continue;} // Salto la primera
            pUsuario = usuario_new();
            usuario_setId(pUsuario,atoi(id_usuario));
            usuario_setnick(pUsuario,nick);
            usuario_setSeguidores(pUsuario,seguidores);
            al_add(usuarios,pUsuario);
        }
        //printf("%d" , al_len(pArrayListEmployee));
    }
    return retorno;
}

int parserPost(FILE* pArchivo , ArrayList* mensajes)
{
    int retorno=-1;
    int firstTime=1;
    Post *pMensaje;
    char id_mensaje[256], likes[256], id_usuario[256],mensaje[256];

    if(pArchivo != NULL && mensajes != NULL)
    {
        retorno = 0;
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",id_usuario,id_mensaje, likes, mensaje);
            if(firstTime){firstTime=0;continue;} // Salto la primera
            pMensaje = post_new();
            post_setId(pMensaje,atoi(id_mensaje));
            post_setMensaje(pMensaje,mensaje);
            al_add(mensajes,pMensaje);
        }
        //printf("%d" , al_len(pArrayListEmployee));
    }
    return retorno;
}
