#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    /*ArrayList* lista2;

    lista2=al_newArrayList();*/
    int retorno;
    Employee* auxiliarA = (Employee*)pEmployeeA;
    Employee* auxiliarB = (Employee*)pEmployeeB;


    if(strcmp(auxiliarA->name,auxiliarB->name) < 0)
        retorno = 1;
    else if(strcmp(auxiliarA->name,auxiliarB->name) > 0)
        retorno = -1;
    else
        retorno = 0;

    return retorno;
}


void employee_print(ArrayList* lista)
{
    Employee* empleado;
    int i=0;
    int len = al_len(lista);

    for(i=0; i<len;i++)
    {
        empleado = (Employee*)al_get(lista,i);
        printf("id: %d,nombre: %s,apellido: %s,isEmpty: %d\n",empleado->id,empleado->name,empleado->lastName,empleado->isEmpty);
    }
}

Employee* employee_new(void)
{

    Employee* returnAux = NULL;


    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


