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

int usuarios_setName(S_Usuario* this,char* name)
{
    int retorno = -1;

    if(this != NULL && strlen(name) > 0)
    {
        strcpy(this->nombre,name);
        retorno = 0;
    }
    return retorno;
}

int usuarios_setPassword(S_Usuario* this,char* password)
{
    int retorno = -1;

    if(this != NULL && strlen(password) > 0)
    {
        strcpy(this->password,password);
        retorno = 0;
    }
    return retorno;
}

int producto_setIdProducto(S_Producto* this, int idProducto)
{
    int retorno = -1;

    if(this != NULL && idProducto > 0)
    {
        this->idProducto = idProducto;
        retorno = 0;
    }
    return retorno;
}

int producto_setName(S_Producto* this, char* producto)
{
    int retorno = -1;

    if(this != NULL && strlen(producto) > 0)
    {
        strcpy(this->nombre,producto);
        retorno = 0;
    }
    return retorno;
}

int producto_setPrecio(S_Producto* this, int precio)
{
    int retorno = -1;

    if(this != NULL && precio > 0)
    {
        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

int producto_setStock(S_Producto* this, int stock)
{
    int retorno = -1;

    if(this != NULL && stock > 0)
    {
        this->stock = stock;
        retorno = 0;
    }
    return retorno;
}

int producto_setIdUsuario(S_Producto* this, int idUsuario)
{
    int retorno = -1;

    if(this != NULL && idUsuario > 0)
    {
        this->idUsuario = idUsuario;
        retorno = 0;
    }
    return retorno;
}

int producto_setCantidadVendida(S_Producto* this, int cantidadVendida)
{
    int retorno = -1;

    if(cantidadVendida>0)
    {
        this->cantidadVendida = cantidadVendida;
        retorno = 0;
    }
    return retorno;
}

int puntuacion_setPuntuacion(S_Calificacion* this,int puntuacion)
{
    int retorno = -1;

    if(this != NULL && puntuacion > 0)
    {
        this->calif = puntuacion;
        retorno = 0;
    }
    return retorno;
}

int puntuacion_setIdUsuario(S_Calificacion* this, int idUsuario)
{
    int retorno = -1;

    if(this != NULL && idUsuario > 0)
    {
        this->idUsuario = idUsuario;
        retorno = 0;
    }
    return retorno;
}

int puntuacion_setIdPuntuacion(S_Calificacion* this, int idCalificacion)
{
    int retorno = -1;

    if(this != NULL && idCalificacion > 0)
    {
        this->idPuntuacion = idCalificacion;
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

char* usuarios_getName(S_Usuario* this)
{
    char* retorno;
    if(this != NULL)
    {
       retorno = this->nombre;
    }
    return retorno;
}

char* usuarios_getPassword(S_Usuario* this)
{
    char* retorno;
    if(this != NULL)
    {
        retorno = this->password;
    }
    return retorno;
}

int puntuacion_getPuntuacion(S_Calificacion* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->calif;
    }
    return retorno;
}

int puntuacion_getIdUsuario(S_Calificacion* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

int puntuacion_getIdCalif(S_Calificacion* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idPuntuacion;
    }
    return retorno;
}

char* producto_getName(S_Producto* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->nombre;
    }
    return retorno;
}

int producto_getPrecio(S_Producto* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->precio;
    }
    return retorno;
}

int producto_getId(S_Producto* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idProducto;
    }
    return retorno;
}

int producto_getStock(S_Producto* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->stock;
    }
    return retorno;
}

int producto_getIdUsuario(S_Producto* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->idUsuario;
    }
    return retorno;
}

int producto_getCantidadVendida(S_Producto* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->cantidadVendida;
    }
    return retorno;
}
