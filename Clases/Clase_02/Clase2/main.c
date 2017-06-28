#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,flag = 0;
    int maximo,minimo;
    int suma = 0, promedio;

    for(i=0;i<5;i++)
    {
        printf("Ingrese numero: ");
        scanf("%d",&num);

        suma = suma + num;

        if(flag == 0 || num>maximo)
        {
            maximo = num;
        }

        if(flag == 0 || num<minimo)
        {
            minimo = num;
        }
        flag = 1;
    }
    promedio = suma /i;
    printf("El promedio es: %d\n",promedio);
    printf("El maximo es: %d\n",maximo);
    printf("El minimo es: %d\n",minimo);


    return 0;
}
