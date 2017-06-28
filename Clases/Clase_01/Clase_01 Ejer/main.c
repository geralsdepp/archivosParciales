#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador = 0, cont_neg = 0, cont_pos = 0, cont_ceros = 0;
    float numero;
    do
    {
        printf("\nIngrese un numero: ");
        scanf("%f",&numero);

        if(numero < 0)
        {
            cont_neg++;
        }
        else if(numero > 0)
        {
            cont_pos++;
        }
        else
            cont_ceros++;

        contador++;
    }while(contador < 10);

    printf("Numeros positivos ingresados: %d\n",cont_pos);
    printf("Numeros negativos ingresados: %d\n",cont_neg);
    printf("Ceros ingresados: %d\n",cont_ceros);

    return 0;
}
