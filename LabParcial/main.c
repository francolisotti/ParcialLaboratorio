#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    nodo * lista=inicLista();
    nodoArbol * arbol=inicArbol();
    char archi_caja[]={"caja.bin"};
   /* int orden=0;
    mostrarArchivo(nombre);
    ArchiToArbol(nombre,arbol);
    getch();
    orden= selectOrden(orden); Arreglar o poner menu switch
    mostrarArbol(arbol,1);*/
    caja cajita[12];
    pasarDeArchiAcaja(archi_caja,cajita);

    return 0;
}
