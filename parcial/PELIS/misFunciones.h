typedef struct
{
    char nombre[50];

}datosNacionalidad;

typedef struct
{
    int anio;
    int mes;
    int dia;

}datosFecha;
typedef struct
{
    int idDirector;
    char nombre[50];
    char idEstado;
    datosNacionalidad nom;
    datosFecha DD;
    datosFecha MM;
    datosFecha AA;

}datosDirector;
typedef struct
{
    int idPelicula;
    char titulo[255];
    datosDirector direc;
    datosNacionalidad nom;
    int anio;
    char idEstado;

}datosPelicula;





//void menuOpcion(int);
//void cargarPersonas(Persona arrayPersonas[],int cantElement,int valor);
void iniciarDatosArray(datosPelicula arrayPeli[], int cantElementos, int valor);
int buscarPrimerOcurrencia(datosPelicula arrayPeliculas[],int cantElementos, int valor);
void estado(datosPelicula arrayPeliculas[], int cantElementos,int valor);
int buscarIdPeliculas(datosPelicula arrayPeliculas[], int cantElementos,int code);

int buscarLugarVacioDirector(datosDirector arrayDirector[],int cantElement);
void iniciarDatosArrayDirector(datosDirector arrayDirector[], int cantElementos,int valor);
int buscarIdDirectores(datosDirector arrayDirector[], int cantElementos,int code);

/*************************************************************************/
int getOpcion(int opc);
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

void cargar(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);


