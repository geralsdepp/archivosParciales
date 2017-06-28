#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* lista, int* len)
{
    Employee* empleado;
    char aux_id[10],aux_isEmpty[10];
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            empleado = (Employee*)malloc(sizeof(Employee)); //asigno memoria por cada empleado
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",aux_id,empleado->name,empleado->lastName,aux_isEmpty);
            empleado->id = atoi(aux_id);
            empleado->isEmpty = atoi(aux_isEmpty);
            al_add(lista,(void*)empleado);
        }
        fclose(pFile);

    }
    return 0;
}

int menu_opcion(void)
{
    int opcion;

    printf("Ingrese opcion:\n1. Parse del archivo data.csv\n2. Listar Empleados\n3. Ordenar por nombre\n4. Agregar un elemento\n5. Elimina un elemento\n6. Listar Empleados (Desde/Hasta)\n7. Salir");
    scanf("%d",&opcion);
    return opcion;
}


