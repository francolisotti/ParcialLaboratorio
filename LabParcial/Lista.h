#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Persona.h"

typedef struct
{
    persona cliente;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo;



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



#endif // LISTA_H_INCLUDED
