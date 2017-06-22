#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#include "ArrayList.h"

int main()
{
    int opcion;
    char seguir = 's';

ArrayList* lista_usuarios = al_newArrayList();
ArrayList* lista_productos = al_newArrayList();
ArrayList* lista_Calificaciones = al_newArrayList();
inicializar_lista(lista_usuarios);
inicializar_lista(lista_productos);
inicializar_lista(lista_Calificaciones);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            alta_usuario(lista_usuarios);
            break;
        case 2:
            modificar_usuario(lista_usuarios);
            break;
        case 3:
            baja_usuario(lista_usuarios);
            break;
        case 4:
            publicar_producto(lista_usuarios,lista_productos);
            break;
        case 5:
            modificar_publicacion(lista_usuarios,lista_productos);
            break;
        case 6:
            cancelar_publicacion(lista_usuarios,lista_productos);
            break;
        case 7:
            comprar_producto(lista_productos,lista_Calificaciones); //falta cantidad vendida
            break;
        case 8:
            listar_public_usuario(lista_usuarios,lista_productos); //anda bien
            break;
        case 9:
            listar_public(lista_productos,lista_usuarios); //anda bien
            break;
        case 10:
            listar_usuario(lista_usuarios, lista_Calificaciones); //no me muestra nada
            break;
        case 11:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    return 0;
}
