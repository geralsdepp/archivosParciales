#include "string.h"
#include "ArrayList.h"
#include "misFunciones.h"
#include "setsGets.h"

int usuarios_setId(S_Usuario* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idUsuario = id;
        retorno = 0;
    }

    return retorno;
}

int usuarios_setNombre(S_Usuario* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setEmail(S_Usuario* this, char* email)
{
    int retorno = -1;

    if(this != NULL && strlen(email) > 0)
    {
        strcpy(this->email,email);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setPais(S_Usuario* this, char* pais)
{
    int retorno = -1;

    if(this != NULL && strlen(pais) > 0)
    {
        strcpy(this->pais,pais);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setSexo(S_Usuario* this, char* sexo)
{
    int retorno = -1;

    if(this != NULL && strlen(sexo) > 0)
    {
        strcpy(this->sexo,sexo);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setPassword(S_Usuario* this, char* password)
{
    int retorno = -1;

    if(this != NULL && strlen(password) > 0)
    {
        strcpy(this->password,password);
        retorno = 0;
    }
    return retorno;
}
int usuarios_setIpAddress(S_Usuario* this, char* ipAddres)
{
    int retorno = -1;

    if(this != NULL && strlen(ipAddres) > 0)
    {
        strcpy(this->ip_address,ipAddres);
        retorno = 0;
    }
    return retorno;
}

int temas_setId(S_Temas* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idTemas = id;
        retorno = 0;
    }
    return retorno;
}

int temas_setNombre(S_Temas* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && strlen(nombre) > 0)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int temas_setArtista(S_Temas* this, char* artista)
{
    int retorno = -1;

    if(this != NULL && strlen(artista) > 0)
    {
        strcpy(this->artista, artista);
        retorno = 0;
    }
    return retorno;
}

int usuarios_getId(S_Usuario* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

char* usuarios_getNombre(S_Usuario* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->nombre;
    }
    return retorno;
}
char* usuarios_getEmail(S_Usuario* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->email;
    }
    return retorno;
}
char* usuarios_getSexo(S_Usuario* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->sexo;
    }
    return retorno;
}
char* usuarios_getPais(S_Usuario* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->pais;
    }
    return retorno;
}
char* usuarios_getPassword(S_Usuario* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->password;
    }
    return retorno;
}
char* usuarios_getIpAddress(S_Usuario* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->ip_address;
    }
    return retorno;
}

int temas_getId(S_Temas* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idTemas;
    }
    return retorno;
}
char* temas_getNombre(S_Temas* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->nombre;
    }
    return retorno;
}
char* temas_getArtista(S_Temas* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->artista;
    }
    return retorno;
}

int escuchados_setIdUsuario(S_Escuchados* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idUsuario = id;
        retorno = 0;
    }
    return retorno;
}

int escuchados_setIdTema(S_Escuchados* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->idTemas = id;
        retorno = 0;
    }
    return retorno;
}

int escuchados_getIdUsuario(S_Escuchados* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

int escuchados_getIdTema(S_Escuchados* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idTemas;
    }
    return retorno;
}
