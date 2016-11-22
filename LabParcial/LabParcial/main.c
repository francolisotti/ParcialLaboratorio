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
        printf("\nElementos mostrados: %d\n",i);
    }
    else
    {
        printf("\nEl archivo no esta cargado");
    }
    fclose(archi);
}

int selectOrden (int orden)
{
    printf("Decida el orden en que se va a mostrar el arbol\nSiendo 1 preorden,2 inorden y 3 postorden: ");
    scanf("%d\n",orden);
    while ((orden > 3) && (orden <1))
    {
        printf("Ingrese nuevamente del 1 al 3 por favor: ");
        scanf("%d\n",&orden);
    }
    return orden;
}

int main()
{
    nodo * lista=inicLista();
    nodoArbol * arbol=inicArbol();
    char nombre[]={"cliente.bin"};
    int orden=0;
    mostrarArchivo(nombre);
    ArchiToArbol(nombre,arbol);
    getch();
    /*orden= selectOrden(orden)*/; //Arreglar o poner menu switch
    mostrarArbol(arbol,1);
    return 0;
}
