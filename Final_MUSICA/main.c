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

    ArrayList* lista_escuchados = al_newArrayList();
    inicializar_lista(lista_escuchados);

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
            escuchar_tema(lista_temas, lista_usuarios, lista_escuchados);
            break;
        case 4:
            saveFile(lista_escuchados,lista_usuarios,lista_temas);
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
