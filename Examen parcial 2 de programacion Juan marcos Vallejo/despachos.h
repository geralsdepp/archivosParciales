#ifndef DESPACHOS_H_INCLUDED
#define DESPACHOS_H_INCLUDED

#include "ArrayListJMV.h"

typedef struct{
int nroDespacho;
char direccion[100];
int tipo;
}eDespacho;

eDespacho* desp_new(void);
eDespacho* desp_paramNew(int idDespacho, char* direccion, int tipo);
void desp_del(eDespacho *this);
int desp_searchNewId(ArrayList *pList);
int movie_SearchIndexById(ArrayList *pList, int idParaBuscar);

// MISC
int desp_searchNewId(ArrayList *pList);

// Sets
int desp_setDir(eDespacho* this, char* textoParaAsignar);
int desp_setNroDespacho(eDespacho* this, int nroDesp);
int desp_setTipo(eDespacho* this, int tipoDeDespacho);

// GET.
int desp_GetNro(eDespacho* this);
int desp_GetTipo(eDespacho* this);

#endif // DESPACHOS_H
