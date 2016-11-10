#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    nodo * lista=inicLista();
    nodoArbol * arbol=inicArbol();
    char archi_persona[]={"cliente.bin"};
    char archi_caja[]={"caja.bin"};
    int orden=0;
    //mostrarArchivo(archi_persona);
    arbol=ArchiToArbol(archi_persona,arbol);
    getch();
    orden= selectOrden();
    //printf("orden %d",orden);
    mostrarArbol(arbol,orden);
    //caja cajita[12];
    //pasarDeArchiAcaja(archi_caja,cajita);

    return 0;
}
