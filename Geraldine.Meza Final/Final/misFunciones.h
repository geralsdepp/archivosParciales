#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char date[11];
    char time[6];
    int serviceId;
    int gravedad;
    char msg[65];

}S_LogEntry;

typedef struct
{
    int id;
    char name[40];
    char email[50];

}S_Service;

/*typedef struct
{
    int idUsuario;
    int idTemas;

}S_Escuchados;*/

int menuOpcion();
ArrayList* inicializar_lista(ArrayList* this);

S_LogEntry* log_new(void);
S_Service* service_new(void);

void cargar_logs(ArrayList* lista_logs);
void cargar_services(ArrayList* lista_services);

void parserLog(FILE* pFile,ArrayList* lista_logs);
void parserService(FILE* pFile, ArrayList* lista_services);
void imprimir(ArrayList* this, int estructura);
void procesar_informacion(ArrayList* lista_log, ArrayList* lista_service);
void saveFileWarnings(ArrayList* lista_logs,ArrayList* lista_services, S_LogEntry* auxLog);
void saveFileErrors(ArrayList* lista_logs, ArrayList* lista_services, S_LogEntry* auxLog);

#endif //USUARIOS_H_INCLUDED
