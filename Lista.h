#ifndef TDA_LISTA_DOBLE_H_INCLUDED
#define TDA_LISTA_DOBLE_H_INCLUDED
#include "string.h"
#include <stdio.h>
#include <stdlib.h>


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
agregarAlFinal (nodo * lista, nodo * nuevo);
nodo * agregarEnOrdenTipoCliente(nodo * lista, nodo * nuevo);
nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevo);
void mostrarLista(nodo * aux);
nodo * borrarPrimero (nodo * lista);
nodo * borrarNodo(nodo * lista, nodo * buscado);







#endif // TDA_LISTA_DOBLE_H_INCLUDED
