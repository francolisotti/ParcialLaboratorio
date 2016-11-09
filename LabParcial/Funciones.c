#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
/// Archivos


void mostrarArchivo (char nombre[])
{
    FILE * archi;
    archi=fopen(nombre, "rb");
    persona aux;
    int i=0;
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(persona),1,archi)>0)
        {
            mostrarPersona(aux);
            i++;
        }
        printf("\nElementos mostrados: %d\n",i);
    }
    else
    {
        printf("\nEl archivo no esta cargado");
    }
    fclose(archi);
}



void mostrarArchivoCaja (char nombre[])
{
    FILE * archi;
    archi=fopen(nombre, "rb");
    caja aux;
    int i=0;
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(caja),1,archi)>0)
        {
            mostrarCaja(aux);
            i++;
        }
        printf("\nElementos mostrados: %d\n",i);
    }
    else
    {
        printf("\nEl archivo no esta cargado");
    }
    fclose(archi);
}

///TDA Persona


persona nuevo_Persona()
{
    char nombreApellido[40];
    int cantArticulos,tipo_Cliente,tipo_Pago;
    persona nuevo;

    printf("\nNombre y Apellido: ");
    fflush(stdin);
    gets(&nombreApellido);
    printf("\nCantidad de articulos: ");
    scanf("%d", &cantArticulos);
    printf("\nTipo de cliente (1: embarazada, 2: jubilado y 3: normal): ");
    scanf("%d", &tipo_Cliente);
    printf("\nTipo de pago (1 efectivo, 2 crédito o débito, 3 todos): ");
    scanf("%d", &tipo_Pago);

    nuevo=crearPersona(nombreApellido,cantArticulos,tipo_Cliente,tipo_Pago);

    return nuevo;
}

persona crearPersona (char nombreApellido[], int cantArticulos,int tipo_Cliente,int tipo_Pago)
{
    persona aux;

    strcpy(aux.nombreApellido,nombreApellido);
    aux.cantArticulos=cantArticulos;
    aux.tipo_cliente=tipo_Cliente;
    aux.tipo_pago=tipo_Pago;

    ///reparar
    aux.tiempoDeEspera=0;
    aux.tiempoProcesado=0;
    ///reparar

    return aux;
}

/*void cargarPersona (char nombreDelArchivo[])
{
    char nombreApellido[40];
    int cantArticulos,tipo_Cliente,tipo_Pago;

    persona aux;

    char control;
    printf("\nDesea cargar los datos de una persona? s/n: ");
    fflush(stdin);
    scanf("%c", &control);
    while (control=='s')
    {
        aux=nuevo_Persona();
        archivarPersona(nombreDelArchivo,aux);


        printf("\nDesea continuar? s/n: ");
        fflush(stdin);
        scanf("%c", &control);
    }
}*/

void mostrarPersona(persona aux)
{
    printf("\n                                                 Nombre y Apellido: %s", aux.nombreApellido);
    printf("\n                                             Cantidad de articulos: %d", aux.cantArticulos);
    printf("\n                                                  Tiempo de espera: %d", aux.tiempoDeEspera);
    printf("\n                                               Tiempo de procesado: %d", aux.tiempoProcesado);
    printf("\nTipo de cliente (prioridad 1: embarazada, 2: jubilado y 3: normal): %d", aux.tipo_cliente);
    printf("\n               Tipo pago (1 efectivo, 2 crédito o débito, 3 todos): %d\n", aux.tipo_pago);

}

///TDA Arbol

int selectOrden (int orden)
{
    printf("Decida el orden en que se va a mostrar el arbol\nSiendo 1 preorden,2 inorden y 3 postorden: ");
    scanf("%d\n",orden);
    while ((orden > 3) && (orden <1))
    {
        printf("Ingrese nuevamente del 1 al 3 por favor: ");
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
    aux->p.cantArticulos=NULL;
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
        puts("------------------------------------------\n");
        printf("             Nombre del cliente: %d\n", arbol->p.nombreApellido);
        printf("          Articulos del cliente: %d\n", arbol->p.cantArticulos);
        printf("   Tiempo de espera del cliente: %d\n", arbol->p.tiempoDeEspera);
        printf("Tiempo de procesado del cliente: %d\n", arbol->p.tiempoProcesado);
        printf("                Tipo de cliente: %d\n", arbol->p.tipo_cliente);
        printf("       Tipo de pago del cliente: %d\n", arbol->p.tipo_pago);
        puts("------------------------------------------\n");
        inorder(arbol->der);
    }
}

void preorder(nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        puts("------------------------------------------\n");
        printf("             Nombre del cliente: %d\n", arbol->p.nombreApellido);
        printf("          Articulos del cliente: %d\n", arbol->p.cantArticulos);
        printf("   Tiempo de espera del cliente: %d\n", arbol->p.tiempoDeEspera);
        printf("Tiempo de procesado del cliente: %d\n", arbol->p.tiempoProcesado);
        printf("                Tipo de cliente: %d\n", arbol->p.tipo_cliente);
        printf("       Tipo de pago del cliente: %d\n", arbol->p.tipo_pago);
        puts("------------------------------------------\n");
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
        puts("------------------------------------------\n");
        printf("             Nombre del cliente: %d\n", arbol->p.nombreApellido);
        printf("          Articulos del cliente: %d\n", arbol->p.cantArticulos);
        printf("   Tiempo de espera del cliente: %d\n", arbol->p.tiempoDeEspera);
        printf("Tiempo de procesado del cliente: %d\n", arbol->p.tiempoProcesado);
        printf("                Tipo de cliente: %d\n", arbol->p.tipo_cliente);
        printf("       Tipo de pago del cliente: %d\n", arbol->p.tipo_pago);
        puts("------------------------------------------\n");
    }
}

void mostrarArbol (nodoArbol * arbol, int orden)
{
    if(arbol)
    {
        printf("adasd");
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

///TDA Lista

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

///TDA arreglo fila

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
    mostrarLista(filita->primero);
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
/// TDA caja
caja abrirOcerrarCaja (caja cajita)
{
    if (cajita.abiertaOcerrada= 1)
    {
        cajita.abiertaOcerrada= 0;
    }
    else
    {
        cajita.abiertaOcerrada= 1;
    }
    return cajita;
}

caja buscarCaja(caja A[], int buscada)
{
    int i=0;
    if((A[i].nro_de_caja!=buscada) && (buscada<=12))
    {
        while (A[i].nro_de_caja!=buscada)
        {
            i++;
        }
    }
    return A[i];
}

void mostrarCaja(caja cajita)
{
    if((cajita.nro_de_caja>0) && (cajita.nro_de_caja<=12))
    {
        puts("------------------------------------------\n");
        if(cajita.abiertaOcerrada=1)
        {
            printf("La caja esta abierta\n");
        }
        else
        {
            printf("La caja esta cerrada\n");
        }
        printf("Su algortmo de planificacion es: %s\n",cajita.algoritmoPlanificacion);
        printf("Su cajero es: %s\n",cajita.nombreCajero);
        printf("Esta es la caja numero: %d\n",cajita.nro_de_caja);
        if (cajita.tipo_pago=1)
        {
            printf("Su metodo de pago es solo efectivo\n");
        }
        else if (cajita.tipo_pago=2)
        {
            printf("Su metodo de pago es debito/tarjeta\n");
        }
        else
        {
            printf("Se acepta todo metodo de pago en esta caja\n");
        }
        char control= 's';
        puts("------------------------------------------\n");
        printf("Desea mostrar la fila?\n");
        fflush(stdin);
        scanf("%c",&control);
        if(control == 's')
        {
            mostrar(&cajita.filita);
        }
        puts("------------------------------------------\n");
    }
    else
        printf("la caja no existe\n");
}


/*

pasarArbolACaja (nodoArbol * arbol, caja cajita[])
{
    int tipopago=arbolp.tipo_pago;
    if (tipopago==1)
    {
        cajita[].filita.ultimo.cliente=arbol.p;
    }
}

agregarClientePreorden(nodoArbol * arbol, caja cajita[])
{
    if(arbol!=NULL)
    {
        pasarArbolCaja
        agregarClientePreorden(arbol->izq,cajita);
        agregarClientePreorden(arbol->der,cajita);
}


caja agregarClienteACaja (caja cajita[], nodoArbol * raiz)
{
    int recorrido;
    printf("\nElija el algoritmo de recorrido (Siendo 1 preorden,2 inorden y 3 postorden): ");
    scanf("%d", &recorrido);
    while (recorrido>3 && recorrido<1)
    {
        printf("ERROR, algoritmo no existente, ingrese nuevamente, (1 preorden,2 inorden y 3 postorden): ");
        scanf("%d", &recorrido);
    }
    if (recorrido==1)
    {

    }
    else if (recorrido==2)
    {

    }
    else
    {

    }
    return cajita;
}

*/






















