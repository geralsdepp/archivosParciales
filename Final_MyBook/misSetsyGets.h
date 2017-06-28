#include "misFunciones.h"
//seters

int usuarios_setId(S_Usuario* this,int id);
int usuarios_setNick(S_Usuario* this,char* nick);
int usuarios_setSeguidores(S_Usuario* this,int seguidores);

int mensajes_setId(S_Post* this, int id);
int mensajes_setMensaje(S_Post* this, char* mensaje);
int mensajes_setLikes(S_Post* this, int likes);
int mensajes_setIdUsuario(S_Post* this, int id);

int feed_setIdMensaje(S_Feed* this, int id);
int feed_setMensaje(S_Feed* this, char* mensaje);
int feed_setLikes(S_Feed* this, int likes);
int feed_setIdUsuario(S_Feed* this, int id);
int feed_setNick(S_Feed* this, char* nick);
int feed_setSeguidores(S_Feed* this, int seguidores);

//geters

int usuarios_getId(S_Usuario* this);
char* usuarios_getNick(S_Usuario* this);
int usuarios_getSeguidores(S_Usuario* this);

int mensajes_getId(S_Post* this);
char* mensajes_getMensaje(S_Post* this);
int mensajes_getLikes(S_Post* this);
int mensajes_getIdUsuario(S_Post* this);

int feed_getIdMensaje(S_Feed* this);
char* feed_getMensaje(S_Feed* this);
int feed_getLikes(S_Feed* this);
int feed_getIdUsuario(S_Feed* this);
char* feed_getNick(S_Feed* this);
int feed_getSeguidores(S_Feed* this);
