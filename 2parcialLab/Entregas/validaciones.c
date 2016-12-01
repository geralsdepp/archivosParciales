#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

int getOpcion(int opc)
{
    char aux_op[255];
    int op;
    printf("1.Entrega URGENTE.\n2.Entrega REGULAR\n3.Proxima ENTREGA\n4.Listar\n.5Informar\n6.Salir\n");
    if(!getInt("Ingrese una opcion: \n", aux_op))
    {
        printf("Debe ingresar un  numero!!");
    }
    op = atoi(aux_op);
    return op;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[], char buffer[])
{
    int retorno=0;
    char seguir='s';

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        gets(buffer);

        if(esNumerico(buffer))
        {
            retorno = 1;
            seguir = 'n';
        }
        else
        {
            printf("Dato ingresado no es numerico. Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }
    }while(seguir=='s');
    return retorno;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

///**
// * \brief Genera un número aleatorio
// * \param desde Número aleatorio mínimo
// * \param hasta Número aleatorio máximo
// * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
// * \return retorna el número aleatorio generado
// *
// */
//char getNumeroAleatorio(int desde , int hasta, int iniciar)
//{
//    if(iniciar)
//        rand (time(NULL));
//    return desde + (rand() % (hasta + 1 - desde)) ;
//}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i = 0;
   char letra;
   int retorno = 1;

   while(str[i] != 0)
   {
       letra = str[i];
       if(isalpha(letra) != 0 || letra == ' ')
       {
           i++;
           continue;
       }
       else
       {
           retorno = 0;
           break;
       }
   }
   return retorno;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;

       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
int getString(char mensaje[],char input[], int longitud)
{
    char seguir = 's';
    int retorno = 0;
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(input);
        if(verificarRangoChar(input,longitud))
        {
            retorno = 1;
             seguir = 'n';
        }
        else
        {
            printf("Dato ingresado muy extenso. Desea continuar?s/n: ");
            fflush(stdin);
            scanf("%c",&seguir);
        }

    }while(seguir=='s');

    return retorno;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[],int longitud)
{
    int retorno = 0;
    char seguir = 's';

    do
    {
        if(getString(mensaje, input, longitud))
        {
            if(esSoloLetras(input))
            {
                retorno = 1;
                seguir = 'n';
            }
            else
            {
                printf("Deben ser solo letras. Desea continuar? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            seguir = 'n';
        }
    }while(seguir == 's');

    return retorno;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char seguir = 's';
    int retorno = 0;

    do
    {
        if(getInt(mensaje, input))
        {
            if(esNumerico(input))
            {
                retorno = 1;
                seguir = 'n';
            }
            else
            {
                printf("Deben ser solo numeros!! Desea continuar? s/n: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
        }
        else
        {
            seguir = 'n';
        }
    }while(seguir=='s');

    return retorno;
}

int verificarRangoChar(char buffer[], int longitud)
{
    int retorno = 0;
    if(strlen(buffer)<=longitud)
    {
        retorno = 1;
    }
    return retorno;
}
