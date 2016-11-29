#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"



void inicFila(Fila * filita)
{
    filita->primero=inicLista();///inicializamos la fila para que no se cargue con basura
    filita->ultimo=inicLista();
}
void agregar (Fila * filita, persona a)
{
    nodo * nuevo=crearNodoLista(a);///creamos un nodo con los datos de la persona a

    if (filita->primero==NULL)
    {
        filita->primero=nuevo;///si estaba vacia lo agrega al principio
    }
    else
    {
        filita->primero=agregarAlFinal(filita->primero,nuevo);///sino al final

    }
    filita->ultimo=nuevo;
}
void quitar (Fila * filita)
{
    nodo * aux;
    nodo * sig;
    if (filita->primero!=NULL)///si tiene datos
    {
        aux=filita->primero;
        while(aux!=NULL)
        {
            sig=aux->siguiente;
            free(aux);///eliminamos el nodo de la fila
            mostrarLista(aux);///mostramos como va la fila
            printf("\nPresione cualquier tecla para continuar\n");///esto es para poder ver paso a paso como va quedando
            getch();
            if (sig!=NULL)///!!!!!!!!!!!!!!!!!!!!!!ASASAFSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
            {
                sig->anterior=NULL;
            }
            filita->primero=sig;
            aux=filita->primero;
        }
    }
}

void mostrar(Fila * filita)
{
    if (filaVacia(filita)==0)///si la fila esta vacia
    {
        printf("\nFila vacia");
    }
    else
    {
        mostrarLista(filita->primero);///sino mostramos la fila (que es una lista de nodos del primero al ultimo)
    }
}

int filaVacia(Fila * filita)
{
    int rta=1;
    if (filita->primero==NULL)
    {
        rta=0;///si esta vacia (es decir que el primer nodo es NULL) devuelve 0 sino 1
    }
    return rta;
}

void tiempo_de_espera_fila (Fila * filita)
{
    if (filaVacia(filita)==1)///si la fila tiene datos
    {///se modifican los tiempos de espera
        int espera=0;
        nodo * aux=filita->primero;///creamos un auxiliar para recorrer la fila
        aux->cliente.tiempoDeEspera=espera;
        espera=aux->cliente.cantArticulos;///cargamos la espera y el provesado del primer cliente de la fila
        aux->cliente.tiempoProcesado=aux->cliente.cantArticulos;
        if(aux->siguiente!=NULL)///si hay mas clientes en la fila
        {
            aux=aux->siguiente;///nos movemos en la lista
            while (aux!=NULL)///mientras que tenga datos
            {
                aux->cliente.tiempoDeEspera=espera;///la segunda persona recivira por espera la cantidad de articulos del cliente ya atendido
                espera=espera+aux->cliente.cantArticulos;///los demas recibiran estos tiempos de espera sumados a la cantidad de articulos
                aux->cliente.tiempoProcesado=aux->cliente.cantArticulos;
///---------------------------------------------------------
                aux=aux->siguiente;///nos movemos en la lista
            }
        }
    }
}


void tiempo_de_espera_fila_RR (Fila * filita)
{
    if (filaVacia(filita)==1)///lo mismo que en la anterior pero con las modificaciones necesarias para round robin
    {
        int espera=0;
        int contador=1;
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
                aux->cliente.tiempoDeEspera=contador*quantum;
                contador++;
                aux->cliente.tiempoProcesado=aux->cliente.cantArticulos;

                aux=aux->siguiente;
            }
        }
    }
}

Fila mostrar_RR(Fila filita)
{
    nodo * aux=filita.primero;
    nodo * seg=aux->siguiente;
    if (filaVacia(&filita)==0)
    {
        printf("\nFila vacia");
    }
   /* else
    {
        mostrarLista(aux);
        aux->cliente.cantArticulos=(aux->cliente.cantArticulos)-6;
        if (aux->cliente.cantArticulos>)
        {
            filita.primero=seg;
            aux=borrarPrimero(aux);
        }
        else
        {
            filita.ultimo=aux;
            agregar(&filita,aux->cliente);
            aux=borrarPrimero(aux);
        }
    }*/
    return filita;
}
