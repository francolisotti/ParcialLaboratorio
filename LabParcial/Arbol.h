#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Persona.h"

typedef struct
{
    persona p;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

int selectOrden ();
nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (persona p);
nodoArbol * insertarNodoArbol (nodoArbol * arbol, persona p);
void inorder(nodoArbol * arbol);
void preorder(nodoArbol * arbol);
void postorder(nodoArbol * arbol);

void mostrarArbol (nodoArbol * arbol, int orden);
nodoArbol * nodoMasDerecho(nodoArbol * arbol);
nodoArbol * nodoMasIzquierdo(nodoArbol * arbol);
nodoArbol * borrarNodoArbol (nodoArbol * arbol, char nombre []);
nodoArbol * ArchiToArbol (char nombre[],nodoArbol * arbol);


#endif // ARBOL_H_INCLUDED
