typedef struct
{
    char* key;
    char* value;
}s_Data;

int loadDataFile(char fileName[], int arrayLen);
void vaciar(char str[]);
void copiar(s_Data* pData,char str[],int i);
