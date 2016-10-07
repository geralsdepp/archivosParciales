#include <stdio.h>
#include <string.h>


typedef struct
{
    char talle;
    char color[35];
}Remera;

typedef struct
{
    char talle;
    char color[35];

}Pantalon;
typedef struct
{
    int nombre[35];
    Remera rem;
}Perro;

typedef struct
{
    int edad;
    char nombre[35];
    Remera rem;
    Pantalon pant;
}Persona;



int main()
{
    Perro can;
    Persona per;
    per.rem.talle = 's';
    per.edad = 1;
    strcpy(per.pant.color,"rojo");

    strcpy(can.nombre,"luna");
    strcpy(can.rem.color,"azul");
    return 0;
}
