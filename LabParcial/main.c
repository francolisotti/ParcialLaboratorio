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
    //orden= selectOrden();
    //mostrarArbol(arbol,orden);
    caja cajita[12];
    caja cajon;
    int i=0;
    pasarDeArchiAcaja(archi_caja,cajita);
<<<<<<< HEAD
<<<<<<< HEAD
    for (i=0;i<12;i++)
    {
        cajon=cajita[i];
        mostrarCaja(cajon);
    }

    abrir_cajas_(cajita);
//    int i=0;

    /*while (i<12)
=======
=======
    abrir_cajas_(cajita);
>>>>>>> origin/master
    int i=0;
    //agregarClienteACaja(cajita,arbol);
    while (i<12)
>>>>>>> origin/master
    {
        mostrarCaja(cajita[i]);
        i++;
    }


    return 0;
}
