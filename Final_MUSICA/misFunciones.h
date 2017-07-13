#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int idUsuario;
    char nombre[20];
    char email[40];
    char sexo[10];
    char pais[5];
    char password[50];
    char ip_address[25];

}S_Usuario;

typedef struct
{
    int idTemas;
    char nombre[40];
    char artista[50];

}S_Temas;

typedef struct
{
    int idUsuario;
    int idTemas;

}S_Escuchados;

int menuOpcion();
ArrayList* inicializar_lista(ArrayList* this);

S_Usuario* usuarios_new(void);
S_Temas* temas_new(void);
S_Escuchados* escuchados_new(void);

void cargar_usuarios(ArrayList* lista_usuarios);
void cargar_temas(ArrayList* lista_temas);

void listarUsuarios(ArrayList* lista_feed);

void parserEmployee(FILE* pFile,ArrayList* lista_usuarios);
void parserTema(FILE* pFile, ArrayList* lista_temas);
void imprimir(ArrayList* this, int estructura);
int compareInt(void* pUsuarioA,void* pUsuarioB);
int compareNom(void* pUsuarioA, void* pUsuarioB);
int compareNac(void* pUsuarioA, void* pUsuarioB);
int compareArtista(void* pTemaA, void* pTema);
void listar_NombreyNac(ArrayList* this);
void saveFile(ArrayList* lista_escuchados, ArrayList* lista_usuarios, ArrayList* lista_temas);
void listar_temas(ArrayList* this);
void escuchar_tema(ArrayList* lista_temas, ArrayList* lista_usuarios, ArrayList* lista_escuchados);
#endif //USUARIOS_H_INCLUDED
