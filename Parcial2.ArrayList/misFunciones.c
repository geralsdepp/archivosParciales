#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#include "ArrayList.h"
#include "misSetsyGets.h"
#include "misValidaciones.h"

int cantidadVendida=0;

/** \brief despliega un menu de opciones
 *
 * \return retorna la opcion ingresada
 *
 */

int menuOpcion(void)
{
    int opcion;
    printf("MENU DE OPCIONES:\n");
    printf("1.ALTA USUARIO.\n");
    printf("2.MODIFICAR DATOS DE USUARIO.\n");
    printf("3.BAJA DE USUARIO.\n");
    printf("4.PUBLICAR PRODUCTO\n");
    printf("5.MODIFICAR PUBLICACION\n");
    printf("6.CANCELAR PUBLICACION\n");
    printf("7.COMPRAR PRODUCTO\n");
    printf("8.LISTAR PUBLICACIONES DE USUARIO\n");
    printf("9.LISTAR PUBLICACIONES\n");
    printf("10.LISTAR USUARIOS\n");
    printf("11.SALIR\n");
    printf("Eliga una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

S_Usuario* usuarios_new()
{
    S_Usuario* returnAux = NULL;
    returnAux = (S_Usuario*)malloc(sizeof(S_Usuario));
    return returnAux;
}
S_Producto* productos_new()
{
    S_Producto* returnAux = NULL;
    returnAux = (S_Producto*)malloc(sizeof(S_Producto));
    return returnAux;
}
S_Calificacion* puntuacion_new()
{
    S_Calificacion* returnAux = NULL;
    returnAux = (S_Calificacion*)malloc(sizeof(S_Calificacion));
    return returnAux;
}

ArrayList* inicializar_lista(ArrayList* lista)
{
    lista = (ArrayList*)calloc(lista->reservedSize,sizeof(ArrayList));
    return lista;
}

int get_nextID(ArrayList* this,int estructura)
{
    int i;
    int indiceMaximo = 0;

    S_Usuario* auxUsuario = NULL;
    auxUsuario = usuarios_new();
    S_Producto* auxProducto = NULL;
    auxProducto = productos_new();
    S_Calificacion* auxCalif = NULL;
    auxCalif = puntuacion_new();

    if(this != NULL)
    {
        if(estructura == 1 && auxUsuario != NULL)
        {
            for(i=0; i<this->len(this); i++) //si i es menor al tamaño del arraylist
            {
               auxUsuario = this->get(this,i); //obtengo el puntero del indice "i"
               if(auxUsuario->idUsuario > indiceMaximo)
               {
                   indiceMaximo = auxUsuario->idUsuario;
               }
            }
        }
        else if(estructura == 2 && auxProducto != NULL)
        {
            for(i=0; i<this->len(this); i++) //si i es menor al tamaño del arraylist
            {
               auxProducto = this->get(this,i); //obtengo el puntero del indice "i"
               if(auxProducto->idProducto > indiceMaximo)
               {
                   indiceMaximo = auxProducto->idProducto;
               }
            }
        }
        else if(estructura == 3 && auxCalif != NULL)
        {
            for(i=0; i<this->len(this); i++) //si i es menor al tamaño del arraylist
            {
               auxCalif = this->get(this,i); //obtengo el puntero del indice "i"
               if(auxCalif->idPuntuacion > indiceMaximo)
               {
                   indiceMaximo = auxCalif->idPuntuacion;
               }
            }
        }
    }
    return indiceMaximo+1;
}

void alta_usuario(ArrayList* this)
{
    int flag = 0,id;
    char nombre[30], password[10];

    S_Usuario* auxUsuario = NULL;
    auxUsuario = usuarios_new();

    id = get_nextID(this,1);
    printf("El id disponible es: %d\n",id);

    do
    {
        if(!getStringLetras("Ingrese nombre: ",nombre))
        {
            printf("Reingrese!!\n");
        }
        else
            flag = 1;
    }while(flag == 0);
    flag = 0;
    do
    {
            getString("Ingrese password: ",password);
            if(!alfanumerico(password))
                printf("La password solo puede contener letras y numeros!!\n");
            else
                flag = 1;
    }while(flag == 0);

    usuarios_setName(auxUsuario,nombre);
    usuarios_setPassword(auxUsuario,password);
    usuarios_setId(auxUsuario,id);
    this->add(this,auxUsuario);
}

void modificar_usuario(ArrayList* this)
{
    int flag = 0,idU,index;
    char id_str[5];
    char nombre[30], password[10];
    S_Usuario* auxUsuario = NULL;

    if(this != NULL)
    {
        if(!getStringNumeros("Ingrese id a modificar: ",id_str))
        {
            printf("El id ser numerico!!");
        }
        else
        {
            idU = atoi(id_str);
            index = idU-1;

            if(this->contains(this,this->get(this,index)) == 1)
            {
                do
                {
                    if(!getStringLetras("Ingrese nombre: ",nombre))
                    {
                        printf("El nombre debe contener letras!!\n");
                    }
                    else
                        flag = 1;
                }while(flag == 0);
                flag = 0;
                do
                {
                    getString("Ingrese password: ",password);
                    if(!alfanumerico(password))
                    {
                        printf("La password solo puede contener letras y numeros!!\n");
                    }
                    else
                    {
                        flag = 1;
                        usuarios_setName(auxUsuario,nombre);
                        usuarios_setPassword(auxUsuario,password);
                        usuarios_setId(auxUsuario,idU);
                        this->set(this,index,auxUsuario);
                        printf("Materia modificada con exito!!\n");
                        break;
                    }
                }while(flag == 0);
            }
            else
                printf("\nEl id ingresado no exite!!\n");
        }
    }
    else
        printf("\nNo hay espacio suficiente en memoria\n");
}

void baja_usuario(ArrayList* this)
{
    int idU,index;
    char id_str[5];
    S_Usuario* auxUsuario = NULL;

    if(this != NULL)
    {
        if(!getStringNumeros("Ingrese el id de usuario a dar de baja: ",id_str))
        {
            printf("El id debe ser numerico!!");
        }
        else
        {
            idU = atoi(id_str);
            index = idU -1;

            if(this->contains(this,this->get(this,index)) == 1)
            {
                auxUsuario = this->pop(this,index); //POP BORRA UN ELEMENTO DEL ARRAYLIST
                printf("El siguiente usuario fue eliminado de la lista!!\n");
                printf("id: %d | Nombre: %s | Password: %s",auxUsuario->idUsuario,auxUsuario->nombre,auxUsuario->password);
            }
            else
            {
                printf("El id ingresado no existe!!\n");
                system("pause");
            }
        }
    }
}

void publicar_producto(ArrayList* this,ArrayList* lista_productos)
{
    int flag = 0;
    int precio, stock,idU,index,idP;
    char nombre[30],precio_str[5],stock_str[10],id_str[5];
    S_Producto* auxProducto = productos_new();

    if(!getStringNumeros("Ingrese id del usuario: ",id_str))
    {
        printf("El id debe contener numeros!!");
    }
    else
    {
        idU = atoi(id_str);
        index = idU-1;

        if(this->contains(this,this->get(this,index)) == 1)
        {
            idP = get_nextID(lista_productos,2); //obtengo el idP
            printf("El proximo idP es: %d\n",idP);

            do
            {
                if(!getStringLetras("Ingrese nombre de producto: ",nombre))
                {
                    printf("Reingrese!!\n");
                }
                else
                    flag = 1;

            }while(flag == 0);
            flag = 0;
            do
            {
                if(!getStringNumeros("Ingrese precio: ",precio_str))
                {
                    printf("Reingrese!\n");
                }
                else
                    flag = 1;
            }while(flag == 0);
            flag = 0;
            do
            {
                if(!getStringNumeros("Ingrese numero de stock: ",stock_str))
                {
                    printf("Reingrese!\n");
                }
                else
                {
                    flag = 1;
                    precio = atoi(precio_str);
                    stock = atoi(stock_str);
                }
            }while(flag == 0);

            producto_setName(auxProducto,nombre);
            producto_setPrecio(auxProducto,precio);
            producto_setStock(auxProducto,stock);
            producto_setIdProducto(auxProducto,idP);
            producto_setIdUsuario(auxProducto,idU);
            producto_setCantidadVendida(auxProducto,0);
            lista_productos->add(lista_productos,auxProducto);
        }
    }
}

void modificar_publicacion(ArrayList* this,ArrayList* lista_productos)
{
    int idP,idU,precio,stock,index,indexp;
    int flag = 0,i;
    char id_str[5],precio_str[5],stock_str[5];
    S_Producto* auxProducto = NULL;

    if(!getStringNumeros("Ingrese id del usuario: ",id_str))
    {
        printf("El id debe ser numerico!!\n");
    }
    else
    {
        flag = 1;
        idU = atoi(id_str);
        index = idU -1;

        if(this->contains(this,this->get(this,index)) == 1 && lista_productos->contains(lista_productos,lista_productos->get(lista_productos,index)) == 1)
        {
            for(i=0; i<lista_productos->len(lista_productos); i++)
            {
                auxProducto = (S_Producto*)lista_productos->get(lista_productos,i);
                printf("Campos del producto:\n");
                printf("id: %d\n",auxProducto->idProducto);
                printf("  Nombre: %s\n",auxProducto->nombre);
                printf("  Precio: %d\n",auxProducto->precio);
                printf("  Cantidad vendida: %d\n",auxProducto->cantidadVendida);
                printf("  Stock: %d\n",auxProducto->stock);
            }
        }
        else
            printf("No se encuentra el id ingresado\n");
        flag = 0;

        //recorro id de productos

        if(!getStringNumeros("Ingrese id del producto: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idP = atoi(id_str);
            indexp = idP -1;

            if(lista_productos->contains(lista_productos,lista_productos->get(lista_productos,indexp))==1)
            {
                 while(flag == 1)
                 {
                     if(!getStringNumeros("Ingrese nuevo precio: ",precio_str))
                     {
                        printf("Reingrese!\n");
                     }
                     else
                        flag = 0;
                 }
                 flag = 1;
                 while(flag == 1)
                 {
                     if(!getStringNumeros("Ingrese nuevo numero de stock: ",stock_str))
                     {
                         printf("Reingrese!\n");
                     }
                     else
                     {
                         flag = 0;
                         precio = atoi(precio_str);
                         stock = atoi(stock_str);

                         producto_setPrecio(auxProducto,precio);
                         producto_setStock(auxProducto,stock);
                         lista_productos->set(lista_productos,idP,auxProducto);
                         break;
                     }
                 }
            }
            else
            {
                printf("El id de producto no existe!!");
            }
        }
    }
}

void cancelar_publicacion(ArrayList* this, ArrayList* lista_productos)
{
    char id_str[5];
    int idU,idP,index,indexP,i;
    int flag = 0;
    S_Producto* auxProducto = NULL;

    if(!getStringNumeros("Ingrese id del usuario: ",id_str))
    {
        printf("El id debe ser numerico!!\n");
    }
    else
    {
        flag = 1;
        idU = atoi(id_str);
        index = idU -1;

        if(this->contains(this,this->get(this,index))==1) //busco si contiene el id del usuario
        {
            for(i=0; i<lista_productos->len(lista_productos);i++)
            {
                auxProducto = (S_Producto*)lista_productos->get(lista_productos,i);
                printf("Campos del producto: \n");
                printf("id: %d\n",auxProducto->idProducto);
                printf("  Nombre: %s\n",auxProducto->nombre);
                printf("  Precio: %d\n",auxProducto->precio);
                printf("  Cantidad vendida: %d\n",auxProducto->cantidadVendida);
                printf("  Stock: %d\n",auxProducto->stock);
            }
        }
        else
        {
            printf("No se encuentra el id ingresado\n");
        }
        flag = 0;
        //recorro id de productos
        do
        {
            if(!getStringNumeros("Ingrese id del producto que desea cancelar: ",id_str))
            {
                printf("El id debe ser numerico!!\n");
            }
            else
            {
                flag = 1;
                idP = atoi(id_str);
                indexP = idP -1;

                if(lista_productos->contains(lista_productos,lista_productos->get(lista_productos,indexP))==1)
                {
                    auxProducto = lista_productos->pop(lista_productos,indexP);
                    printf("El siguiente producto ha sido borrado:\n idP: %d| nombre: %s | precio: %d | stock: %d | cantidad vendida: %d\n",producto_getId(auxProducto),producto_getName(auxProducto),producto_getPrecio(auxProducto),producto_getStock(auxProducto),producto_getCantidadVendida(auxProducto));
                }
                else
                {
                    printf("El id no existe!!");
                }
            }
        }while(flag == 0);
    }
}

void comprar_producto(ArrayList* this,ArrayList* lista_calif)
{
    char id_str[5],calificacion_str[5];
    int idC,idP,calificacion,flag = 0,indexP;

    S_Calificacion* auxCalif = puntuacion_new();
   // S_Usuario* auxUsuario = usuarios_new();
    S_Producto* auxProducto = NULL;
    int auxStock = 0,i;

    if(!getStringNumeros("Ingrese id del producto que desea comprar: ",id_str))
    {
        printf("El id debe ser numerico!!\n");
    }
    else
    {
        flag = 1;
        idP = atoi(id_str);
        indexP = idP -1;
        idC = get_nextID(lista_calif,3);
        printf("Proximo idC: %d\n",idC);

        if(this->contains(this,this->get(this,indexP))==1)
        {
            while(flag == 1)
            {
                if(!getStringNumeros("Ingrese calificacion para el vendedor: ",calificacion_str))
                {
                    printf("Debe ser numerico!!\n");
                }
                else
                {
                    flag = 0;
                    calificacion = atoi(calificacion_str);
                    for(i=0; i<this->len(this); i++)
                    {
                        auxProducto = this->get(this,indexP);

                        if(auxProducto->idUsuario == i)
                        {
                            puntuacion_setIdPuntuacion(auxCalif,idC);
                            puntuacion_setPuntuacion(auxCalif,calificacion);
                            puntuacion_setIdUsuario(auxCalif,producto_getIdUsuario(auxProducto)); //no me copia el usuario
                            auxStock = producto_getStock(auxProducto);
                            auxStock = auxStock -1;
                            producto_setStock(auxProducto,auxStock);

                            producto_setCantidadVendida(auxProducto,cantidadVendida+1);

                            lista_calif->add(lista_calif,auxCalif);
                            break;
                        }

                    }

                }
            }
        }
        else
        {
            printf("El id no existe!!");
        }
    }
}

void listar_public_usuario(ArrayList* lista_usuarios, ArrayList* lista_productos)
{
    char id_str[5];
    int idU,i;
    int flag = 0;
    S_Producto* auxProducto = NULL;

    do
    {
        if(!getStringNumeros("Ingrese id del usuario: ",id_str))
        {
            printf("El id debe ser numerico!!\n");
        }
        else
        {
            flag = 1;
            idU = atoi(id_str);
            int indexU = idU - 1;
            int longitud = lista_productos->len(lista_productos);

            if(lista_usuarios->contains(lista_usuarios,lista_usuarios->get(lista_usuarios,indexU)) == 1)
            {
                for(i=0;i<longitud;i++)
                {
                    auxProducto = lista_productos->get(lista_productos,i);
                    if(producto_getIdUsuario(auxProducto) == idU)
                    {
                        printf("Campos del producto:\n\n");
                        printf("id: %d\n", producto_getId(auxProducto));
                        printf("  Nombre: %s\n",producto_getName(auxProducto));
                        printf("  Precio: %d\n",producto_getPrecio(auxProducto));
                        printf("  Cantidad vendida: %d\n",producto_getCantidadVendida(auxProducto));
                        printf("  Stock: %d\n",producto_getStock(auxProducto));
                    }
                }
                system("pause");
                system("cls");
            }
            else
            {
                printf("No se encuentra el id ingresado\n");
                break;
            }

        }
    }while(flag == 0);
}

void listar_public(ArrayList* lista_productos,ArrayList* lista_usuarios)
{
    S_Producto* auxProducto = NULL;
    S_Usuario* auxUsuario = NULL;

    int i,j,longitud,longitudUsuarios;
    longitud = lista_productos->len(lista_productos);
    longitudUsuarios = lista_usuarios->len(lista_usuarios);
    for(j=0; j<longitudUsuarios;j++)
    {
        for(i=0; i<longitud;i++)
        {
            auxProducto = (S_Producto*)lista_productos->get(lista_productos,i);

            printf("ID: %d\n",producto_getId(auxProducto));
            printf("  Nombre: %s\n",producto_getName(auxProducto));
            printf("  Precio: %d\n",producto_getPrecio(auxProducto));
            printf("  Cantidad Vendida: %d\n",producto_getCantidadVendida(auxProducto));
            printf("  Stock: %d\n",producto_getStock(auxProducto));
            if(producto_getIdUsuario(auxProducto) == usuarios_getId(auxUsuario))
            {
                auxUsuario = (S_Usuario*)lista_usuarios->get(lista_usuarios,j);
                printf("  Nombre de usuario: %s\n",usuarios_getName(auxUsuario));
            }
        }
    }
    system("pause");
}

void listar_usuario(ArrayList* lista_usuarios, ArrayList* lista_calif)
{
    int i;
    float prom = 0;
    S_Usuario* auxUsuario = NULL;
    S_Calificacion* auxCalif = NULL;
    int longUsuario = lista_usuarios->len(lista_usuarios);

    for(i=0; i<longUsuario; i++)
    {
        if(lista_usuarios->contains(lista_usuarios,lista_usuarios->get(lista_usuarios,i))==1)
        {
            auxCalif = lista_calif->get(lista_calif,i);
            auxUsuario = lista_usuarios->get(lista_usuarios,i);
            if(puntuacion_getIdUsuario(auxCalif) == i)
            {
                prom = promedio(lista_calif,auxCalif,i);
                printf("id: %d",usuarios_getId(auxUsuario));
                printf("  Nombre: %s",usuarios_getName(auxUsuario));
                printf("  Password: %s",usuarios_getPassword(auxUsuario));
                printf("  Calificacion promedio: %.2f",prom);
            }

        }else printf("error");
    }
}

float promedio(ArrayList* this,S_Calificacion* auxCalif, int i) //tengo que calcular el promedio de cada usuario
{
    float retornoPromedio;
    int suma=0;
    int longitudCalif = this->len(this);
    int j;

    for(j=0; j<longitudCalif;j++)
    {
        if(this->contains(this,this->get(this,j))==1) //busca en la lista si contiene el idCalif NO ENTRA EN EL IF
        {
            auxCalif = (S_Calificacion*)this->get(this,j);
            if(puntuacion_getIdCalif(auxCalif) == j && puntuacion_getIdUsuario(auxCalif) == i)
            {
                suma = suma + puntuacion_getPuntuacion(auxCalif);
            }
        }
        else
            printf("error!!");
    }
    retornoPromedio = suma/longitudCalif;

    return retornoPromedio;
}

S_Producto* findIdProducto(ArrayList* this, int idP)
{
    S_Producto* auxProducto = NULL;
    int i,exist = -1;
    if(this != NULL)
    {
        for(i=0; i<this->len(this);i++)
        {
            auxProducto = this->get(this,i);
            if(producto_getIdUsuario(auxProducto) == idP)
            {
                exist = 0;
                break;
            }
        }
        if(exist!=0)
        {
            auxProducto = NULL;
        }
    }
    return auxProducto;
}

//sabri

/*
void controller_saveFile(ArrayList* this)
{
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    FILE *f;
    int i = 0, cantidad;
    f = fopen("Materias.dat", "wb");
    if(f != NULL)
    {
        if (auxMateria != NULL)
        {
            cantidad = this->len(this);
            for(i=0; i<cantidad; i++)
            {
                auxMateria = this->get(this, i);
                fwrite((Materias*)this->get(this, i), sizeof(Materias),1,f);

            }
            fclose(f);
            printf("Archivo guardado con exito\n\n");
        }
    }
    else
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }
}


void controller_getFile(ArrayList* this)
{
    FILE* f;
    Materias* auxMateria = NULL;
    auxMateria = materias_new();
    f = fopen("Materias.dat", "rb");
    int cantidad = 0, cantTotal=0;
    if(f != NULL)
    {
        while(!feof(f))
        {
            auxMateria = materias_new();
            if(auxMateria != NULL)
            {
                cantidad = fread(auxMateria, sizeof(Materias), 1, f);
                if(cantidad == 1)
                {
                    controller_printOne(auxMateria);
                    this->add(this, auxMateria);
                    cantTotal++;
                }
                else
                {
                    if(feof(f))
                        break;
                    else
                    {
                        printf("No leyo el ultimo registro.\n");
                        break;
                    }
                }
            }//printf("%d\n", auxMateria->id);
        }
        fclose(f);
        printf("Archivo levantado con exito. Se obtuvieron %d registros\n\n", cantTotal);
        //controller_printAll(this);
    }
    else
    {
        printf("No existe archivo.\n");
    }
}
*/
