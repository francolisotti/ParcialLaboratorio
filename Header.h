#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "string.h"

///TDA Persona

typedef struct
{
    char nombreApellido [40];
    int cantArticulos; // es el tiempo de ejecución
    int tiempoDeEspera; // es el tiempo de respuesta
    int tiempoProcesado; // es el tiempo que ya fue procesado en la línea de caja
    int tipo_cliente; // prioridad (1: embarazada, 2: jubilado y 3: normal)
    int tipo_pago; // 1 efectivo, 2 crédito o débito, 3 todos
} persona;

persona nuevo_Persona();
persona crearPersona (char nombreApellido[], int cantArticulos,int tipo_Cliente,int tipo_Pago);
void cargarPersona (char nombreDelArchivo[]);
void mostrarPersona(persona aux);

///TDA Arbol

typedef struct
{
    persona p;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (persona p);
nodoArbol * insertarNodoArbol (nodoArbol * arbol, persona p);
void mostrarArbol (nodoArbol * arbol, int orden);
nodoArbol * nodoMasDerecho(nodoArbol * arbol);
nodoArbol * nodoMasIzquierdo(nodoArbol * arbol);
nodoArbol * borrarNodoArbol (nodoArbol * arbol, char nombre []);
nodoArbol * ArchiToArbol (char nombre[],nodoArbol * arbol);

///TDA Lista Doble

typedef struct
{
    persona cliente;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo;

typedef struct
{
    struct nodo * primero;
    struct nodo * ultimo;
} Fila;

nodo * inicLista ();
nodo * crearNodoLista (persona cliente);
nodo * agregarAlPrincipio (nodo * lista, nodo * nuevo);
nodo * buscarUltimo (nodo * lista);
nodo * agregarAlFinal (nodo * lista, nodo * nuevo);
nodo * agregarEnOrdenTipoCliente(nodo * lista, nodo * nuevo);
nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevo);
void mostrarLista(nodo * aux);
nodo * borrarPrimero (nodo * lista);
nodo * borrarNodo(nodo * lista, nodo * buscado);
void inicFila(Fila * filita);
void agregar (Fila * filita, persona a);
char quitar (Fila * filita);
void mostrar(Fila * filita);
int filaVacia(Fila * filita);

///TDA Caja

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;  //1 efectivo, 2 credito o debito, 3 todos
    int abiertaOcerrada;
    char algoritmoPlanificacion[30]; //debe informar que tipo de alg. de planificaicon utiliza la caja
    Fila filita;
}caja;

agregarCaja ();
abrirOcerrarCaja (caja cajita);
buscarCaja (caja cajita, int buscada);
mostrarCaja (caja cajita);
agregarClienteACaja (caja cajita, nodo * lista);
agregarClienteACajaEnTiempoDeterminado ();
atenderClientes (caja cajita);




#endif // HEADER_H_INCLUDED
