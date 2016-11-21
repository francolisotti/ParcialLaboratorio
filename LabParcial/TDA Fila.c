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
char quitar (Fila * filita)
{
    char resp[40];
    strcpy(resp,"ninguno");
    if (filita->primero!=NULL)
    {
        nodo * aux=filita->primero;
        nodo * sig=aux->siguiente;

        if(filita->primero!=filita->ultimo)
        {
            sig->anterior=NULL;
            filita->primero=sig;
        }
        else
        {
            filita->primero=NULL;
            filita->ultimo=NULL;
        }
        strcpy(resp,aux->cliente.nombreApellido);
        free(aux);
    }
    return resp;
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
        printf("tumami");
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
