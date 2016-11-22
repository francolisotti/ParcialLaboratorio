#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"



void inicFila(Fila * filita)
{
    filita->primero=inicLista();
    filita->ultimo=inicLista();
}
void agregar (Fila * filita, persona a)
{
    nodo * nuevo=crearNodoLista(a);

    if (filita->primero==NULL)
    {
        filita->primero=nuevo;
    }
    else
    {
        filita->primero=agregarAlFinal(filita->primero,nuevo);

    }
    filita->ultimo=nuevo;
}
void quitar (Fila * filita)
{
    //printf("\n-ENTRA-");
    if (filita->primero!=NULL)
    {
        nodo * aux=filita->primero;
        nodo * sig=aux->siguiente;
        if(filita->primero!=filita->ultimo)
        {
            sig->anterior=NULL;
            filita->primero=sig;
           // printf("\n--MASDEUNO-----");
        }
        else
        {
            inicFila(filita);
           // printf("\n---ULTIMO---");
        }
        free(aux);
    }
   // printf("\n-SALE-");

}

void mostrar(Fila * filita)
{
    if (filaVacia(filita)==0)
    {
        printf("\nFila vacia");
    }
    else
    {
        mostrarLista(filita->primero);
    }
}

int filaVacia(Fila * filita)
{
    int rta=1;
    if (filita->primero==NULL)
    {
        rta=0;
    }
    return rta;
}

void tiempo_de_espera_fila (Fila * filita)
{
    if (filaVacia(filita)==1)
    {
        int espera=0;
        nodo * aux=filita->primero;
        aux->cliente.tiempoDeEspera=espera;
        espera=aux->cliente.cantArticulos;
        aux->cliente.tiempoProcesado=aux->cliente.cantArticulos;
        if(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
            while (aux!=NULL)
            {
                aux->cliente.tiempoDeEspera=espera;
                espera=espera+aux->cliente.cantArticulos;
                aux->cliente.tiempoProcesado=aux->cliente.tiempoDeEspera+aux->cliente.cantArticulos;

                aux=aux->siguiente;
            }
        }
    }
}


void tiempo_de_espera_fila_RR (Fila * filita)
{
    if (filaVacia(filita)==1)
    {
        int espera=0;
        int quantum=6;
        nodo * aux=filita->primero;
        aux->cliente.tiempoDeEspera=espera;
        espera=aux->cliente.cantArticulos;
        aux->cliente.tiempoProcesado=aux->cliente.cantArticulos;

        if(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
            while (aux!=NULL)
            {
                aux->cliente.tiempoDeEspera=espera;
                espera=espera+aux->cliente.cantArticulos;
                aux->cliente.tiempoProcesado=aux->cliente.tiempoDeEspera+aux->cliente.cantArticulos;

                aux=aux->siguiente;
            }
        }
    }
}

void vaciar_fila(Fila * filita)
{
    while (filaVacia(filita)==1)
    {
        filita->primero=borrarPrimero(filita->primero);
    }
}






























