#include "misSetsyGets.h"
#include "misFunciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int usuarios_setId(S_Usuario* this,int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idUsuario = id;
        retorno = 0;
    }
    return retorno;
}

int usuarios_setNick(S_Usuario* this,char* nick)
{
    int retorno = -1;

    if(this != NULL && strlen(nick) > 0)
    {
        strcpy(this->nick,nick);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setSeguidores(S_Usuario* this,int seguidores)
{
    int retorno = -1;

    if(this != NULL && seguidores > 0)
    {
        this->seguidores = seguidores;
        retorno = 0;
    }
    return retorno;
}

int mensajes_setId(S_Post* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idMensaje = id;
        retorno = 0;
    }
    return retorno;
}

int mensajes_setMensaje(S_Post* this, char* mensaje)
{
    int retorno = -1;

    if(this != NULL && strlen(mensaje) > 0)
    {
        strcpy(this->mensaje,mensaje);
        retorno = 0;
    }
    return retorno;
}

int mensajes_setLikes(S_Post* this, int likes)
{
    int retorno = -1;

    if(this != NULL && likes > 0)
    {
        this->likes = likes;
        retorno = 0;
    }
    return retorno;
}

int mensajes_setIdUsuario(S_Post* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idUsuario = id;
        retorno = 0;
    }
    return retorno;
}

int feed_setIdMensaje(S_Feed* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idMensaje = id;
        retorno = 0;
    }
    return retorno;
}

int feed_setMensaje(S_Feed* this, char* mensaje)
{
    int retorno = -1;

    if(this != NULL && strlen(mensaje) > 0)
    {
        strcpy(this->mensaje,mensaje);
        retorno = 0;
    }
    return retorno;
}

int feed_setLikes(S_Feed* this, int likes)
{
    int retorno = -1;

    if(this != NULL && likes > 0)
    {
        this->likes = likes;
        retorno = 0;
    }
    return retorno;
}

int feed_setIdUsuario(S_Feed* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idUsuario = id;
        retorno = 0;
    }
    return retorno;
}

int feed_setNick(S_Feed* this, char* nick)
{
    int retorno = -1;

    if(this != NULL && strlen(nick) > 0)
    {
        strcpy(this->nick,nick);
        retorno = 0;
    }
    return retorno;
}

int feed_setSeguidores(S_Feed* this, int seguidores)
{
    int retorno = -1;

    if(this != NULL && seguidores > 0)
    {
        this->seguidores = seguidores;
        retorno = 0;
    }
    return retorno;
}

int usuarios_getId(S_Usuario* this)
{
    int retorno = -1;

    if(this != NULL )
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

char* usuarios_getNick(S_Usuario* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
       retorno = this->nick;
    }
    return retorno;
}

int usuarios_getSeguidores(S_Usuario* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->seguidores;
    }
    return retorno;
}

int mensajes_getId(S_Post* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idMensaje;
    }
    return retorno;
}

char* mensajes_getMensaje(S_Post* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->mensaje;
    }
    return retorno;
}

int mensajes_getLikes(S_Post* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->likes;
    }
    return retorno;
}

int mensajes_getIdUsuario(S_Post* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

int feed_getIdMensaje(S_Feed* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idMensaje;
    }
    return retorno;
}

char* feed_getMensaje(S_Feed* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->mensaje;
    }

    return retorno;
}

int feed_getLikes(S_Feed* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->likes;
    }
    return retorno;
}

int feed_getIdUsuario(S_Feed* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

char* feed_getNick(S_Feed* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->nick;
    }
    return retorno;
}

int feed_getSeguidores(S_Feed* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->seguidores;
    }
    return retorno;
}

