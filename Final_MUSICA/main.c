#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#include "ArrayList.h"

int main()
{
    int opcion;
    char seguir = 's';

    ArrayList* lista_usuarios = al_newArrayList();
    inicializar_lista(lista_usuarios);

    ArrayList* lista_temas = al_newArrayList();
    inicializar_lista(lista_temas);

    ArrayList* lista_feed = al_newArrayList();
    inicializar_lista(lista_feed);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            cargar_usuarios(lista_usuarios);
            break;
        case 2:
            cargar_temas(lista_temas);
            break;
        case 3:
           //depurar(lista_usuarios,lista_temas,lista_feed);
           //saveFile(lista_feed);
            break;
        case 4:
            //listar(lista_feed);
            break;
        case 5:

            break;
        case 6:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');

    return 0;
}
