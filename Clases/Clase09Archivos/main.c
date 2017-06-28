#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"

int main()
{
    int arrayLen = 50;
   // s_Data* pData;
   // pData = (s_Data*)malloc(sizeof(s_Data)*arrayLen);
    loadDataFile("archivo.txt",arrayLen);

    return 0;
}
