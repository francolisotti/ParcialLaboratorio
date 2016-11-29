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

    strcpy(aux->p.nombreApellido,p.nombreApellido);///asignamos los valores de p a aux
    aux->p.tipo_cliente=p.tipo_cliente;
    aux->p.tipo_pago=p.tipo_pago;
    aux->p.cantArticulos=p.cantArticulos;
    aux->p.tiempoDeEspera=NULL;
    aux->p.tiempoProcesado=NULL;

    aux->izq=NULL;
    aux->der=NULL;

    return aux;///retornamos aux que sera el nuevo nodoArbol
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
        if(orden==1)///con esto evaluamos el orden a utilizar
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
    nodoArbol * aux;///lo usamos para recorrer el arbol
    if(!arbol->der)///si ya no hay mas nodos a la derecha, ese es el nodo mas derecho
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasDerecho(arbol->der);///sino seguimos buscando hacia la derecha
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * arbol)
{
    nodoArbol * aux;///lo usamos para recorrer el arbol
    if(!arbol->izq)///si ya no hay mas nodos a la izquierda, ese es el nodo mas izquierdo
    {
        aux=arbol;
    }
    else
    {
        aux=nodoMasIzquierdo(arbol->izq);///sino seguimos buscando hacia la izquierda
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
        }///esto lo usamos para que no recorra zonas en las que no puede estar (ah no ser que se haya cargado mal el arbol)
        else///sino (es decir si se encontro el nodo buscado)
        {
            if(arbol->izq)///asignamos las direcciones de memoria para no romper el arbol
            {
                arbol->p= (nodoMasDerecho(arbol->izq))->p;
                arbol->izq=borrarNodoArbol(arbol->izq, arbol->p.nombreApellido);
            }
            else if(arbol->der!=NULL)
            {
                arbol->p=(nodoMasIzquierdo(arbol->der))->p;
                arbol->der=borrarNodoArbol(arbol->der, arbol->p.nombreApellido);
            }
            else///borramos el nodoArbol
            {
                free(arbol);
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
        while (!feof(archi))///tambien podria ser while (fread(&aux,sizeof(persona),1,archi)>0) sin el if (!feof(archi))
        {
            fread(&aux,sizeof(persona),1,archi);
            if (!feof(archi))///mientras que no se supere el final del archivo
            {
                arbol=insertarNodoArbol(arbol,aux);///insertamos en arbol un nodoArbol con la persona aux
            }
        }
    }
    fclose(archi);///cerramos el archivo

    return arbol;///retornamos arbol para guardar los parametros ya que no usamos punteros dobles
}

