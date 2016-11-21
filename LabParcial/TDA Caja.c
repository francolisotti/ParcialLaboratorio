#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"


void abrir_cajas_(caja cajita[])
{
    char opcion='s';
    char opcion2='s';
    int i=0;
    printf("\nDesea abrir todas las cajas? s/n: ");
    fflush(stdin);
    scanf("%c",&opcion);
    if (opcion=='s')
    {
        for (i=0; i<12; i++)
        {
            cajita[i].abiertaOcerrada=1;
        }
    }
    else
    {
        printf("\nDesea abrir alguna caja s/n: ");
        fflush(stdin);
        scanf("%c", &opcion2);
        if (opcion2=='s')
        {
            for (i=0; i<12; i++)
            {
                mostrarCaja(cajita[i]);
                printf("\nDesea abrir esta caja: s/n: ");
                fflush(stdin);
                scanf("%c",&opcion2);
                if (opcion2=='s')
                {
                    cajita[i].abiertaOcerrada=1;
                }
            }
        }

    }
}

caja abrirOcerrarCaja (caja cajita)
{
    if (cajita.abiertaOcerrada == 1)
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
        puts("------------------------------------------");
        printf("Caja numero: %d",cajita.nro_de_caja);
        if(cajita.abiertaOcerrada==1)
        {
            printf("\nCaja abierta");
        }
        else
        {
            printf("\nCaja cerrada");
        }
        printf("\nalgoritmo de planificacion: %s",cajita.algoritmoPlanificacion);
        printf("\nCajero: %s",cajita.nombreCajero);

        if (cajita.tipo_pago==1)
        {
            printf("\nPago: Efectivo");
        }
        else if (cajita.tipo_pago==2)
        {
            printf("\nPago: debito/credito");
        }
        else
        {
            printf("\nPago: todos");
        }

        /* char control='s';
         printf("\nDesea mostrar la fila? s/n: ");
         scanf("%c", &control);*/

        // if(control == 's')
        //{
        printf("\nFila:\n");
        mostrar(&cajita.filita);
        //}
        puts("\n------------------------------------------");
    }

    else
    {
        printf("\nLa caja no existe");
    }
}

void pasarDeArchiAcaja (char archiCajas[], caja cajita[])
{
    FILE * archi=fopen(archiCajas,"rb");
    int i=0;
    caja aux;
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(caja),1,archi)>0)
        {
            cajita[i]=aux;
            inicFila(&(cajita[i].filita));
            i++;
        }
    }
    fclose(archi);
}


int contarClientesCaja (caja cajita)
{
    int cont=0;
    Fila seg=cajita.filita;
    nodo * aux;
    int x=0;
    if (filaVacia(&seg)==1)
    {

        aux=seg.primero;
        while (aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
            cont++;
        }
    }
    return cont;
}

int evaluar_caja_con_menos_clientes (caja  cajita[], int tipoPago)
{
    int i=0;
    int u=0;
    int flag=0;
    int menor=0;
    int posmenor=0;

    while (flag==0)
    {
        if (cajita[i].tipo_pago==tipoPago)
        {
            flag=1;
            posmenor=i;
            menor=contarClientesCaja(cajita[posmenor]);
        }
        i++;
    }
    while (i<12)
    {
        if (cajita[i].tipo_pago==tipoPago)
        {
            if (menor>contarClientesCaja(cajita[i]))
            {
                menor=contarClientesCaja(cajita[i]);
                posmenor=i;
            }

        }
        i++;
    }
    return posmenor;
}

void agregarClienteACaja (caja cajita[], nodoArbol * raiz)
{
    int recorrido;
    printf("\nElija el algoritmo de recorrido: ");
    scanf("%d", &recorrido);
    while (recorrido>3 && recorrido<1)
    {
        printf("ERROR, algoritmo no existente, ingrese nuevamente: ");
        scanf("%d", &recorrido);
    }
    if (recorrido==1)
    {
        agregarClientePreorden(raiz,cajita);
    }
    else if (recorrido==2)
    {
        agregarClienteInorden(raiz,cajita);
    }
    else
    {
       agregarClientePostorden(raiz,cajita);
    }
}

void agregarPrioridadesA(Fila * filita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    filita->primero=agregarEnOrdenTipoCliente(filita->primero,nuevo);
}

void agregarPrioridadesNA(Fila * filita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    filita->primero=agregarEnOrdenTipoCliente(filita->primero,nuevo);
}

void agregarSRTF (Fila * filita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    filita->primero=agregarEnOrdenPorCant(filita->primero,nuevo);
}

void agregarSJF (Fila * filita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    filita->primero=agregarEnOrdenPorCant(filita->primero,nuevo);
}

void agregarSegunAlgoritmo (Fila * filita, persona a, char algoritmo[])
{
    char fifo[]= {"FIFO"};
    char prioridadesa[]= {"PRIORIDADES A"};
    char prioridadesna[]= {"PRIORIDADES NA"};
    char srtf[]= {"SRTF"};
    char sjf[]= {"SJF"};
    char rr[]= {"RR"};
    printf("%s ",algoritmo);

    if (strcmp(algoritmo,fifo)==0)
    {
        agregar(filita,a);
    }
    else if (strcmp(algoritmo,prioridadesa)==0)
    {
        agregarPrioridadesA(filita,a);
    }
    else if (strcmp(algoritmo,prioridadesna)==0)
    {
        agregarPrioridadesNA(filita,a);
    }
    else if (strcmp(algoritmo,srtf)==0)
    {
        agregarSRTF(filita,a);
    }
    else if (strcmp(algoritmo,sjf)==0)
    {
        agregarSJF(filita,a);
    }
    else if (strcmp(algoritmo,rr)==0)
    {
        agregar(filita,a);
    }
}

void agregarClientePreorden(nodoArbol * arbol, caja cajita[])
{
    int tipoPago;
    int pos_menor;
    persona aux;
    if (arbol==NULL)
    {
    }
    else
    {
        aux=arbol->p;
        tipoPago=aux.tipo_pago;
        pos_menor=evaluar_caja_con_menos_clientes(cajita,tipoPago);
        agregarSegunAlgoritmo(&cajita[pos_menor].filita,aux,cajita[pos_menor].algoritmoPlanificacion);
        agregarClientePreorden(arbol->izq,cajita);
        agregarClientePreorden(arbol->der,cajita);
    }
}

void agregarClienteInorden(nodoArbol * arbol, caja cajita[])
{
     int tipoPago;
    int pos_menor;
    persona aux;
    if (arbol==NULL)
    {
    }
    else
    {
        agregarClienteInorden(arbol->izq,cajita);
        aux=arbol->p;
        tipoPago=aux.tipo_pago;
        pos_menor=evaluar_caja_con_menos_clientes(cajita,tipoPago);
        agregarSegunAlgoritmo(&cajita[pos_menor].filita,aux,cajita[pos_menor].algoritmoPlanificacion);
        agregarClienteInorden(arbol->der,cajita);
    }
}

void agregarClientePostorden(nodoArbol * arbol, caja cajita[])
{
        int tipoPago;
    int pos_menor;
    persona aux;
    if (arbol==NULL)
    {
    }
    else
    {
        agregarClientePreorden(arbol->izq,cajita);
        agregarClientePreorden(arbol->der,cajita);
        aux=arbol->p;
        tipoPago=aux.tipo_pago;
        pos_menor=evaluar_caja_con_menos_clientes(cajita,tipoPago);
        agregarSegunAlgoritmo(&cajita[pos_menor].filita,aux,cajita[pos_menor].algoritmoPlanificacion);
    }
}
