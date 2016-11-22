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
void mostrarArchiCaja (char archi_Caja[]);

int contarClientesCaja (caja cajita);
void mostrarCaja (caja cajita);
int pasarDeArchiAcaja_yContar (char archiCajas[], caja cajita[]);
int evaluar_caja_con_menos_clientes (caja cajita[], int tipoPago);

void agregarClientePreorden(nodoArbol * arbol, caja cajita[]);
void agregarClienteInorden(nodoArbol * arbol, caja cajita[]);
void agregarClientePostorden(nodoArbol * arbol, caja cajita[]);

void agregarClienteACaja (caja cajita[], nodoArbol * raiz);
void agregarFIFO (Fila * filita, persona a);
void agregarPrioridadesA(Fila * filita, persona a);
void agregarPrioridadesNA(Fila * filita, persona a);
void agregarSRTF (Fila * filita, persona a);


void agregarSegunAlgoritmo (Fila * filita, persona a, char algoritmo[]);

int agregarClienteACajaEnTiempoDeterminado(caja cajita[], int tiempo);
void atenderClientes (caja cajita[]);

void agregarSegunAlgoritmoEnTiempo(Fila * filita, persona a, char algoritmo[], int tiempo);

void vaciar_cajas (caja cajita[], int validos);
void vaciar_fila(caja cajita, int op);


#endif // CAJA_H_INCLUDED
