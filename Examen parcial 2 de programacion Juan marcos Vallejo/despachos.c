#include "despachos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListJMV.h"

/** \brief Crea el espacio en memoria necesario para trabajar con una entidad.
 *
 * \return Direccion de memoria asignada.
 *
 */
eDespacho* desp_new(void)
{
    eDespacho * auxiliar;
    auxiliar = NULL;
    auxiliar = malloc(sizeof(eDespacho));

    return auxiliar;
}

/** \brief Crea el espacio en memoria necesario para trabajar con una entidad, indicando ademàs sus parametros.
 *
 * \param int ID
 * \param CHAR[] Direccion
 * \param CHAR[] Tipo (Urgente o regular)
 * \return El puntero a la direcciòn de memoria asignada.
 *
 */

 eDespacho* desp_paramNew(int idDespacho, char* direccion, int tipo)
 {
    eDespacho* auxiliar = NULL;

    if(idDespacho > 0 && direccion != NULL)
    {
        auxiliar = malloc(sizeof(eDespacho));

        if(auxiliar != NULL)
        {
            desp_setDir(auxiliar, direccion);
            desp_setTipo(auxiliar, tipo);
            desp_setNroDespacho(auxiliar, idDespacho);
        }
    }

    return auxiliar;
 }

/** \brief Modifica el la dir de un despacho
 *
 * \param Puntero a la dirección de memoria del despacho.
 * \return Retorna [0] Si todo está bien o [-1] En caso de error.
 *
 */

 int desp_setDir(eDespacho* this, char* textoParaAsignar)
 {
    int retorno = -1;
    int check = strlen(textoParaAsignar);

    if(this != NULL && check <= 99)
    {
        strcpy(this->direccion, textoParaAsignar);
        retorno = 0;
    }
    return retorno;
 }

 /** \brief Setea el tipo de despacho.
 *
 * \param Puntero a la dirección de memoria de la entidad.
 * \param int 1 en caso de ser urgente 0 en caso de ser regular.
 * \return [0] Si todo salió bien o [-1] En caso de error
 *
 */

 int desp_setTipo(eDespacho* this, int tipoDeDespacho)
 {
    int retorno = -1;
    if(this != NULL && (tipoDeDespacho  == 0 || tipoDeDespacho == 1))
    {
        if(tipoDeDespacho == 0) // Si el despacho es urgente.
        {
            this->tipo = 0;
            retorno = 0;
        }
        if(tipoDeDespacho == 1) // Si el despacho es regular
        {
            this->tipo = 1;
            retorno = 0;
        }
        retorno = 0;
    }
    return retorno;
 }

  /** \brief Setea el nro de despacho.
 *
 * \param Puntero a la dirección de memoria de la entidad.
 * \param int nroDespacho.
 * \return [0] Si todo salió bien o [-1] En caso de error
 *
 */

 int desp_setNroDespacho(eDespacho* this, int nroDesp)
 {
    int retorno = -1;
    if(this != NULL)
    {
        if(nroDesp > 0) // Si el despacho es regular
        {
            this->nroDespacho = nroDesp;
            retorno = 0;
        }
        retorno = 0;
    }
    return retorno;
 }



/** \brief Funcion que busca dentro del array list de despachos el próximo ID a Asignar a la entidad despacho
 *
 * \param Array List en cuestion.
 * \return int Retorna el id próximo o -1 en caso de error.
 *
 */

 int desp_searchNewId(ArrayList *pList)
 {
    int ret = -1;
    int mayor = 0; // Acumulador.
    int i; // Contador
    eDespacho *aux = desp_new(); // Asignamos espacio en memoria.

    if(pList!=NULL && aux != NULL)
    {
        if(al_isEmpty(pList) == 1) // If the array list is empty.
        {
            ret = 1; // In this case the first ID will be 1.
        }
        else   {
                    for(i=0; i < al_len(pList); i++) // Recorremos el array.
                    {
                            aux = al_get(pList, i);
                            if(desp_GetNro(aux) > mayor)
                            {
                                mayor = desp_GetNro(aux);
                            }
                    }
                        ret = mayor;
                        ret++;
                }
    }
    return ret;

 }

 /** \brief Get nro desp.
  *
  * \param eDespacho - puntero a la direccion de memoria.
  * \return Retorna como entero el nro de despacho
  *
  */
  int desp_GetNro(eDespacho* this)
 {
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->nroDespacho;
    }
    return retorno;
 }

 /** \brief Get tipo desp.
  *
  * \param eDespacho - puntero a la direccion de memoria.
  * \return Retorna el tipo de despacho (0 Urgente - 1 Regular)
  *
  */

  int desp_GetTipo(eDespacho* this)
 {
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->tipo;
    }
    return retorno;
 }


/** \brief Libera el espacio en memoria asignado a una entidad despacho
 *
 * \param eDespacho * Puntero a la entidad en cuestion
 *
 */
void desp_del(eDespacho *this)
 {
     free(this);
 }

/** \brief Obtain the index of the send in the array list by ID.
  *
  * \param Pointer to arrayList.
  * \param int Id to search in the AL.
  * \return Returns the index of the element or -1 in case of error.
  *
  */

  int movie_SearchIndexById(ArrayList *pList, int idParaBuscar)
  {
    int ret = -1;
    int i; // Contador.
    eDespacho *aux = desp_new();

        for(i=0; i < al_len(pList); i++)
        {
            aux = al_get(pList, i);
            if(desp_GetNro(aux) == idParaBuscar)
            {
                ret = i;
                break;
            }
        }

    desp_del(aux);
    return ret;

  }
