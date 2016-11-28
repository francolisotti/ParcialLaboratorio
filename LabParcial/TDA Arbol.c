#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

int selectOrden ()///nos permite elegir el orden en el cual vamos a recorrer el arbol
{
    int orden=0;
    printf("Decida el orden en que se va a mostrar el arbol: ");
    scanf("%d",&orden);///guardamos el dato en orden
    while ((orden > 3) && (orden <1))///esto es por si se ingresa un numero incorrecto
    {
        printf("\nIngrese nuevamente del 1 al 3 por favor: ");
        scanf("%d\n",&orden);
    }
    return orden;///retornamos orden a alguna variable receptora que llame a la funcion para manejarnos en el arbol
}

nodoArbol * inicArbol ()
{
    return NULL;///lo usamos para que el arbol empieze "limpio", sin basura
}

nodoArbol * crearNodoArbol(persona p)///recibimos una persona p cargada con los datos correspondientes
{
    nodoArbol * aux = (nodoArbol *) malloc(sizeof(nodoArbol));///creamos un auxiliar con los casteos necesarios

    strcpy(aux->p.nombreApellido,p.nombreApellido);
    aux->p.tipo_cliente=p.tipo_cliente;
    aux->p.tipo_pago=p.tipo_pago;
    aux->p.cantArticulos=p.cantArticulos;/// //////////////////////////////////////////
    aux->p.tiempoDeEspera=NULL;///no iria 0?
    aux->p.tiempoProcesado=NULL;///no iria 0?

    aux->izq=NULL;/// //////////////////////////////////////////////////////
    aux->der=NULL;

    return aux;
}

nodoArbol * insertarNodoArbol(nodoArbol * arbol, persona p)///incerta una persona en el arbol
{
    if(arbol==NULL)///si el arbol esta vacio la persona ira al principio
    {

        arbol = crearNodoArbol(p);///creamos un nodoArbol con los datos de p

    }
    else///si no esta vacio
    {
        if(strcmp(p.nombreApellido,arbol->p.nombreApellido)>0)///comparamos los nombres del arbol y de la persona
        {
            arbol->der=insertarNodoArbol(arbol->der, p);///si el nombre de la persona es "mas grande" se agrega a la derecha
        }
        else///sino a la izquierda
        {
            arbol->izq=insertarNodoArbol(arbol->izq, p);
        }
    }
    return arbol;///retornamos el arbol cargado
}

void inorder(nodoArbol * arbol)///mostramos el arbol de forma "inorder"
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);///vamos a la extrema izquierda
        mostrarPersona(arbol->p);///mostramos los datos de la persona cargada en ese nodo del arbol
        inorder(arbol->der);///vamos a la extrema derecha
    }
}

void preorder(nodoArbol * arbol)///mostramos el arbol de forma "preorder"
{
    if(arbol!=NULL)
    {
        mostrarPersona(arbol->p);///mostramos los datos de la persona cargada en ese nodo del arbol
        preorder(arbol->izq);///vamos a la extrema izquierda
        preorder(arbol->der);///vamos a la extrema derecha
    }
}

void postorder(nodoArbol * arbol)///mostramos el arbol de forma "postorder"
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);///vamos a la extrema izquierda
        postorder(arbol->der);///vamos a la extrema derecha
        mostrarPersona(arbol->p);///mostramos los datos de la persona cargada en ese nodo del arbol
    }
}

void mostrarArbol (nodoArbol * arbol, int orden)
{///mostramos el arbol segun el orden que recivamos (orden)
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

nodoArbol * nodoMasDerecho(nodoArbol * arbol)///buscamos el nodo mas a la derecha
{
    nodoArbol * aux;/// ////////////////////////////////// aca no iria lo de malloc?????
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

nodoArbol * borrarNodoArbol (nodoArbol * arbol, char nombre [])///buscamos un nodoArbol por nombre y lo eliminamos
{
    if(arbol)///primero comprobamos que el arbol exista
    {
        if(strcmp(nombre,arbol->p.nombreApellido)>0)///si el nombre es "mayor" seguimos buscando a la derecha del arbol
        {
            arbol->der=borrarNodoArbol(arbol->der, nombre);
        }
        else if (strcmp(nombre,arbol->p.nombreApellido)<0)///si el nombre es "menor" seguimos buscando a la izquierda
        {
            arbol->izq=borrarNodoArbol(arbol->izq, nombre);
        }
        else/// ////////////////////ayudame a explicar esto por que tengo sueño////////////////////////////////////////////////
            /// ////////////////////ayudame a explicar esto por que tengo sueño////////////////////////////////////////////////
            /// ////////////////////ayudame a explicar esto por que tengo sueño////////////////////////////////////////////////
            /// ////////////////////ayudame a explicar esto por que tengo sueño////////////////////////////////////////////////
            /// ////////////////////ayudame a explicar esto por que tengo sueño////////////////////////////////////////////////
            /// ////////////////////ayudame a explicar esto por que tengo sueño////////////////////////////////////////////////
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
                free(arbol);///SE LIBRE ARBOL, SE LIBRE!!!!!!!
                arbol=NULL;
            }
        }
    }
    return arbol;
}
nodoArbol * ArchiToArbol (char nombre[],nodoArbol * arbol)///pasamos los datos del archivo a un arbol binario
{
    persona aux;///creamos una persona auxiliar
    FILE * archi=fopen(nombre,"rb");///abrimos el archivo en modo lectura para comprobar que existe
    if (archi==NULL)
    {
        printf("No se encontro el archivo\n");
    }
    else
    {
        while (!feof(archi))
        {
            fread(&aux,sizeof(persona),1,archi);
            if (!feof(archi))///mientras que no se supere el final del archivo
            {
                arbol=insertarNodoArbol(arbol,aux);///insertamos en arbol un nodoArbol con la persona aux
            }
        }
    }
    fclose(archi);///cerramos el arvhibo

    return arbol;///retornamos arbol para guardar los parametros ya que no usamos punteros dobles
}

