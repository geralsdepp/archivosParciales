#include "ArrayList.h"
typedef struct
{
    char address[50];
    char cliente[50];
    int despacho;
} Entregas;

Entregas* entrega_new();
Entregas* entrega_add(Entregas* returnAux, int [], char cliente[], char direccion[]);
Entregas* entregas_urgente_saveData(int despacho, char cliente[], char direccion[]);
int get_nextId(int id);
int entrega_urgente_alta(ArrayList* pListEntregas);
int entrega_getId(ArrayList* pListEntregas);

void entrega_list (ArrayList* pListEntregas);

int entregas_urgente_getData(Entregas* auxEntregas);
