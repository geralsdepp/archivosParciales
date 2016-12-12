#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "validaciones.h"
#include "misFunciones.h"
#include "parserEmployee.h"


int usuario_compare(void* pUsuarioA,void* pUsuarioB)
{
    int retorno = 0;
    if(pUsuarioA != NULL && pUsuarioB != NULL)
    {
        if(strcmp(usuario_getnick(pUsuarioA),usuario_getnick(pUsuarioB)) > 0)
        {
            retorno = 1;
        }
        else if(strcmp(usuario_getnick(pUsuarioA),usuario_getnick(pUsuarioB)) < 0)
        {
            retorno = -1;
        }
    }
    return retorno;
}

void ordenar_numeros(int arreglo[], int lon)
{
    int temp,i,j;

    for(i=0; i<lon;i++)
    {
        for(j=0; j<lon-1; j++)
        {
            if(arreglo[j]<arreglo[j+1])
            {
                temp = arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
        for(i=0; i<lon; i++)
        {
            cout<<arreglo[i]<<endl;
        }
    }
    return 1;
}


//void Usuario_print(Usuario* this)
//{
//
//}


Usuario* usuario_new(void)
{
    Usuario* returnAux = NULL;
    returnAux = malloc(sizeof(Usuario));
    return returnAux;
}

void usuario_delete(Usuario* this)
{
    free(this);
}

int usuario_setId(Usuario* this, int* id_usuario)
{
    int retorno = -1;
    if(this != NULL && id_usuario > 0)
    {
        this->id_usuario = id_usuario;
        retorno = this->id_usuario;
    }
    return retorno;
}

int* usuario_getId(Usuario* this)
{
    int retorno = NULL;
    if(this != NULL)
    {
        retorno = this->id_usuario;
    }
    return retorno;
}

int usuario_setnick(Usuario* this, char* nick)
{
    int retorno = -1;
    if(this != NULL && strlen(nick) > 0)
    {
        retorno = 0;
        strncpy(this->nick,nick,110);
    }
    return retorno;
}

char* usuario_getnick(Usuario* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->nick;
    }
    return retorno;
}

int* usuario_getSeguidores(Usuario* this)
{
    int retorno = NULL;
    if(this != NULL)
    {
        retorno = this->seguidores;
    }
    return retorno;
}

int usuario_setSeguidores(Usuario* this, int* seguidores)
{
    int retorno = -1;
    if(this != NULL && seguidores > 0)
    {
        retorno = 0;
        this->seguidores = seguidores;
    }
    return retorno;
}


/*********************************************/

Post* post_new(void)
{
    Post* returnAux = NULL;
    returnAux = malloc(sizeof(Post));
    return returnAux;
}

void post_delete(Post* this)
{
    free(this);
}

int post_setId(Post* this, int id_mensaje)
{
    int retorno = -1;
    if(this != NULL && id_mensaje > 0)
    {
        retorno = 0;
        this->id_mensaje = id_mensaje;
    }
    return retorno;
}

int post_getId(Post* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->id_mensaje;
    }
    return retorno;
}

int post_setMensaje(Post* this, char* mensaje)
{
    int retorno = -1;
    if(this != NULL && strlen(mensaje) > 0)
    {
        retorno = 0;
        strncpy(this->mensaje,mensaje,50);
    }
    return retorno;
}

char* post_getMensaje(Post* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->mensaje;
    }
    return retorno;
}
