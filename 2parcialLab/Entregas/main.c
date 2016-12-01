#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entregas.h"
#include "ArrayList.h"
#include "validaciones.h"

int main()
{
    int opcion = 0;
    char seguir = 's';
//    Entregas* clientes;
    ArrayList* L1 = al_newArrayList(); //ENTREGAS URGENTES
    //ArrayList* L2 =  al_newArrayList(); //ENTREGAS REGULARES
    //ArrayList* L3 =  al_newArrayList();
    //ArrayList* L4 =  al_newArrayList();
    /*
    L1->add(L1,clientes->despacho);
    L1->add(L1,clientes->cliente);
    L1->add(L1,clientes->address);*/


    while(seguir == 's')
    {
        opcion = getOpcion(opcion);
        switch(opcion)
        {
            case 1: //ENTREGA URGENTE
                L1->add(L1, entrega_urgente_alta(L1));
                break;
            case 2://ENTREGA REGULAR
                //L2->add(L2, )
                break;
            case 3://PROXIMA ENTREGA
                break;
            case 4://LISTAR
                break;
            case 5://INFORMAR
                break;
            case 6://SALIR
                seguir = 'n';
                break;
        }
    }


    return 0;
}
