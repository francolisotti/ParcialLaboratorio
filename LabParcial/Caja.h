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


void mostrarCaja (caja cajita);
int pasarDeArchiAcaja_yContar (char archiCajas[], caja cajita[]);
int contarClientesCaja (caja cajita);
int evaluar_caja_con_menos_clientes (caja cajita[], int tipoPago);

void agregarClienteACaja (caja cajita[], nodoArbol * raiz);
void agregarPrioridadesA(Fila * filita, persona a);
void agregarPrioridadesNA(Fila * filita, persona a);
void agregarSRTF (Fila * filita, persona a);
void agregarSJF (Fila * filita, persona a);

void agregarSegunAlgoritmo (Fila * filita, persona a, char algoritmo[]);

void agregarClientePreorden(nodoArbol * arbol, caja cajita[]);
void agregarClienteInorden(nodoArbol * arbol, caja cajita[]);
void agregarClientePostorden(nodoArbol * arbol, caja cajita[]);


void atenderClientes (caja cajita[]);

int agregarClienteACajaEnTiempoDeterminado(caja cajita[], int tiempo);

void agregarPrioridadesAEnTiempo(Fila * filita,persona a,int tiempo);
void agregarPrioridadesNAEnTiempo(Fila * filita,persona a,int tiempo);
void agregarSRTFEnTiempo(Fila * filita, persona a,int tiempo);
void agregarSJFEnTiempo(Fila * filita,persona a,int tiempo);
void agregarFIFOEnTiempo(Fila * filita, persona a, int tiempo);
void agregarRREnTiempo(Fila * filita,persona a,int tiempo);
void agregarSegunAlgoritmoEnTiempo(Fila * filita, persona a, char algoritmo[], int tiempo);

void vaciar_cajas (caja cajita[], int validos);
void promedioCajas (caja cajita[],int validos, float promediosE[], float promediosR[]);

#endif // CAJA_H_INCLUDED
