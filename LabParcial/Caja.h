#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "Arbol.h"
#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;  ///1 efectivo, 2 credito o debito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30]; ///debe informar que tipo de alg. de planificaicon utiliza la caja
    Fila * filita;
}caja;

void abrir_cajas_(caja cajita[]);
caja buscarCaja (caja A[], int buscada);
void mostrarCaja (caja cajita);
caja agregarClienteACaja (caja cajita[], nodoArbol * raiz);
caja agregarClienteACajaEnTiempoDeterminado ();
caja atenderClientes (caja cajita);
void pasarDeArchiAcaja (char archiCajas[], caja cajita[]);



#endif // CAJA_H_INCLUDED
