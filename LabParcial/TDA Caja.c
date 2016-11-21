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

int Subarreglo (caja cajita[], caja aux[12], int tipopago)
{
    int i=0,u=0;
    while (i<12)
    {
        /*if ((cajita[i].tipo_pago==tipopago) || (cajita[i].tipo_pago==3) && cajita[i].abiertaOcerrada==1)
        {
            aux[u]=cajita[i];
            printf("%d",tipopago);

            u++;

        }
        i++;*/
        if (cajita[i].abiertaOcerrada==1)
        {
            if (cajita[i].tipo_pago==tipopago)
            {
                aux[u]=cajita[i];
                u++;
            }
            if (cajita[i].tipo_pago==3)
            {
                aux[u]=cajita[i];
                u++;
            }
        }
        i++;

    }

    return u;
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

/*void agregarClientePreorden(nodoArbol * arbol, caja cajita[])
{

    caja aux[12];
    int cantsub=0;
    int i=0;
    int cantclientes=0;
    int menor=0;

    int posmenor=0;
    int tipopago=0;

    if(arbol!=NULL)
    {
        printf("\nA\n");
        tipopago=arbol->p.tipo_pago;
        printf("%d",tipopago);
        cantsub=Subarreglo((cajita),(aux),tipopago);
        printf("\nB\n");
        menor=contarClientesCaja(aux[i]);
        printf("\nC\n");
        posmenor=i;
        i++;
        while (i<cantsub)
        {

            cantclientes=contarClientesCaja(aux[i]);
            if (cantclientes<menor)
            {
                menor=cantclientes;
                posmenor=i;

            }
            i++;
        }

        aux[posmenor]=agregarSegunAlgoritmo(aux[posmenor],arbol->p);
        agregarClientePreorden(arbol->izq,&cajita);
        agregarClientePreorden(arbol->der,&cajita);
        pasarAuxACaja(aux[posmenor],cajita);
    }


}*/

int evaluar_caja_con_menos_clientes (caja  cajita[], int tipoPago)
{
    int i=0;
    int u=0;
    int c=0;
    int menor=0;
    int posmenor=0;

    caja aux[12];

    while (i<12)
    {
        if (cajita[i].tipo_pago==tipoPago)
        {
            aux[u]=cajita[i];
            u++;
        }
        if (cajita[i].tipo_pago==3)
        {
            aux[u]=cajita[i];
            u++;
        }
        i++;
    }

    menor=contarClientesCaja(aux[posmenor]);
    c++;
    while (c<u)
    {
        if (menor>contarClientesCaja(aux[c]))
        {
            menor=contarClientesCaja(aux[c]);

            posmenor=c;
        }
        c++;

    }
    int j=0;
    while (j<12)
    {
        if (cajita[j].nro_de_caja==aux[posmenor].nro_de_caja)
        {
            posmenor=j;
        }
        j++;
        printf("\nj=%d",j);
    }
    return posmenor;
}

void agregarClientePreorden(nodoArbol * arbol, caja cajita[])
{
    int tipoPago;
    int pos_menor;
    persona aux;
    if (arbol==NULL)
    {
        printf("\nERROR\nEl arbol no existe");
    }
    else
    {
        aux=arbol->p;
        tipoPago=aux.tipo_pago;
        pos_menor=evaluar_caja_con_menos_clientes(cajita,tipoPago);
        agregar(&cajita[pos_menor].filita,aux);
        agregarClientePreorden(arbol->izq,cajita);
        agregarClientePreorden(arbol->der,cajita);
    }
}

/*void agregarClienteInorden(nodoArbol * arbol, caja cajita[])
{
    caja aux[12];
    int cantsub=0;
    int i=0;
    int cantclientes=0;
    int menor;
    int posmenor;
    int tipopago=0;


    if(arbol!=NULL)
    {
        agregarClienteInorden(arbol->izq,cajita);
        tipopago=arbol->p.tipo_pago;
        cantsub=Subarreglo(&(cajita),aux,tipopago);
        menor=contarClientesCaja(aux[i]);
        posmenor=i;
        while (i<cantsub)
        {
            cantclientes=contarClientesCaja(aux[i]);
            if (cantclientes<menor)
            {
                menor=cantclientes;
                posmenor=i;
            }
            i++;
        }
        agregar(&aux[posmenor].filita,arbol->p);
        agregarClienteInorden(arbol->der,cajita);
        pasarAuxACaja(aux[posmenor],(&cajita));

    }
}

void agregarClientePostorden(nodoArbol * arbol, caja cajita[])
{
    caja aux[12];
    int cantsub=0;
    int i=0;
    int cantclientes=0;
    int menor;
    int posmenor;
    int tipopago=0;

    if(arbol!=NULL)
    {
        agregarClientePostorden(arbol->izq,cajita);
        agregarClientePostorden(arbol->der,cajita);
        tipopago=arbol->p.tipo_pago;
        cantsub=Subarreglo(&(cajita),aux,tipopago);
        menor=contarClientesCaja(aux[i]);
        posmenor=i;
        i++;
        while (i<cantsub)
        {
            cantclientes=contarClientesCaja(aux[i]);
            if (cantclientes<menor)
            {
                menor=cantclientes;
                posmenor=i;
            }
            i++;
        }
        agregar(&aux[posmenor].filita,arbol->p);
        pasarAuxACaja(aux[posmenor],(&cajita));
        printf("ACAESTAELPROBLEMA");
    }
}*/

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
        //agregarClienteInorden(raiz,cajita);
    }
    else
    {
        //agregarClientePostorden(raiz,cajita);
    }
    //return cajita;
}

void pasarAuxACaja (caja aux, caja cajita[])
{
    int i=0,flag=0;
    while (i<12 && flag==0)
    {
        if (strcmp(aux.nombreCajero,cajita[i].nombreCajero)==0)
        {
            cajita[i]=aux;
            flag=1;
        }
        i++;
    }
}

caja agregarFIFO (caja cajita, persona a)
{
    agregar(&cajita.filita,a);

    return cajita;
}

caja agregarPrioridadesA(caja cajita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    if (filaVacia(&cajita.filita)==0)
    {
        agregar(&cajita.filita,a);
    }
    else
    {
        int prioridad=a.tipo_cliente;
        Fila * aux=&(cajita.filita);
        nodo * seg=aux->primero;
        while (seg->cliente.tipo_cliente<=prioridad && seg!=NULL)
        {
            seg=seg->siguiente;
        }
        if (seg==NULL)
        {
            agregar(&(cajita.filita),a);
        }
        else
        {
            seg->siguiente=nuevo;
            nuevo->anterior=seg;
        }
    }
    return cajita;
}

caja agregarPrioridadesNA(caja cajita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    if (filaVacia(&cajita.filita)==0)
    {
        agregar((&cajita.filita),a);
    }
    else
    {
        int prioridad=a.tipo_cliente;
        Fila * aux=&(cajita.filita);
        nodo * ante=aux->primero;
        nodo * seg=ante->siguiente;
        while (seg!=NULL && seg->cliente.tipo_cliente<=prioridad)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if (seg==NULL)
        {
            agregar(&cajita.filita,a);
        }
        else
        {
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            nuevo->siguiente=seg;
            seg->anterior=nuevo;
        }
    }
    return cajita;
}

caja agregarSRTF (caja cajita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    if (filaVacia(&cajita.filita)==0)
    {
        agregar((&cajita.filita),a);
    }
    else
    {
        int cantidad=a.cantArticulos;
        Fila * aux=&(cajita.filita);
        nodo * ante=aux->primero;
        nodo * seg=ante->siguiente;
        while (seg!=NULL && seg->cliente.cantArticulos<=cantidad)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if (seg==NULL)
        {
            agregar(&cajita.filita,a);
        }
        else
        {
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            nuevo->siguiente=seg;
            seg->anterior=nuevo;
        }
    }
    return cajita;
}

caja agregarSJF (caja cajita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    if (filaVacia(&cajita.filita)==0)
    {
        agregar((&cajita.filita),a);
    }
    else
    {
        int cantidad=a.cantArticulos;
        Fila * aux=&(cajita.filita);
        nodo * ante=aux->primero;
        nodo * seg=ante->siguiente;
        while (seg!=NULL && seg->cliente.cantArticulos<=cantidad)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if (seg==NULL)
        {
            agregar(&cajita.filita,a);
        }
        else
        {
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            nuevo->siguiente=seg;
            seg->anterior=nuevo;
        }
    }
    return cajita;
}

caja agregarRR(caja cajita, persona a)
{
    nodo * nuevo=crearNodoLista(a);
    if (filaVacia(&cajita.filita)==0)
    {
        agregar((&cajita.filita),a);
    }
    else
    {
        int prioridad=a.tipo_cliente;
        Fila * aux=&(cajita.filita);
        nodo * ante=aux->primero;
        nodo * seg=ante->siguiente;
        while (seg!=NULL && seg->cliente.tipo_cliente<=prioridad)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if (seg==NULL)
        {
            agregar(&cajita.filita,a);
        }
        else
        {
            ante->siguiente=nuevo;
            nuevo->anterior=ante;
            nuevo->siguiente=seg;
            seg->anterior=nuevo;
        }
    }
    return cajita;
}




caja agregarSegunAlgoritmo (caja cajita, persona a)
{
    char fifo[]= {"FIFO"};
    char prioridadesa[]= {"PRIORIDADES A"};
    char prioridadesna[]= {"PRIORIDADES NA"};
    char srtf[]= {"SRTF"};
    char sjf[]= {"SJF"};
    char rr[]= {"RR"};

    if (strcmp(cajita.algoritmoPlanificacion,fifo)==0)
    {
        cajita=agregarFIFO(cajita,a);
    }
    else if (strcmp(cajita.algoritmoPlanificacion,prioridadesa)==0)
    {
        cajita=agregarPrioridadesA(cajita,a);
    }
    else if (strcmp(cajita.algoritmoPlanificacion,prioridadesna)==0)
    {
        cajita=agregarPrioridadesNA(cajita,a);
    }
    else if (strcmp(cajita.algoritmoPlanificacion,srtf)==0)
    {
        cajita=agregarSRTF(cajita,a);
    }
    else if (strcmp(cajita.algoritmoPlanificacion,sjf)==0)
    {
        cajita=agregarSJF(cajita,a);
    }
    else if (strcmp(cajita.algoritmoPlanificacion,rr)==0)
    {
        cajita=agregarRR(cajita,a);
    }

    return cajita;
}
