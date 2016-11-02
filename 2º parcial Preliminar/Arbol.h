#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED



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
#endif // ARBOL_H_INCLUDED
