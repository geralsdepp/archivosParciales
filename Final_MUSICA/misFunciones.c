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

S_Escuchados* escuchados_new(void)
{
    S_Escuchados* returnAux = NULL;
    returnAux = (S_Escuchados*)malloc(sizeof(S_Escuchados));
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
    FILE* pFile;

    pFile = fopen("temas.dat","r");
    parserTema(pFile,lista_temas);

   listar_temas(lista_temas);
}

void imprimir(ArrayList* this, int estructura)
{
    S_Usuario* auxUsuario = NULL;
    S_Temas* auxTema = NULL;
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
            printf("\nidTema: %d | Nombre: %s | Artista: %s\n",temas_getId(auxTema),temas_getNombre(auxTema),temas_getArtista(auxTema));
        }
    }
}

void parserEmployee(FILE* pFile,ArrayList* lista_usuarios)
{
    char buffer[50], auxId[10], auxPassword[50],auxNombre[20], auxEmail[40], auxSexo[10], auxPais[5], auxip_address[25];
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
//    S_Usuario* auxTemp = NULL;

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
               /* auxTemp = auxUsuario;
                auxUsuario = auxUsuario1;
                auxUsuario1 = auxTemp;*/

                this->set(this,i,auxUsuario1);
                this->set(this,j,auxUsuario);

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

int compareArtista(void* pTemaA, void* pTemaB)
{
    int retorno;

    S_Temas* auxiliarA = (S_Temas*)pTemaA;
    S_Temas* auxiliarB = (S_Temas*)pTemaB;

    if(strcmp(auxiliarA->artista,auxiliarB->artista) < 0)
        retorno = 1;
    else if(strcmp(auxiliarA->artista,auxiliarB->artista) > 0)
        retorno = -1;
    else if(strcmp(auxiliarA->artista,auxiliarB->artista) == 0)
        retorno = 0;
    return retorno;
}

int compareNomTema(void* pTemaA, void* pTemaB)
{
    int retorno;

    S_Temas* auxiliarA = (S_Temas*)pTemaA;
    S_Temas* auxiliarB = (S_Temas*)pTemaB;

    if(strcmp(auxiliarA->nombre,auxiliarB->nombre) < 0)
        retorno = 1;
    else if(strcmp(auxiliarA->nombre,auxiliarB->nombre) > 0)
        retorno = -1;
    else  if(strcmp(auxiliarA->nombre,auxiliarB->nombre) == 0)
        retorno = 0;
    return retorno;
}

void listar_temas(ArrayList* this)
{
    int i,j;
    int longitud = this->len(this);

    S_Temas* auxTema1 = NULL;
    S_Temas* auxTema2 = NULL;

    al_sort(this,compareArtista,1);
//    imprimir(this,2);

    for(i=0; i<longitud - 1; i++)
    {
        for(j=i+1; j<longitud; j++)
        {
            auxTema1 = (S_Temas*)this->get(this,i);
            auxTema2 = (S_Temas*)this->get(this,j);

            if(compareNomTema(auxTema1,auxTema2) < 0 && compareArtista(auxTema1,auxTema2) == 0) //si son iguales
            {
               /* auxTemp = auxUsuario;
                auxUsuario = auxUsuario1;
                auxUsuario1 = auxTemp;*/

                this->set(this,i,auxTema2);
                this->set(this,j,auxTema1);
            }
        }
    }
    imprimir(this,2);
}

void escuchar_tema(ArrayList* lista_temas, ArrayList* lista_usuarios, ArrayList* lista_escuchados)
{
    int flag = 0,i,j,auxId;
    char auxNick[20], auxPassword[50];
    S_Usuario* auxUsuario = NULL;
    S_Temas* auxTema = NULL;
    S_Escuchados* auxEscuchados = NULL;


    int lengthUsuarios = lista_temas->len(lista_temas);
    int lenghtTemas = lista_usuarios->len(lista_usuarios);

    do
    {
        if(!getStringLetras("Ingrese nick: ",auxNick))
            printf("Reingrese Nick!!\n");
        else
        {
            printf("Ingrese password: ");
            fflush(stdin);
            scanf("%[^\n]",auxPassword);

            flag = 1;
            for(i = 0; i < lengthUsuarios; i++)
            {
                auxUsuario = (S_Usuario*)lista_usuarios->get(lista_usuarios,i);

                if(strcmp(auxNick,usuarios_getNombre(auxUsuario)) == 0 && strcmp(auxPassword,usuarios_getPassword(auxUsuario)) == 0)
                {
                    listar_temas(lista_temas);

                    auxId = obtenerInt("Ingrese id del tema que desea escuchar: ","El id debe existir","400","1");

                    for(j = 0; j<lenghtTemas; j++)
                    {
                        auxTema = (S_Temas*)lista_temas->get(lista_temas,j);

                        if(auxId == temas_getId(auxTema))
                        {
                            printf("REPRODUCIENDO...%d\n\n %s\n %s",temas_getId(auxTema),temas_getNombre(auxTema),temas_getArtista(auxTema));

                            auxEscuchados = escuchados_new();
                            escuchados_setIdUsuario(auxEscuchados, usuarios_getId(auxUsuario));
                            escuchados_setIdTema(auxEscuchados, temas_getId(auxTema));

                            al_add(lista_escuchados,(void*)auxEscuchados);
                            break;
                        }
                    }
                }
            }
        }
    }while(flag == 0);
}

void saveFile(ArrayList* lista_escuchados, ArrayList* lista_usuarios, ArrayList* lista_temas)
{
    S_Usuario* auxUsuario = NULL;
    S_Temas* auxTema = NULL;
    S_Escuchados* auxEscuchado = NULL;
    FILE *pArchivo = NULL;
    int i = 0, j, k, sizeUsuario, sizeTema, sizeEscuchado;

    sizeEscuchado = lista_escuchados->len(lista_escuchados);
    sizeUsuario = lista_usuarios->len(lista_usuarios);
    sizeTema = lista_temas->len(lista_temas);

    pArchivo = fopen("estadistica.dat", "w");

    if(pArchivo != NULL)
    {
        for(i=0; i<sizeEscuchado; i++) //recorro la lista de los temas escuchados
        {
            auxEscuchado = lista_escuchados->get(lista_escuchados, i);

            for(j=0; j<sizeUsuario; j++) //recorro la lista de usuarios
            {
                auxUsuario = lista_escuchados->get(lista_usuarios,j);
                if(escuchados_getIdUsuario(auxEscuchado) == usuarios_getId(auxUsuario))
                {
                    for(k=0; k<sizeTema; k++)
                    {
                        auxTema = lista_temas->get(lista_temas,k);
                        if(escuchados_getIdTema(auxEscuchado) == temas_getId(auxTema))
                        {
                            fprintf(pArchivo,"Escuchado por el usuario: %s\n  Tema: %s | Artista: %s\n",usuarios_getNombre(auxUsuario),temas_getNombre(auxTema),temas_getArtista(auxTema));
                            printf("Archivo escrito!!\n");
                        }
                    }
                }
            }
        }
        fclose(pArchivo);
        printf("Archivo guardado con exito\n\n");
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}


