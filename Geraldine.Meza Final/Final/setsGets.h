int log_setServiceId(S_LogEntry* this, int idService);
int log_setDate(S_LogEntry* this, char* date);
int log_setTime(S_LogEntry* this, char* time);
int log_setGravedad(S_LogEntry* this, int gravedad);
int log_setMsg(S_LogEntry* this, char* msg);

int log_getServiceId(S_LogEntry* this);
char* log_getDate(S_LogEntry* this);
char* log_getTime(S_LogEntry* this);
int log_getGravedad(S_LogEntry* this);
char* log_getMsg(S_LogEntry* this);

int service_setId(S_Service* this, int id);
int service_setName(S_Service* this, char* name);
int service_setEmail(S_Service* this, char* email);

int service_getId(S_Service* this);
char* service_getName(S_Service* this);
char* service_getEmail(S_Service* this);

