#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int calif;
    int idPuntuacion;
    int idUsuario;
}S_Calificacion;

typedef struct
{
    char nombre[20];
    int precio;
    int idProducto;
    int idUsuario;
    int stock;
    int cantidadVendida;
}S_Producto;

typedef struct
{
    int idUsuario;
    char nombre[20];
    char password[10];

}S_Usuario;


int get_nextID(ArrayList* this,int estructura);
int menuOpcion(void);
ArrayList* inicializar_lista(ArrayList* lista);

S_Usuario* usuarios_new();
void alta_usuario(ArrayList* this);
void baja_usuario(ArrayList* this);
void modificar_usuario(ArrayList* this);

S_Producto* productos_new();
void publicar_producto(ArrayList* this,ArrayList* lista_productos);
void cancelar_publicacion(ArrayList* this, ArrayList* lista_productos);
void modificar_publicacion(ArrayList* this, ArrayList* lista_productos);
void comprar_producto(ArrayList* this,ArrayList* lista_calif);

S_Calificacion* puntuacion_new();
void listar_public_usuario(ArrayList* lista_usuarios, ArrayList* lista_productos);
void listar_public(ArrayList* lista_productos, ArrayList* lista_usuarios);
void listar_usuario(ArrayList* lista_usuarios, ArrayList* lista_calif);

float promedio(ArrayList* this, S_Usuario* auxUsuario, int i);
#endif //USUARIOS_H_INCLUDED
