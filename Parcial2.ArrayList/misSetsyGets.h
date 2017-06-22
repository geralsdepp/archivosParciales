#include "misFunciones.h"
//seters

int usuarios_setId(S_Usuario* this,int id);
int usuarios_setName(S_Usuario* this,char* name);
int usuarios_setPassword(S_Usuario* this,char* password);
int usuarios_setPuntuacion(S_Usuario* this,int puntuacion);

int producto_setName(S_Producto* this, char* producto);
int producto_setPrecio(S_Producto* this, int precio);
int producto_setStock(S_Producto* this, int stock);
int producto_setIdProducto(S_Producto* this, int idProducto);
int producto_setIdUsuario(S_Producto* this, int idUsuario);
int producto_setCantidadVendida(S_Producto* this, int cantidadVendida);

int puntuacion_setIdPuntuacion(S_Calificacion* this, int idCalificacion);
int puntuacion_setPuntuacion(S_Calificacion* this,int puntuacion);
int puntuacion_setIdUsuario(S_Calificacion* this, int idUsuario);
//geters


int usuarios_getId(S_Usuario* this);
char* usuarios_getName(S_Usuario* this);
char* usuarios_getPassword(S_Usuario* this);
int usuarios_getPuntuacion(S_Usuario* this);

char* producto_getName(S_Producto* this);
int producto_getPrecio(S_Producto* this);
int producto_getId(S_Producto* this);
int producto_getStock(S_Producto* this);
int producto_getIdUsuario(S_Producto* this);
int producto_getCantidadVendida(S_Producto* this);

int puntuacion_getIdUsuario(S_Calificacion* this);
int puntuacion_getIdCalif(S_Calificacion* this);
int puntuacion_getPuntuacion(S_Calificacion* this);
