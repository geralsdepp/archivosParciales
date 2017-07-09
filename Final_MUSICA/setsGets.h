int usuarios_setId(S_Usuario* this, int id);
int usuarios_setNombre(S_Usuario* this, char* nombre);
int usuarios_setEmail(S_Usuario* this, char* email);
int usuarios_setSexo(S_Usuario* this, char* sexo);
int usuarios_setPais(S_Usuario* this, char* pais);
int usuarios_setPassword(S_Usuario* this, char* password);
int usuarios_setIpAddress(S_Usuario* this, char* ipAddres);

int temas_setId(S_Temas* this, int id);
int temas_setNombre(S_Temas* this, char* nombre);
int temas_setArtista(S_Temas* this, char* artista);

int usuarios_getId(S_Usuario* this);
char* usuarios_getNombre(S_Usuario* this);
char* usuarios_getEmail(S_Usuario* this);
char* usuarios_getSexo(S_Usuario* this);
char* usuarios_getPais(S_Usuario* this);
char* usuarios_getPassword(S_Usuario* this);
char* usuarios_getIpAddress(S_Usuario* this);

int temas_getId(S_Temas* this);
char* temas_getNombre(S_Temas* this);
char* temas_getArtista(S_Temas* this);
