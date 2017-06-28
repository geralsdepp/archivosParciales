#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idUsuario; //identificador del mensaje
    char nick[20]; // Apodo del usuario en la red social
    int seguidores; // Refiere a la popularidad del usuario (cantidad de seguidores)

}S_Usuario;

typedef struct
{
    int idMensaje; //El identificador del mensaje
    char mensaje[4050]; // El contenido de la publicacion
    int likes; // Refiere a la popularidad de la publicacion(cantidad de likes)
    int idUsuario;//El identificador que creo la publicacion

}S_Post;

typedef struct
{
    int idMensaje; //El identificador del mensaje
    char mensaje[4050]; //El contenido de la publicacion
    int likes; //Refiere a la popularidad de la publicacion (cantidad de likes)
    int idUsuario; //El identificador del usuario que creo la publicacion
    char nick[20]; //Apodo del usuario en la red social
    int seguidores;//Refiere a la popularidad del usuario (cantidad de seguidores)

}S_Feed;

int menuOpcion();
ArrayList* inicializar_lista(ArrayList* this);

S_Usuario* usuarios_new(void);
S_Post* mensajes_new(void);
S_Feed* feed_new(void);

void cargar_usuarios(ArrayList* lista_usuarios);
void cargar_mensajes(ArrayList* lista_mensajes);
void cargar_feed(ArrayList* lista_feed);
void depurar(ArrayList* lista_usuarios, ArrayList* lista_mensajes, ArrayList* lista_feed);
void listar(ArrayList* lista_feed);

void parserEmployee(FILE* pFile,ArrayList* lista_usuarios);
void parserPost(FILE* pFile, ArrayList* lista_mensajes);
void imprimir(ArrayList* this, int estructura);
int compare(void* pUsuarioA,void* pUsuarioB);
void saveFile(ArrayList* this);

#endif //USUARIOS_H_INCLUDED
