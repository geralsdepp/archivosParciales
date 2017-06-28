#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "ArrayList.h"
#include "misSetsyGets.h"
#include "misValidaciones.h"


int menuOpcion(){
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.CARGAR USUARIOS.\n");
    printf("2.CARGAR MENSAJES.\n");
    printf("3.DEPURAR.\n");
    printf("4.LISTAR\n");
    printf("5.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

S_Usuario* usuarios_new(void)
{
    S_Usuario* returnAux = NULL;
    returnAux = (S_Usuario*)malloc(sizeof(S_Usuario));
    return returnAux;
}

S_Post* mensajes_new(void)
{
    S_Post* returnAux = NULL;
    returnAux = (S_Post*)malloc(sizeof(S_Post));
    return returnAux;
}

S_Feed* feed_new(void)
{
    S_Feed* returnAux = NULL;
    returnAux = (S_Feed*)malloc(sizeof(S_Feed));
    return returnAux;
}

ArrayList* inicializar_lista(ArrayList* lista)
{
    lista = (ArrayList*)calloc(lista->reservedSize,sizeof(ArrayList));
    return lista;
}


void cargar_usuarios(ArrayList* lista_usuarios)
{
    //S_Usuario* auxUsuario = NULL;
    //auxUsuario = usuarios_new();
    FILE* pFile;

    pFile = fopen("usuarios.csv","r");
    parserEmployee(pFile,lista_usuarios);
    imprimir(lista_usuarios,1);
//    al_add(this,(void*)auxUsuario);
}

void cargar_mensajes(ArrayList* lista_mensajes)
{
   // S_Post* auxMensajes = NULL;
   // auxMensajes = mensajes_new();
    FILE* pFile;

    pFile = fopen("mensajes.csv","r");
    parserPost(pFile,lista_mensajes);
    imprimir(lista_mensajes,2);
   // al_add(this,(void*)auxMensajes);
}

void imprimir(ArrayList* this, int estructura)
{
    S_Usuario* auxUsuario = NULL;
    S_Post* auxMensaje = NULL;
    S_Feed* auxFeed = NULL;
    int j,longitud;
    longitud = this->len(this);

    if(estructura == 1)
    {
        for(j=0; j<longitud-1;j++)
        {
            auxUsuario = (S_Usuario*)this->get(this,j);
            printf("idUsuario: %d | nick: %s | seguidores: %d\n",usuarios_getId(auxUsuario),usuarios_getNick(auxUsuario),usuarios_getSeguidores(auxUsuario));
        }
    }
    else if(estructura == 2)
    {
        for(j=0; j<longitud-1;j++)
        {
            auxMensaje = (S_Post*)this->get(this,j);
            printf("idMensaje: %d | idUsuario: %d | Likes: %d | Mensaje: %s\n",mensajes_getId(auxMensaje),mensajes_getIdUsuario(auxMensaje),mensajes_getLikes(auxMensaje),mensajes_getMensaje(auxMensaje));
        }
    }
    else if(estructura == 3)
    {
        for(j=0; j<longitud;j++)
        {
            auxFeed = (S_Feed*)this->get(this,j);
            printf("Nick: %s --> seguidores: %d\n  Mensaje: %s --> likes: %d\n",auxFeed->nick,auxFeed->seguidores,auxFeed->mensaje,auxFeed->likes);
        }
    }
    system("pause");
}

void parserEmployee(FILE* pFile,ArrayList* lista_usuarios)
{
    char buffer[50], auxId[10], auxSeguidor[10],auxNick[50];
    S_Usuario* auxUsuario = NULL;

    if(pFile!=NULL && lista_usuarios != NULL)
    {
        fgets(buffer,50,pFile);
        while(!feof(pFile))
        {
            auxUsuario = usuarios_new(); //asigno memoria por cada empleado
            fscanf(pFile,"%[^,],%[^,],%[^\n]",auxId,auxNick,auxSeguidor);
            usuarios_setId(auxUsuario,atoi(auxId));
            usuarios_setNick(auxUsuario,auxNick);
            usuarios_setSeguidores(auxUsuario,atoi(auxSeguidor));
            al_add(lista_usuarios, (void*)auxUsuario);
        }
        fclose(pFile);
    }
}

void parserPost(FILE* pFile, ArrayList* lista_mensajes)
{
    S_Post* auxMensaje = NULL;
    char buffer[50], auxId[10],auxIdMensaje[10],auxLikes[10],auxMensajes[4050];

    if(pFile != NULL && lista_mensajes != NULL)
    {
        fgets(buffer,50,pFile);
        while(!feof(pFile))
        {
            auxMensaje = mensajes_new();
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",auxIdMensaje,auxId,auxLikes,auxMensajes);
            mensajes_setId(auxMensaje,atoi(auxIdMensaje));
            mensajes_setIdUsuario(auxMensaje,atoi(auxId));
            mensajes_setLikes(auxMensaje,atoi(auxLikes));
            mensajes_setMensaje(auxMensaje,auxMensajes);
            al_add(lista_mensajes, (void*)auxMensaje);
        }
        fclose(pFile);
    }
}

void depurar(ArrayList* lista_usuarios, ArrayList* lista_mensajes, ArrayList* lista_feed)
{
    int i,j,k=0;
    int longitudUsuarios = lista_usuarios->len(lista_usuarios);
    int longitudMensajes = lista_mensajes->len(lista_mensajes);
    S_Usuario* auxUsuario = NULL;
    S_Post* auxMensaje = NULL;
    S_Feed* auxFeed = NULL;

    for(i=0; i<longitudUsuarios; i++) //no entra en el for
    {
        for(j=0; j<longitudMensajes; j++)
        {
            auxUsuario = (S_Usuario*)lista_usuarios->get(lista_usuarios,i);
            auxMensaje = (S_Post*)lista_mensajes->get(lista_mensajes,j);

            if(usuarios_getId(auxUsuario) == mensajes_getIdUsuario(auxMensaje))
            {
                auxFeed = feed_new();
                feed_setIdMensaje(auxFeed,mensajes_getId(auxMensaje));
                feed_setIdUsuario(auxFeed,mensajes_getIdUsuario(auxMensaje));
                feed_setLikes(auxFeed,mensajes_getLikes(auxMensaje));
                feed_setMensaje(auxFeed,mensajes_getMensaje(auxMensaje));
                feed_setNick(auxFeed,usuarios_getNick(auxUsuario));
                feed_setSeguidores(auxFeed,usuarios_getSeguidores(auxUsuario));
                al_add(lista_feed,(void*)auxFeed);
                printf("DEPURADO\n");
                k++;
            }
        }
    }
}

int compare(void* pUsuarioA,void* pUsuarioB)
{
    int retorno;

    S_Feed* auxiliarA = (S_Feed*)pUsuarioA;
    S_Feed* auxiliarB = (S_Feed*)pUsuarioB;

    if(auxiliarA->seguidores < auxiliarB->seguidores)
        retorno = 1;
    else if(auxiliarA->seguidores > auxiliarB->seguidores)
        retorno = -1;
    else if(auxiliarA->seguidores == auxiliarB->seguidores)
        retorno = 0;

    return retorno;
}

void listar(ArrayList* lista_feed)
{
    if(al_sort(lista_feed, compare, 0)==0)
        imprimir(lista_feed,3);
}

void saveFile(ArrayList* this)
{
    S_Feed* auxFeed = NULL;
    auxFeed = feed_new();
    FILE *pArchivo;
    int i = 0, cantidad;
    pArchivo = fopen("feed.csv", "w");
    if(pArchivo != NULL)
    {
        if (auxFeed != NULL)
        {
            cantidad = this->len(this);
            for(i=0; i<cantidad; i++)
            {
                auxFeed = this->get(this, i);
                fwrite((S_Feed*)this->get(this, i), sizeof(S_Feed),1,pArchivo);

            }
            fclose(pArchivo);
            printf("Archivo guardado con exito\n\n");
        }
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}
