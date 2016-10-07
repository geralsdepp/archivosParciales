#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#define PELICULAS 5
#define DIRECTORES 5
#define NACIONALIDADES 5

int main()
{

    int opcion = 0, ultimo_id = 0;
    char aux_Titulo[50], aux_Nacionalidad[50], aux_Director[50],aux_ID[3], aux_AnioSTR[4];
    int aux_Dia, aux_Mes;
    int  aux_Anio, LugarLibrePeli, LugarOcupadoPeli, LugarLibreDire, LugarOcupadoDire;
    int i, getNum;
    int flag = 0;

    datosPelicula arrayPeli[PELICULAS];
    datosDirector arrayDire[DIRECTORES];


    iniciarDatosArray(arrayPeli, PELICULAS, 0); ///**< Inicio los datos en 0 (VACIO) */

    while(opcion != 6)
    {

        opcion = getOpcion(opcion);

            switch(opcion)
            {
            case 1:
                LugarLibrePeli = buscarPrimerOcurrencia(arrayPeli, PELICULAS,-1);

                if(LugarLibrePeli == -1)
                {
                    printf("\n\nNO HAY MAS LUGARES LIBRES!!\n");
                    break;
                }

                printf("\nALTA\n");

                while(flag == 0 )
                {
                    if(!getStringLetras("Ingrese titulo: \n",aux_Titulo))
                    {
                       system("cls");
                       printf("El titulo debe estar compuesto por letras.\n");
                       system("cls");
                    }
                    else
                        flag = 1;
                }


               while(flag == 0)
               {
                   if(!getStringNumeros("Ingrese el anio: \n",aux_AnioSTR))
                   {
                     system("cls");
                     printf("El año debe ser numerico\n");
                     system("cls");
                     break;
                   }
                   else
                    flag = 1;

               }
               aux_Anio = atoi(aux_AnioSTR);

               while(flag == 0)
               {
                   if(!getStringLetras("Ingrese la Nacionalidad: \n",aux_Nacionalidad))
                   {
                     system("cls");
                     printf("La Nacionalidad debe contener solo letras!!\n");
                     system("cls");
                     break;
                   }
                   else
                    flag = 1;
               }

               while(flag == 0)
               {
                   if(!getStringLetras("Ingrese un Director para ésta película: \n",aux_Director))
                   {
                       system("cls");
                       printf("El Director debe contener solo letras!!\n");
                       system("cls");
                       break;
                   }
                   else
                    flag = 1;
               }

               strcpy(arrayPeli[LugarLibrePeli].titulo,aux_Titulo);
               strcpy(arrayPeli[LugarLibrePeli].nom.nombre,aux_Nacionalidad);
               strcpy(arrayPeli[LugarLibrePeli].direc.nombre,aux_Director);
               arrayPeli[LugarLibrePeli].anio = aux_Anio;
               arrayPeli[LugarLibrePeli].idEstado = 1;
               arrayPeli[LugarLibrePeli].idPelicula = ultimo_id + 1;
               ultimo_id = ultimo_id + 1;
               printf("PELICULA CARGADA\n");

             break;

            case 2:
                printf("MODIFICAR\n");
                while(flag == 0)
                {
                    if(!getStringNumeros("Ingrese el ID a modificar: ",aux_ID))
                    {
                       printf("El ID debe ser numerico!!\n");
                       break;
                    }
                    else
                        flag = 1;
                }

                LugarOcupadoPeli = buscarPrimerOcurrencia(arrayPeli, PELICULAS, getNum);// getNum es mi ID

                if(LugarOcupadoPeli == -1)
                {
                    printf("\n\n No se encuentra ese ID\n");
                    break;
                }
                if(!getStringLetras("Ingrese el titulo de la pelicula: ",aux_Titulo));
                {
                    printf("El titulo debe estar compuesto por letras!!\n");
                    break;
                }

                if(!getStringNumeros("Ingrese el anio: ",aux_AnioSTR))
                {
                    printf("Ingrese el anio de forma numerica!!\n");
                    break;
                }

                aux_Anio = atoi(aux_AnioSTR);

                if(!getStringLetras("Ingrese Nacionalidad: ",aux_Nacionalidad))
                {
                    printf("La nacionalidad debe estar compuesta por letras!!\n");
                    break;
                }
                if(!getStringLetras("Ingrese director: ",aux_Director))
                {
                    printf("El director ingresado no existe: ");
                }

                strcpy(arrayPeli[LugarOcupadoPeli].titulo,aux_Titulo);
                arrayPeli[LugarOcupadoPeli].anio = aux_Anio;
                strcpy(arrayPeli[LugarOcupadoPeli].nom.nombre,aux_Nacionalidad);
                strcpy(arrayPeli[LugarOcupadoPeli].direc.nombre,aux_Director);
                arrayPeli[LugarOcupadoPeli].idEstado = 1;
                break;

            case 3:
                printf("BORRAR\n");

                if(!getStringNumeros("Ingrese ID que desee borrar: ",aux_ID))
                {
                    printf("El ID ingresado debe ser numerico!!\n");
                    break;
                }

                getNum = atoi(aux_ID);

                LugarOcupadoPeli = buscarIdPeliculas(arrayPeli, PELICULAS, getNum);
                printf("%d",LugarOcupadoPeli);

                if(LugarOcupadoPeli == -1)
                {
                    printf("\n\nNo se encuentra el codigo\n");
                    break;
                }
                arrayPeli[LugarOcupadoPeli].idEstado = -1;

                break;
            case 4:
                printf("NUEVO DIRECTOR");
                    LugarLibreDire = buscarPrimerOcurrenciaDirectores(arrayDire, DIRECTORES, -1);

                   if(LugarLibreDire == -1)
                   {
                       printf("\n\nNO HAY MAS LUGARES LIBRES!!\n");
                   }
                   printf("\nALTA\n");

                   while(flag == 0)
                   {
                       if(!getStringLetras("Ingrese nombre del nuevo director: ",aux_Director))
                       {
                            printf("El titulo debe estar compuesto por letras.\n");
                            break;
                       }
                   }


                   while(flag == 0)
                   {
                       if(!getStringNumerosFlotantes("Ingrese dia de nacimiento: ",aux_Dia));
                       {
                            printf("El dia debe ser numerico\n");
                            break;
                       }
                       else
                        flag = 1;
                   }
                   while(flag == 0)
                   {
                        if(!getStringNumerosFlotantes("Ingrese mes de nacimiento: ",aux_Mes);
                        {
                           printf("El mes debe ser numerico\n");
                           break;
                        }
                        else
                            flag = 1;
                   }

                   if(!getStringNumerosFlotantes("Ingrese anio de nacimiento: ");
                   {
                       printf("El anio debe ser numerico\n",aux_Anio);
                       break;
                   }

                   strcpy(arrayDire[LugarLibreDire].nombre,aux_Director);
                   strcpy(arrayDire[LugarLibreDire].nom.nombre,aux_Nacionalidad);
                   arrayDire[LugarLibreDire].DD.dia = aux_Dia;
                   arrayDire[LugarLibreDire].MM.mes = aux_Mes;
                   arrayDire[LugarLibreDire].AA.anio = aux_Anio;
                   arrayDire[LugarLibreDire].idEstado = 1;
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("LISTAR");
                for(i = 0; i < PELICULAS; i++)
                {
                   if(arrayPeli[i].idEstado == -1)
                   {
                       printf("\n%d---%s---%d---%s---%s",arrayPeli[i].idPelicula, arrayPeli[i].titulo, arrayPeli[i].anio, arrayPeli[i].direc, arrayPeli[i].nom);
                   }
                }
                break;

        }

    }

    return 0;
}
