#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

int selectOrden ()
{
    int orden=0;
    printf("Decida el orden en que se va a mostrar el arbol: ");
    scanf("%d",&orden);
    while ((orden > 3) && (orden <1))
    {
        printf("\nIngrese nuevamente del 1 al 3 por favor: ");
        scanf("%d\n",&orden);
    }
    return orden;
}

nodoArbol * inicArbol ()
{
    return NULL;
}

nodoArbol * crearNodoArbol(persona p)
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));

    strcpy(aux->p.nombreApellido,p.nombreApellido);
    aux->p.tipo_cliente=p.tipo_cliente;
    aux->p.tipo_pago=p.tipo_pago;
    aux->p.cantArticulos=p.cantArticulos;
    aux->p.tiempoDeEspera=NULL;
    aux->p.tiempoProcesado=NULL;

    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

nodoArbol * insertarNodoArbol(nodoArbol * arbol, persona p)
{
    if(arbol==NULL)
    {

        arbol = crearNodoArbol(p);

    }
    else
    {
        if(strcmp(p.nombreApellido,arbol->p.nombreApellido)>0)
        {
            arbol->der=insertarNodoArbol(arbol->der, p);
        }
        else
        {
            arbol->izq=insertarNodoArbol(arbol->izq, p);
        }
    }
    return arbol;
}

void inorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        mostrarPersona(arbol->p);
        inorder(arbol->der);
    }
}

void preorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        mostrarPersona(arbol->p);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void postorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        mostrarPersona(arbol->p);
    }
}

void mostrarArbol (nodoArbol * arbol, int orden)
{

    if(arbol)
    {
        if(orden==1)
        {
            preorder(arbol);
        }
        else if (orden==2)
        {
            inorder(arbol);
        }
        else if (orden==3)
        {
            postorder(arbol);
        }
    }
}

nodoArbol * nodoMasDerecho(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(!arbol->der)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * arbol)
{
    nodoArbol * aux;
    if(!arbol->izq)
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);
    }
    return aux;
}

nodoArbol * borrarNodoArbol (nodoArbol * arbol, char nombre [])
{
    if(arbol)
    {
        if(strcmp(nombre,arbol->p.nombreApellido)>0)
        {
            arbol->der=borrarNodoArbol(arbol->der, nombre);
        }
        else if (strcmp(nombre,arbol->p.nombreApellido)<0)
        {
            arbol->izq=borrarNodoArbol(arbol->izq, nombre);
        }
        else
        {
            if(arbol->izq)
            {
                arbol->p= (nodoMasDerecho(arbol->izq))->p;
                arbol->izq=borrarNodoArbol(arbol->izq, arbol->p.nombreApellido);
            }
            else if(arbol->der!=NULL)
            {
                arbol->p=(nodoMasIzquierdo(arbol->der))->p;
                arbol->der=borrarNodoArbol(arbol->der, arbol->p.nombreApellido);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
    }
    return arbol;
}
nodoArbol * ArchiToArbol (char nombre[],nodoArbol * arbol)
{
    persona aux;
    FILE * archi=fopen(nombre,"rb");
    if (archi==NULL)
    {
        printf("No se encontro el archivo\n");
    }
    else
    {

        while (!feof(archi))
        {
            fread(&aux,sizeof(persona),1,archi);
            if (!feof(archi))
            {
                arbol=insertarNodoArbol(arbol,aux);
            }
        }
    }
    fclose(archi);

    return arbol;
}

