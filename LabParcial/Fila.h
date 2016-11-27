#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "Lista.h"
#include "arbol.h"

typedef struct
{
    struct nodo * primero;
    struct nodo * ultimo;
} Fila;


void inicFila(Fila * filita);
void agregar (Fila * filita, persona a);
void quitar (Fila * filita);
void mostrar(Fila * filita);
int filaVacia(Fila * filita);
void tiempo_de_espera_fila (Fila * filita);
void tiempo_de_espera_fila_RR (Fila * filita);

void vaciar_fila(Fila * filita);


#endif // FILA_H_INCLUDED
