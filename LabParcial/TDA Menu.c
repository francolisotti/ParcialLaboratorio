#include "Menu.h"
#include "string.h"

char nombreArchivoPersona ()
{
    char supuestoNombre[40];
    FILE * archi;

    printf("\nIngrese el nombre del archivo cargado con personas (con su extencion): ");
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
    return supuestoNombre;
}
