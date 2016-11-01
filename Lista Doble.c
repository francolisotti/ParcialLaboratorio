#include "TDA Lista Doble.h"

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

agregarAlFinal (nodo * lista, nodo * nuevo)
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

nodo * agregarEnOrdenTipoCliente(nodo * lista, nodo * nuevo)
{
    nodo * seg=lista;

    while (seg->cliente.tipo_cliente <= nuevo->cliente.tipo_cliente)
    {
        seg=seg->siguiente;
    }

    if (seg->siguiente==NULL)
    {
        lista=agregarAlFinal(lista,nuevo);

    }
    else
    {
        nodo * aux=seg->siguiente;
        nuevo->siguiente=seg->siguiente;
        aux->anterior=nuevo;
        nuevo->anterior=seg;
        seg->siguiente=nuevo;
    }

    return lista;

}
nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevo)
{
    nodo * seg=lista;
    while (seg->cliente.cantArticulos <= nuevo->cliente.cantArticulos)
    {
        seg=seg->siguiente;
    }
    if (seg->siguiente==NULL)
    {
        lista=agregarAlFinal(lista,nuevo);

    }
    else
    {
        nodo * aux=seg->siguiente;
        nuevo->siguiente=seg->siguiente;
        aux->anterior=nuevo;
        nuevo->anterior=seg;
        seg->siguiente=nuevo;
    }

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
    lista=lista->siguiente;
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

void inicFila()
{
    return NULL;
}
Fila * agregar (Fila * filita, nodo * nuevo)
{
    nodo * aux=filita->ultimo;

    nuevo->anterior=aux;
    aux->siguiente=nuevo;
    filita->ultimo=nuevo;

    return filita;
}
Fila * quitar (Fila * filita)
{
    nodo * aux=filita->primero;

    filita->primero=aux->siguiente;
    nodo * aux2=filita->primero;
}
void mostrar(Fila * filita)
{
    mostrarLista(filita->primero);
}
filaVacia(Fila * filita)
{
    int rta=NULL;

    if (fila)
}
