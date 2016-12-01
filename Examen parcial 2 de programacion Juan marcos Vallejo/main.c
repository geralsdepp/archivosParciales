#include <stdio.h>
#include <stdlib.h>
#include "ArrayListJMV.h"
#include "Validaciones.h"
#include "despachos.h"
#include "forms.h"

int main()
{
    // Creamos nuestras listas.
    ArrayList * despachosActivosUrgentes = al_newArrayList();
    ArrayList * despachosActivosRegulares = al_newArrayList();
    ArrayList * despachosInactivosUrgentes = al_newArrayList();
    ArrayList * despachosInactivosRegulares = al_newArrayList();

    char seguir = 's';
    int opcion;
    int tipoDespacho;

    while(seguir != 'n')
    {
    system("cls");
    printf("\t\t [1] ENTREGA URGENTE O REGULAR\n");
    printf("\t\t [2] PROXIMA ENTREGA\n");
    printf("\t\t [3] LISTAR\n");
    printf("\t\t [4] INFORMAR\n");
    printf("\t\t [5] SALIR\n");
    printf("\n\n\t\t Urgentes: %d - Pendientes: %d\n\n", al_len(despachosActivosUrgentes), al_len(despachosActivosRegulares));
    printf("\n\n\t\t InactivosURG: %d - InactivosREG: %d\n\n", al_len(despachosInactivosUrgentes), al_len(despachosInactivosRegulares));
    fflush(stdin);
    scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            // Llamamos al formulario de alta.
            system("cls");
            printf("[INGRESE EL TIPO DE DESPACHO A REALIZAR]\n");
            printf("[ 0 - DESPACHOS URGENTES ]\n");
            printf("[ 1 - DESPACHOS REGULARES ]\n");
            fflush(stdin);
            scanf("%d", &tipoDespacho);
            printf("[ TIPO: %d ]\n", tipoDespacho);


            while(tipoDespacho != 0 && tipoDespacho != 1)
            {
                printf("\nIngrese un despacho valido por favor:");
                scanf("%d", &tipoDespacho);

            }
            form_AltA(despachosActivosUrgentes, despachosActivosRegulares, despachosInactivosUrgentes, despachosInactivosRegulares,tipoDespacho);

            break;
        case 2: // Proxima entrega
            form_Despachar(despachosActivosUrgentes, despachosActivosRegulares, despachosInactivosUrgentes, despachosInactivosRegulares);
            break;
        case 3: // Listar pendientes.
            form_printDespachos(despachosActivosUrgentes, despachosActivosRegulares);
            break;
        case 4: // Informar las entregas ya realizadas de cada tipo ordenadas por direccion de manera descendete.
            form_informar(despachosInactivosUrgentes, despachosInactivosRegulares);
            break;
        case 5:
            // Liberamos las array list.
            seguir = 'n';
            break;
        default:
            system("cls");
            printf("Opcion invalida.\n");
            system("pause");
            break;

        }
    }

    return 0;
}
