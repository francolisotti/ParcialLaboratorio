#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "Arbol.h"
#include "Fila.h"

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;  ///1 efectivo, 2 credito o debito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30]; ///debe informar que tipo de alg. de planificaicon utiliza la caja
    Fila filita;
}caja;

void abrir_cajas_(caja cajita[]);
caja abrirOcerrarCaja (caja cajita);
caja buscarCaja (caja A[], int buscada);
int contarClientesCaja (caja cajita);
void mostrarCaja (caja cajita);
void pasarDeArchiAcaja (char archiCajas[], caja cajita[]);
int Subarreglo (caja cajita[], caja aux[12], int tipopago);
int evaluar_caja_con_menos_clientes (caja cajita[], int tipoPago);

void agregarClientePreorden(nodoArbol * arbol, caja cajita[]);
void agregarClienteInorden(nodoArbol * arbol, caja cajita[]);
void agregarClientePostorden(nodoArbol * arbol, caja cajita[]);

void agregarClienteACaja (caja cajita[], nodoArbol * raiz);
void pasarAuxACaja (caja aux, caja cajita[]);
caja agregarFIFO (caja cajita, persona a);
caja agregarPrioridadesA(caja cajita, persona a);
caja agregarPrioridadesNA(caja cajita, persona a);
caja agregarSRTF (caja cajita, persona a);


caja agregarSegunAlgoritmo (caja cajita, persona a);

caja agregarClienteACajaEnTiempoDeterminado ();
caja atenderClientes (caja cajita);



#endif // CAJA_H_INCLUDED
