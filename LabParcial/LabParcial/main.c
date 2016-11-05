#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void archivarPersona (char nombre[], persona nuevo)
{
    FILE * archi=fopen(nombre,"rb");
    if (archi==NULL)
    {
        archi=fopen(nombre,"wb");
    }
    else
    {
        archi=fopen(nombre,"ab");
    }
    fwrite(&nuevo,sizeof(persona),1,archi);
    fclose(archi);
}

void mostrarArchivo (char nombre[])
{
    FILE * archi;
    archi=fopen(nombre, "rb");
    persona aux;
    int i=0;
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(persona),1,archi)>0)
        {
            mostrarPersona(aux);
            i++;
        }
        printf("Elementos mostrados: %d",i);
    }
    else
    {
        printf("\nEl archivo no esta cargado");
    }
    fclose(archi);
}



int main()
{
    nodo * lista=inicLista();
    char nombre[]={"cliente.bin"};
    mostrarArchivo(nombre);

    return 0;
}
