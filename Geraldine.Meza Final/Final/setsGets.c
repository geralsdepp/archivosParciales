#include "string.h"
#include "ArrayList.h"
#include "misFunciones.h"
#include "setsGets.h"

int log_setServiceId(S_LogEntry* this, int idService)
{
    int retorno = -1;

    if(this != NULL && idService > 0)
    {
        this->serviceId = idService;
        retorno = 0;
    }
    return retorno;
}
int log_setDate(S_LogEntry* this, char* date)
{
    int retorno = -1;

    if(this != NULL && strlen(date) > 0)
    {
        strcpy(this->date,date);
        retorno = 0;
    }
    return retorno;
}
int log_setTime(S_LogEntry* this, char* time)
{
    int retorno = -1;

    if(this != NULL && strlen(time) > 0)
    {
        strcpy(this->time,time);
        retorno = 0;
    }
    return retorno;
}
int log_setGravedad(S_LogEntry* this, int gravedad)
{
    int retorno = -1;

    if(this != NULL && gravedad >= 0)
    {
        this->gravedad = gravedad;
        retorno = 0;
    }
    return retorno;
}
int log_setMsg(S_LogEntry* this, char* msg)
{
    int retorno = -1;

    if(this != NULL && strlen(msg) > 0)
    {
        strcpy(this->msg,msg);
        retorno = 0;
    }
    return retorno;
}


int log_getServiceId(S_LogEntry* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->serviceId;
    }
    return retorno;
}
char* log_getDate(S_LogEntry* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->date;
    }
    return retorno;
}
char* log_getTime(S_LogEntry* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->time;
    }
    return retorno;
}
int log_getGravedad(S_LogEntry* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->gravedad;
    }
    return retorno;
}
char* log_getMsg(S_LogEntry* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->msg;
    }
    return retorno;
}

int service_setId(S_Service* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int service_setName(S_Service* this, char* name)
{
    int retorno = -1;

    if(this != NULL && strlen(name)>0)
    {
        strcpy(this->name,name);
        retorno = 0;
    }
    return retorno;
}
int service_setEmail(S_Service* this, char* email)
{
    int retorno = -1;

    if(this != NULL && strlen(email) > 0)
    {
        strcpy(this->email,email);
        retorno = 0;
    }
    return retorno;
}

int service_getId(S_Service* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        retorno = this->id;
    }
    return retorno;
}
char* service_getName(S_Service* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}
char* service_getEmail(S_Service* this)
{
    char* retorno = NULL;

    if(this != NULL)
    {
        retorno = this->email;
    }
    return retorno;
}

