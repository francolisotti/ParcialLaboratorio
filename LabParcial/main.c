#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "Arbol.h"
#include "Lista.h"
#include "Caja.h"
#include "Fila.h"


int main()
{
    //nodo * lista=inicLista();
    nodoArbol * arbol=inicArbol();
    char archi_persona[]={"cliente.bin"};
    char archi_caja[]={"caja.bin"};
    int orden=0;
    arbol=ArchiToArbol(archi_persona,arbol);
    //orden= selectOrden();
    //mostrarArbol(arbol,orden);
    caja cajita[12];
    int i=0;
    pasarDeArchiAcaja(archi_caja,cajita);
    abrir_cajas_(cajita);
    agregarClienteACaja(&cajita,arbol);
    int j=0;
    //mostrar(&(cajita[11].filita));
    caja cajaAux;
    atenderClientes(&cajita);
    while (j<12)
    {
        printf("\n\n\n\n\n\nUltimo while va a mostrar las cajas (hay un getch())\n\n");
        getch();
        cajaAux=cajita[j];
        mostrarCaja(cajaAux);
        j++;
    }
    return 0;
}
