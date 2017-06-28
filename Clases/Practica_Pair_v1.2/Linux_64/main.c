#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    FILE* pArchivo;
    ArrayList* lista;
    /*Employee* empleado;
    Employee* empleado2;*/

    int opcion;
    char seguir = 's';

    lista = al_newArrayList();

    int len = al_len(lista);

    pArchivo = fopen("data.csv","r");

    while(seguir == 's')
    {

        opcion = menu_opcion();
        switch(opcion)
        {
        case 1:
            parserEmployee(pArchivo,lista,&len);
            break;
        case 2:
            employee_print(lista);
            break;
        case 3:
            al_sort(lista,employee_compare,1);
            break;
        case 4:
            employee_print(lista);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
