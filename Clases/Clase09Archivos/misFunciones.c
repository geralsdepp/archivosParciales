#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"

/** \brief La función leerá un archivo de texto
 * \param fileName, puntero al nombre del archivo
 * \param array de la estructura
 * \param arrayLen
 * \return La función devolverá la cantidad de items que se cargaron en el array, y nunca se superará
 *         el tamaño del array.
 */

int loadDataFile(char fileName[], int arrayLen)
{
    FILE* pArchivo;
    s_Data* pData;
    int retorno = 1;
    int i,j;
    char aux;
    int contador = 0;
    char lineStr[50];

    pArchivo = fopen(fileName,"r");

    if(pArchivo == NULL)
    {
        perror("Error al abrir el archivo\n");
        retorno = -1;
    }

    while(!feof(pArchivo))
    {
        fgets(lineStr,50,pArchivo);
        contador++;
    }
    rewind(pArchivo); //pongo el cursor en el inicio de mi archivo para poder seguir trabajndo on el
    pData = (s_Data*)malloc(sizeof(s_Data)*contador); //reservo memoria para la estructura
    if(pData == NULL)
    {
        printf("No se ha podido reservar memroria!!\n");
        retorno = -1;
        exit(1);
    }

    for(i=0;!feof(pArchivo);i++)
    {
        vaciar(lineStr);
        aux = '0';

        for(j=0; aux != '=';j++)
        {
            aux = fgetc(pArchivo); //leemos caracter por caracter, mientras que el caracter sea distinto de '='
            if(aux != '=')
            {
                lineStr[j] = aux; //una vez que lo leyo y se cumplio la condicion, lo copia en mi string.
            }
        }
        //realizamos una funcion copiar para copiar la primera parte que se leyó en un campo de mi estructura.
        copiar(pData,lineStr,i);
        //una ves que se copio, el cursor esta parado despues del caracter '=', entonces utilizo:
        fgets(lineStr,20,pArchivo); //le paso mi string y que lea 20 caracteres mas hasta que encuentre un  salto de linea en mi acrhivo
        pData[i].value = lineStr; //copio lo leido  y lo guardo en mi estructura.
        printf("Key: %s -- Value: %s\n",pData[i].key,pData[i].value); //imprimo los valores que logre extraer del archivo y guardarlos en mi estructura
    fclose(pArchivo);
    return retorno;
}
void vaciar(char str[]) //vacío el string.
{
    int i;

    for(i=0;i<50;i++)
    {
        str[i] = '\0';
    }
}
void copiar(s_Data* pData,char str[],int i)
{
    int n = strlen(str) + 1;

    pData[i].key = (char*)malloc(sizeof(char)*n);
    pData[i].value = (char*)malloc(sizeof(char)*n);

    if(pData[i].key == NULL)
    {
        printf("No se ha podido reservar memoria!!\n");
        exit(1);
    }
    if(pData[i].value == NULL)
    {
        printf("No se ha podido reservar memoria!!\n");
        exit(1);
    }

    strcpy(pData[i].key,str);
    strcpy(pData[i].value,str);
}
