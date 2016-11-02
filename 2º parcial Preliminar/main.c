#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Persona.h"
#include "Arbol.h"

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

    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(persona),1,archi)>0)
        {
            mostrarPersona(aux);
        }
    }
    else
    {
        printf("\nEl archivo no esta cargado");
    }
    fclose(archi);
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
