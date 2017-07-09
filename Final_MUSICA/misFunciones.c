#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"
#include "setsGets.h"
#include "ArrayList.h"
#include "string.h"

int menuOpcion()
{
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.LISTAR USUARIOS.\n");
    printf("2.LISTAR TEMAS.\n");
    printf("3.ESCUCHAR TEMA.\n");
    printf("4.GUARDAR ESTADISTICA\n");
    printf("5.INFORMAR\n");
    printf("6.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

S_Usuario* usuarios_new(void)
{
    S_Usuario* returnAux = NULL;
    returnAux = (S_Usuario*)malloc(sizeof(S_Usuario));
    return returnAux;
}

S_Temas* temas_new(void)
{
    S_Temas* returnAux = NULL;
    returnAux = (S_Temas*)malloc(sizeof(S_Temas));
    return returnAux;
}

S_Feed* feed_new(void)
{
    S_Feed* returnAux = NULL;
    returnAux = (S_Feed*)malloc(sizeof(S_Feed));
    return returnAux;
}

ArrayList* inicializar_lista(ArrayList* lista)
{
    lista = (ArrayList*)calloc(lista->reservedSize,sizeof(ArrayList));
    return lista;
}


void cargar_usuarios(ArrayList* lista_usuarios)
{
    int opcion;
    char seguir = 's';
    FILE* pFile;

    pFile = fopen("usuarios.dat","r");
    parserEmployee(pFile,lista_usuarios);

    do
    {
        printf("Menu:\n1.LISTAR POR NOMBRE\n2.LISTAR POR NACIONALIDAD Y POR NOMBRE\n3.ATRAS");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                al_sort(lista_usuarios,compareNom,1);
                imprimir(lista_usuarios,1); //imprimo los usuarios ordenados
                break;
            case 2:
                listar_NombreyNac(lista_usuarios);
                break;
            case 3:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }while(seguir =='s');
}

void cargar_temas(ArrayList* lista_temas)
{
   // S_Post* auxMensajes = NULL;
   // auxMensajes = mensajes_new();
    FILE* pFile;

    pFile = fopen("temas.dat","r");
    parserTema(pFile,lista_temas);
  //  imprimir(lista_temas,2);
   // al_add(this,(void*)auxMensajes);
}

void imprimir(ArrayList* this, int estructura)
{
    S_Usuario* auxUsuario = NULL;
    S_Temas* auxTema = NULL;
    S_Feed* auxFeed = NULL;
    int j,longitud;
    longitud = this->len(this);

    if(estructura == 1)
    {
        for(j=0; j<longitud-1;j++)
        {
            auxUsuario = (S_Usuario*)this->get(this,j);
            printf("\nidUsuario: %d | nombre: %s | email: %s | sexo: %s | pais: %s | password: %s | ip addres: %s\n",usuarios_getId(auxUsuario),usuarios_getNombre(auxUsuario),usuarios_getEmail(auxUsuario),usuarios_getSexo(auxUsuario),usuarios_getPais(auxUsuario),usuarios_getPassword(auxUsuario),usuarios_getIpAddress(auxUsuario));
        }
    }
    else if(estructura == 2)
    {
        for(j=0; j<longitud-1;j++)
        {
            auxTema = (S_Temas*)this->get(this,j);
            printf("idTema: %d | Nombre: %s | Artista: %s\n",temas_getId(auxTema),temas_getNombre(auxTema),temas_getArtista(auxTema));
        }
    }
    else if(estructura == 3)
    {
        for(j=0; j<longitud;j++)
        {
            auxFeed = (S_Feed*)this->get(this,j);
            printf("Nick: %s --> seguidores: %d\n  Mensaje: %s --> likes: %d\n",auxFeed->nick,auxFeed->seguidores,auxFeed->mensaje,auxFeed->likes);
        }
    }
    system("pause");
}

void parserEmployee(FILE* pFile,ArrayList* lista_usuarios)
{
    char buffer[50], auxId[10], auxPassword[40],auxNombre[20], auxEmail[40], auxSexo[10], auxPais[5], auxip_address[25];
    S_Usuario* auxUsuario = NULL;

    if(pFile!=NULL && lista_usuarios != NULL)
    {
        fgets(buffer,50,pFile);
        while(!feof(pFile))
        {
            auxUsuario = usuarios_new(); //asigno memoria por cada empleado
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",auxId,auxNombre,auxEmail,auxSexo,auxPais,auxPassword,auxip_address);
            usuarios_setId(auxUsuario,atoi(auxId));
            usuarios_setNombre(auxUsuario,auxNombre);
            usuarios_setEmail(auxUsuario,auxEmail);
            usuarios_setSexo(auxUsuario,auxSexo);
            usuarios_setPais(auxUsuario,auxPais);
            usuarios_setPassword(auxUsuario,auxPassword);
            usuarios_setIpAddress(auxUsuario,auxip_address);

            al_add(lista_usuarios, (void*)auxUsuario);
        }
        fclose(pFile);
    }
}

void parserTema(FILE* pFile, ArrayList* lista_temas)
{
    S_Temas* auxTema = NULL;
    char buffer[50], auxIdTema[10],auxNombre[40],auxArtista[50];

    if(pFile != NULL && lista_temas != NULL)
    {
        fgets(buffer,50,pFile);
        while(!feof(pFile))
        {
            auxTema = temas_new();
            fscanf(pFile,"%[^,],%[^,],%[^\n]",auxIdTema,auxNombre,auxArtista);
            temas_setId(auxTema,atoi(auxIdTema));
            temas_setNombre(auxTema,auxNombre);
            temas_setArtista(auxTema,auxArtista);
            al_add(lista_temas, (void*)auxTema);
        }
        fclose(pFile);
    }
}

void listar_NombreyNac(ArrayList* this)
{
    int i,j;
    int longitudUsuarios = this->len(this);

    S_Usuario* auxUsuario = NULL;
    S_Usuario* auxUsuario1 = NULL;
    S_Usuario* auxTemp = NULL;

    al_sort(this,compareNac,1);
    printf("ordeno por nombre\n");

    for(i=0; i<longitudUsuarios - 1; i++)
    {
        for(j=i+1; j<longitudUsuarios; j++)
        {
            auxUsuario = (S_Usuario*)this->get(this,i);
            auxUsuario1 = (S_Usuario*)this->get(this,j);

            if(compareNom(auxUsuario,auxUsuario1) < 0 && compareNac(auxUsuario,auxUsuario1) == 0) //si son iguales
            {
                //al_sort(this,compareNac,1);
               /* auxTemp = auxUsuario;
                auxUsuario = auxUsuario1;
                auxUsuario1 = auxTemp;*/

            (S_Usuario*)this->set(this,i,auxUsuario1);
            (S_Usuario*)this->set(this,j,auxUsuario);

            }
        }
    }
    imprimir(this,1);
}

int compareNom(void* pUsuarioA, void* pUsuarioB)
{
    int retorno;

    S_Usuario* auxiliarA = (S_Usuario*)pUsuarioA;
    S_Usuario* auxiliarB = (S_Usuario*)pUsuarioB;

    if(pUsuarioA != NULL && pUsuarioB != NULL)
    {
        if(strcmp(auxiliarA->nombre,auxiliarB->nombre) < 0)
            retorno = 1;
        else if(strcmp(auxiliarA->nombre,auxiliarB->nombre) > 0)
            retorno = -1;
        else if(strcmp(auxiliarA->nombre,auxiliarB->nombre) == 0)
            retorno = 0;
    }
    return retorno;
}

int compareNac(void* pUsuarioA, void* pUsuarioB)
{
    int retorno;

    S_Usuario* auxiliarA = (S_Usuario*)pUsuarioA;
    S_Usuario* auxiliarB = (S_Usuario*)pUsuarioB;

    if(pUsuarioA != NULL && pUsuarioB != NULL)
    {
        if(strcmp(auxiliarA->pais,auxiliarB->pais) < 0)
            retorno = 1;
        else if(strcmp(auxiliarA->pais,auxiliarB->pais) > 0)
            retorno = -1;
        else if(strcmp(auxiliarA->pais,auxiliarB->pais) == 0)
            retorno = 0;
    }
    return retorno;
}

/*int compareInt(void* pUsuarioA,void* pUsuarioB)
{
    int retorno;

    S_Temas* auxiliarA = (S_Temas*)pUsuarioA;
    S_Temas* auxiliarB = (S_Temas*)pUsuarioB;

    if(auxiliarA->seguidores < auxiliarB->seguidores)
        retorno = 1;
    else if(auxiliarA->seguidores > auxiliarB->seguidores)
        retorno = -1;
    else if(auxiliarA->seguidores == auxiliarB->seguidores)
        retorno = 0;

    return retorno;
}*/

void saveFile(ArrayList* this)
{
    S_Feed* auxFeed = NULL;
    auxFeed = feed_new();
    FILE *pArchivo;
    int i = 0, cantidad;
    pArchivo = fopen("feed.csv", "w");
    if(pArchivo != NULL)
    {
        if (auxFeed != NULL)
        {
            cantidad = this->len(this);
            for(i=0; i<cantidad; i++)
            {
                auxFeed = this->get(this, i);
                fwrite((S_Feed*)this->get(this, i), sizeof(S_Feed),1,pArchivo);

            }
            fclose(pArchivo);
            printf("Archivo guardado con exito\n\n");
        }
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}

void al_swap(void* pUsuarioA, void* pUsuarioB, ArrayList* this)
{
    S_Usuario* auxiliarA = (S_Usuario*)pUsuarioA;
    S_Usuario* auxiliarB = (S_Usuario*)pUsuarioB;
    S_Usuario* auxiliarC;

    auxiliarC = auxiliarA;
    auxiliarA = auxiliarB;
    auxiliarB = auxiliarC;
}
