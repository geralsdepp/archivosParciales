typedef struct
{
    int id_mensaje;
    char mensaje[255];
    int likes;
    int id_usuario;
}Post;

typedef struct
{
    Post *id_usuario;
    char nick[100];
    int seguidores;
}Usuario;

typedef struct
{
    Post *id_mensaje;
    Post *mensaje;
    Post *likes;
    Usuario *id_usuario;
    Usuario *seguidores;
}Feed;

int usuario_compare(void* pUsuarioA,void* pUsuarioB);
void Usuario_print(Usuario* this);
Usuario* usuario_new(void);
void usuario_delete(Usuario* this);
int usuario_setId(Usuario* this, int* id_usuario);
int* usuario_getId(Usuario* this);
int usuario_setnick(Usuario* this, char* nick);
char* usuario_getnick(Usuario* this);
int* usuario_getSeguidores(Usuario* this);
int usuario_setSeguidores(Usuario* this, int* seguidores);

void ordenar_numeros(int arreglo[], int lon);

//int usuario_compare(void* pUsuarioA,void* pUsuarioB);
void post_print(Post* this);
Post* post_new(void);
void post_delete(Post* this);
int post_setId(Post* this, int id_mensaje);
int post_getId(Post* this);
int post_setMensaje(Post* this, char* mensaje);
char* post_getMensaje(Post* this);
