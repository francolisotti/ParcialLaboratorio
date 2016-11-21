#include "Menu.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void nombreArchivoPersona (char nombre[])
{
    char supuestoNombre[40];
    FILE * archi;

    printf("\nIngrese el nombre del archivo cargado con personas (y extencion): ");
    fflush(stdin);
    gets(&supuestoNombre);
    archi=fopen(supuestoNombre, "rb");
    while (archi==NULL)
    {
        printf("\nERROR:");
        printf("\nNo existe un archivo con tal nombre");
        printf("\nPor favor, ingrese otro nombre: ");
        gets(&supuestoNombre);
        archi=fopen(supuestoNombre, "rb");
    }
    fclose(archi);
    strcpy(nombre,supuestoNombre);
}

void nombreArchivoCaja (char nombre[])
{
    char supuestoNombre[40];
    FILE * archi;

    printf("\nIngrese el nombre del archivo cargado con cajas (y extencion): ");
    fflush(stdin);
    gets(&supuestoNombre);
    archi=fopen(supuestoNombre, "rb");
    while (archi==NULL)
    {
        printf("\nERROR:");
        printf("\nNo existe un archivo con tal nombre");
        printf("\nPor favor ingrese otro nombre: ");
        gets(&supuestoNombre);
        archi=fopen(supuestoNombre, "rb");
    }
    fclose(archi);
    strcpy(nombre,supuestoNombre);
}


