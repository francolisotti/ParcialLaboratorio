#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

nodo * inicLista ()
{
    return NULL;
}

nodo * crearNodoLista (persona cliente)
{
    nodo * nuevo=(nodo*)malloc(sizeof(nodo));

    nuevo->cliente=cliente;
    nuevo->siguiente=NULL;
    nuevo->anterior=NULL;

    return nuevo;
}

nodo * agregarAlPrincipio (nodo * lista, nodo * nuevo)
{
    nuevo->siguiente=lista;
    if(lista!=NULL)
    {
        lista->anterior=nuevo;
    }
    return nuevo;
}

nodo * buscarUltimo (nodo * lista)
{
    nodo * seg=lista;
    while (seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodo * agregarAlFinal (nodo * lista, nodo * nuevo)
{
    nodo * seg;
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        seg=buscarUltimo(lista);
        seg->siguiente=nuevo;
        nuevo->anterior=seg;


        return lista;
    }
}

nodo * agregarEnOrdenTipoCliente (nodo * lista, nodo * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else if(nuevo->cliente.tipo_cliente <= lista->cliente.tipo_cliente)
    {
        lista=agregarAlPrincipio(lista,nuevo);
    }
    else
    {
        nodo * ante=lista;
        nodo * seg=lista->siguiente;
        while(seg!=NULL && seg->cliente.tipo_cliente <= nuevo->cliente.tipo_cliente)
        {
            ante=seg;
            seg=seg->siguiente;
        }

        ante->siguiente=nuevo;
        nuevo->anterior=ante;
        nuevo->siguiente=seg;

        if(seg!=NULL)
        {
            seg->anterior=nuevo;
        }
    }
    return lista;
}

nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else if(nuevo->cliente.cantArticulos <= lista->cliente.cantArticulos)
    {
        lista=agregarAlPrincipio(lista,nuevo);
    }
    else
    {
        nodo * ante=lista;
        nodo * seg=lista->siguiente;
        while(seg!=NULL && seg->cliente.cantArticulos <= nuevo->cliente.cantArticulos)
        {
            ante=seg;
            seg=seg->siguiente;
        }

        ante->siguiente=nuevo;
        nuevo->anterior=ante;
        nuevo->siguiente=seg;

        if(seg!=NULL)
        {
            seg->anterior=nuevo;
        }
    }
    return lista;
}

void mostrarLista(nodo * aux)
{
    while (aux!=NULL)
    {
        mostrarPersona(aux->cliente);
        aux=aux->siguiente;
    }
}

nodo * borrarPrimero (nodo * lista)
{
    nodo * seg=lista;
    if (lista->siguiente)
    {
        lista=lista->siguiente;
    }
    lista->anterior=NULL;
    free(seg);

    return lista;
}

nodo * borrarNodo(nodo * lista, nodo * buscado)
{
    nodo * aBorrar=NULL;
    nodo * seg=NULL;

    if(lista!=NULL)
    {
        if(lista->cliente.nombreApellido==buscado->cliente.nombreApellido)
        {
            aBorrar=lista;

            lista=lista->siguiente;
            if(lista!=NULL)
            {
                lista->anterior=NULL;
            }

            free(aBorrar);
        }
        else
        {
            seg=lista->siguiente;
            while(seg!=NULL && seg->cliente.nombreApellido!=buscado->cliente.nombreApellido)
            {
                seg=seg->siguiente;
            }

            if(seg!= NULL)
            {
                nodo * ant=seg->anterior;
                ant->siguiente=seg->siguiente;

                if(seg->siguiente!=NULL)
                {
                    nodo * aux = seg->siguiente;
                    aux->anterior=ant;
                }
                free(seg);
            }

        }
    }
    return lista;
}
