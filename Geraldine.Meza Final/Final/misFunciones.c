#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "setsGets.h"
#include "ArrayList.h"
#include "misValidaciones.h"

int menuOpcion()
{
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.LEER LOG.\n");
    printf("2.PROCESAR INFORMACION.\n");
    printf("3.MOSTRAR ESTADISTICA.\n");
    printf("4.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

S_LogEntry* log_new(void)
{
    S_LogEntry* returnAux = NULL;
    returnAux = (S_LogEntry*)malloc(sizeof(S_LogEntry));
    return returnAux;
}

S_Service* service_new(void)
{
    S_Service* returnAux = NULL;
    returnAux = (S_Service*)malloc(sizeof(S_Service));
    return returnAux;
}

/*S_Escuchados* escuchados_new(void)
{
    S_Escuchados* returnAux = NULL;
    returnAux = (S_Escuchados*)malloc(sizeof(S_Escuchados));
    return returnAux;
}*/

ArrayList* inicializar_lista(ArrayList* lista)
{
    lista = (ArrayList*)calloc(lista->reservedSize,sizeof(ArrayList));
    return lista;
}

void cargar_logs(ArrayList* lista_logs)
{
    FILE* pFile;

    pFile = fopen("log.txt","r");
    parserLog(pFile,lista_logs);
    printf("ya parseo");
    imprimir(lista_logs, 1);
}

void cargar_services(ArrayList* lista_sevices)
{
    FILE* pFile;

    pFile = fopen("services.txt","r");
    parserService(pFile,lista_sevices);
    //printf("ya parseo!");
    imprimir(lista_sevices,2);
}

void imprimir(ArrayList* this, int estructura)
{
    S_LogEntry* auxLog = NULL;
    S_Service* auxService = NULL;
    int j,longitud;
    longitud = al_len(this);

    if(estructura == 1)
    {
        for(j=0; j<longitud-1;j++)
        {
            auxLog = (S_LogEntry*)al_get(this,j);
            printf("\nFecha: %s | Hora: %s | IdService: %d | Gravedad: %d | Msg: %s",log_getDate(auxLog), log_getTime(auxLog), log_getServiceId(auxLog), log_getGravedad(auxLog), log_getMsg(auxLog));
        }
    }
    else if(estructura == 2)
    {
        for(j=0; j<longitud-1;j++)
        {
            auxService = (S_Service*)al_get(this,j);
            printf("\nIdService: %d | Name: %s | Email: %s\n",service_getId(auxService),service_getName(auxService),service_getEmail(auxService));
        }
    }
}

void parserLog(FILE* pFile,ArrayList* lista_logs)
{
    char auxServiceId[10], auxDate[11], auxTime[6], auxGravedad[10], auxMsg[65];
    int serviceId,gravedad;
    S_LogEntry* auxLog = NULL;

    if(pFile!=NULL && lista_logs != NULL)
    {
        while(!feof(pFile))
        {
            auxLog = log_new(); //asigno memoria por cada empleado
            fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]",auxDate,auxTime,auxServiceId,auxGravedad,auxMsg);

            log_setDate(auxLog, auxDate);
            log_setTime(auxLog, auxTime);
            serviceId = atoi(auxServiceId);
            log_setServiceId(auxLog, serviceId);
            gravedad = atoi(auxGravedad);
            log_setGravedad(auxLog, gravedad);
            log_setMsg(auxLog, auxMsg);

            al_add(lista_logs, (void*)auxLog);
        }
        fclose(pFile);
    }
}

void parserService(FILE* pFile, ArrayList* lista_services)
{
    S_Service* auxService = NULL;
    char auxIdService[10],auxName[33],auxEmail[65];
    int id;

    if(pFile != NULL && lista_services != NULL)
    {
        while(!feof(pFile))
        {
            auxService = service_new();
            fscanf(pFile,"%[^;];%[^;];%[^\n]",auxIdService,auxName,auxEmail);
            id = atoi(auxIdService);
            service_setId(auxService,id);
            service_setName(auxService,auxName);
            service_setEmail(auxService,auxEmail);

            al_add(lista_services, (void*)auxService);
        }
        fclose(pFile);
    }
}

void procesar_informacion(ArrayList* lista_log, ArrayList* lista_service)
{
    S_LogEntry* auxLog = NULL;
    S_Service* auxService = NULL;

    int i,j;
    int sizeLog = al_len(lista_log);
    int sizeService = al_len(lista_log);

    for(i=0; i<sizeLog; i++)
    {
        auxLog = (S_LogEntry*)al_get(lista_log,i);
        if(log_getGravedad(auxLog) < 3)
            continue;
        else if(log_getGravedad(auxLog) == 3 && log_getServiceId(auxLog) != 45)
            saveFileWarnings(lista_log,lista_service,auxLog);
        else if(log_getGravedad(auxLog) > 4 && log_getGravedad(auxLog) <= 7)
        {
            for(j=0; j<sizeService; j++)
            {
                auxService = (S_Service*)al_get(lista_service,i);
                if(log_getServiceId(auxLog) == service_getId(auxService))
                {
                    printf("%s | %s | %s | %s | %d\n",log_getDate(auxLog),log_getTime(auxLog),service_getName(auxService),log_getMsg(auxLog),log_getGravedad(auxLog));
                }
            }
        }
        else if(log_getGravedad(auxLog) > 7)
            saveFileErrors(lista_log,lista_service,auxLog);

    }
}
void saveFileWarnings(ArrayList* lista_logs,ArrayList* lista_services, S_LogEntry* auxLog)
{
    FILE* pArchivo = NULL;
    S_Service* auxService = NULL;

    int i = 0, sizeService;

    sizeService = al_len(lista_services);
    pArchivo = fopen("warning.txt","a");

    if(pArchivo != NULL)
    {
        for(i=0; i<sizeService; i++)
        {
            auxService = (S_Service*)al_get(lista_services,i);
            if(log_getServiceId(auxLog) == service_getId(auxService))
            {
                ftell(pArchivo);
                fprintf(pArchivo,"%s;%s;%s;%s;%s\n",log_getDate(auxLog),log_getTime(auxLog),service_getName(auxService),log_getMsg(auxLog),service_getEmail(auxService));
            }
        }
        fclose(pArchivo);
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}

void saveFileErrors(ArrayList* lista_logs, ArrayList* lista_services, S_LogEntry* auxLog)
{
        FILE* pArchivo = NULL;
    S_Service* auxService = NULL;

    int i = 0, sizeService;

//    sizeLog = al_len(lista_logs);
    sizeService = al_len(lista_services);
    pArchivo = fopen("errors.txt","a");

    if(pArchivo != NULL)
    {
        for(i=0; i<sizeService; i++)
        {
            auxService = (S_Service*)al_get(lista_services,i);
            if(log_getServiceId(auxLog) == service_getId(auxService))
            {
                ftell(pArchivo);
                fprintf(pArchivo,"%s;%s;%s;%s;%s\n",log_getDate(auxLog),log_getTime(auxLog),service_getName(auxService),log_getMsg(auxLog),service_getEmail(auxService));
            }
        }
        fclose(pArchivo);
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}


