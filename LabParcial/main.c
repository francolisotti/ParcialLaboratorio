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
    arbol=ArchiToArbol(archi_persona,arbol);
   // orden= selectOrden();
   // mostrarArbol(arbol,orden);
    caja cajita[12];
    int i=0;
    pasarDeArchiAcaja(archi_caja,cajita);
    abrir_cajas_(cajita);
    while (i<12)
    {
        mostrarCaja(cajita[i]);
        i++;
    }
    agregarClienteACaja(cajita,arbol);

    return 0;
}
