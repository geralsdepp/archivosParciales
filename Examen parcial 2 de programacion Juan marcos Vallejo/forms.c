#include "despachos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

/** \brief Formulario de alta de nuevo despacho
 * \param Puntero a la lista activa urgente
 * \param Puntero a la lista activa regular.
 * \param Puntero a la lista inactiva urgente
 * \param Puntero a la lista inactiva regular
 * \param int Tipo de despacho (0 Urgente - 1 Regular)
 */

void form_AltA(ArrayList *pListUrg, ArrayList *pListReg, ArrayList *pListInactivosUrg, ArrayList*pListInactivosReg, int tipoDespacho)
{
    eDespacho *auxiliar;
    auxiliar = desp_new();
    char buffer[1024];
    int idMayor = 0;
    int idUno, idDos, idTres, idCuatro;
    printf("[ INGRESE LA DIRECCION DEL DESPACHO: ");
    fflush(stdin);
    gets(buffer);

    if(validateField(buffer, 1024, 3, 1, 99) == 1 && pListReg != NULL && pListUrg != NULL && pListInactivosReg != NULL && pListInactivosUrg != NULL) // Si la direccion es valida.
    {

        idUno = desp_searchNewId(pListUrg); // Busco los IDS
        idDos = desp_searchNewId(pListReg);
        idTres = desp_searchNewId(pListInactivosUrg);
        idCuatro = desp_searchNewId(pListInactivosReg);

        if(idUno > idMayor) idMayor = idUno; // Evaluo el mayor.
        if(idDos > idMayor) idMayor = idDos;
        if(idTres > idMayor) idMayor = idTres;
        if(idCuatro > idMayor) idMayor = idCuatro;

        desp_setNroDespacho(auxiliar, idMayor);
        strcpy(auxiliar->direccion, buffer);
        auxiliar->tipo = tipoDespacho;

        if(tipoDespacho == 0)
        al_add(pListUrg, auxiliar);

        if(tipoDespacho == 1)
        al_add(pListReg, auxiliar);

        printf("[ DESPACHO REGISTRADO CORRECTAMENTE ]\n");
        printf("NRO. %d - DIRECCION: %s\n", desp_GetNro(auxiliar), auxiliar->direccion);

    }

}

/** \brief Formulario para realizar el siguiente despacho.
 *
 * \param Puntero a la lista activa urgente
 * \param Puntero a la lista activa regular.
 *
 */

void form_Despachar(ArrayList *pListUrgente, ArrayList *pListRegular, ArrayList *pListInacUrgentes, ArrayList *pListInacRegu)
{
    eDespacho *aux = desp_new();
    printf("[ MENU DE DESPACHOS ]\n\n");

    if(al_len(pListUrgente) >= 1) // Hay registros urgentes próximos a despachar.
    {
        printf("[EXISTEN DESPACHOS URGENTES]\n");
        aux = al_pop(pListUrgente, 0);
        al_add(pListInacUrgentes, aux);
        printf("\nID BORRADO CORRECTAMENTE\n");
    } else if(al_len(pListRegular) >= 1) // Solo quedan registros regulares para trabajar.
        {
        printf("[EXISTEN SOLO DESPACHOS REGULARES]\n");
        aux = al_pop(pListRegular, 0);
        al_add(pListInacRegu, aux);
        printf("\nID BORRADO CORRECTAMENTE\n");
        } else // No existen despachos activos.
            {
                printf("[ POR EL MOMENTO NO SE REGISTRARON USUARIOS ACTIVOS ]\n");
            }


    system("pause");
}

/** \brief Lista las entregas pendientes mostrando sus datos.
 *
 *
 */

void form_printDespachos(ArrayList *pListUrg, ArrayList *pListReg)
{
eDespacho * aux = desp_new();
 int i;
 int contador = 0;
if(al_len(pListUrg) > 0)
{
    for(i=0; i < al_len(pListUrg); i++)
    {
        aux = al_get(pListUrg, i);
        printf("[NRO: %d] Direccion: %s Tipo: ", aux->nroDespacho, aux->direccion);

        if(desp_GetTipo(aux) == 0)// Urgente
        printf("Urgente\n\n");

        if(desp_GetTipo(aux) == 1)
        printf("Regular\n\n");
        contador++;
    }
}

if(al_len(pListReg) > 0)
{
    for(i=0; i < al_len(pListReg); i++)
    {
        aux = al_get(pListReg, i);
        printf("[NRO: %d] Direccion: %s Tipo: ", aux->nroDespacho, aux->direccion);

        if(desp_GetTipo(aux) == 0)// Urgente
        printf("Urgente\n\n");

        if(desp_GetTipo(aux) == 1)
        printf("Regular\n\n");
        contador++;
    }
}

printf("\n\n[SE IMPRIMIERON CORRECTAMENTE %d REGISTROS]\n", contador);
system("pause");
}

/** \brief Informa las entregas ya realizadas de cada tipo, ordenadas por direccion de manera descendente.
 *
 * \param Puntero a arraylist de urgentes inactivos
 * \param Puntero a arraylist de regulares inactivos.
 * \return
 *
 */

void form_informar(ArrayList *pListInactivosUrgentes, ArrayList *pListInactivosRegulares)
{
    eDespacho * aux = desp_new();
    int i;
    int contador = 0;

    al_sort(pListInactivosUrgentes, strcmp, 0);
    al_sort(pListInactivosRegulares, strcmp,0);

if(al_len(pListInactivosUrgentes) > 0)
{

    for(i=0; i < al_len(pListInactivosUrgentes); i++)
    {
        aux = al_get(pListInactivosUrgentes, i);
        printf("[NRO: %d] Direccion: %s Tipo: ", aux->nroDespacho, aux->direccion);

        if(desp_GetTipo(aux) == 0)// Urgente
        printf("Urgente\n\n");

        if(desp_GetTipo(aux) == 1)
        printf("Regular\n\n");
        contador++;
    }
}

if(al_len(pListInactivosRegulares) > 0)
{
    for(i=0; i < al_len(pListInactivosRegulares); i++)
    {
        aux = al_get(pListInactivosRegulares, i);
        printf("[NRO: %d] Direccion: %s Tipo: ", aux->nroDespacho, aux->direccion);

        if(desp_GetTipo(aux) == 0)// Urgente
        printf("Urgente\n\n");

        if(desp_GetTipo(aux) == 1)
        printf("Regular\n\n");
        contador++;
    }
}

printf("\n\n[SE IMPRIMIERON CORRECTAMENTE %d REGISTROS]\n", contador);
system("pause");
}


