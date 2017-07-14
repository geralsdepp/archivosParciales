#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#include "ArrayList.h"

int main()
{
    char seguir = 's';
    int opcion;

    ArrayList* lista_logs = al_newArrayList();
    ArrayList* lista_services = al_newArrayList();

    lista_logs = inicializar_lista(lista_logs);
    lista_services = inicializar_lista(lista_services);

    do
    {
        opcion = menuOpcion();

        switch(opcion)
        {
        case 1:
            cargar_logs(lista_logs);
            cargar_services(lista_services);
            break;
        case 2:
            procesar_informacion(lista_logs,lista_services);
            break;
        case 3:
            break;
        case 4:
            seguir = 'n';
            break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    return 0;
}
