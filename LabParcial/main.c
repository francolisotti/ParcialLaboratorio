#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "Arbol.h"
#include "Lista.h"
#include "Caja.h"
#include "Fila.h"


int main()
{
    nodo * lista=inicLista();
    nodoArbol * arbol=inicArbol();
    char archi_persona[]={"cliente.bin"};
    char archi_caja[]={"caja.bin"};
    int orden=0;
    //mostrarArchiPersona(archi_persona);
    //getch();
    arbol=ArchiToArbol(archi_persona,arbol);
    getch();
    orden= selectOrden();
    mostrarArbol(arbol,orden);
    getch();
    caja cajita[12];
    pasarDeArchiAcaja(archi_caja,cajita);
    int i=0;
    caja cajiton;
    while (i<12)
    {
        cajiton=cajita[i];
        mostrarCaja(cajiton);
        i++;
    }

    return 0;
}
