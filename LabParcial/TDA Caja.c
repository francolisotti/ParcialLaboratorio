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

void mostrarArchiCaja (char archi_Caja[])
{
    FILE * archi=fopen(archi_Caja, "rb");
    caja aux;
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(caja),1,archi)>0)
        {
            inicFila(&(aux.filita));
            puts("\n------------------------------------------");
            mostrarCaja(aux);
            printf("\nAprete enter para continuar");
            getch();
        }
    }
    else
    {
        printf("\nERROR\nArchivo no encontrado");
    }
    fclose(archi);
}


void mostrarCaja(caja cajita)
{
    if((cajita.nro_de_caja>0) && (cajita.nro_de_caja<=12))
    {
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

        if (filaVacia(&cajita.filita)==1)
        {
            char control='s';
            printf("\nDesea mostrar la fila? s/n: ");
            fflush(stdin);
            scanf("%c", &control);

            if(control == 's')
            {
                printf("\nFila:\n");
                mostrar(&cajita.filita);
            }
        }
        puts("\n------------------------------------------");
    }

    else
    {
        printf("\nLa caja no existe");
    }
}

int pasarDeArchiAcaja_yContar (char archiCajas[], caja cajita[])
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
    return i;
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

void atenderClientes(caja cajita[])
{
    int i=0;
    char rr[]= {"RR"};
    while (i<12)
    {
        if (strcmp(cajita[i].algoritmoPlanificacion,rr)==0)
        {
            tiempo_de_espera_fila_RR(&cajita[i].filita);
        }
        else
        {
            tiempo_de_espera_fila(&cajita[i].filita);
        }
        i++;
    }
}

int agregarClienteACajaEnTiempoDeterminado(caja cajita[], int tiempo)
{
    persona cliente;
    cliente=nuevo_Persona();
    int tipodepago=cliente.tipo_pago;
    char control='s';
    int flag=0;
    int i=0;
    int posicion;
    while (i<12 && flag==0)
    {
        if (cajita[i].tipo_pago==tipodepago)
        {
            mostrarCaja(cajita[i]);
            printf("\nDesea cargar el cliente a esta caja? s/n: ");
            fflush(stdin);
            scanf("%c",&control);
            if (control=='s')
            {
                flag=1;
                posicion=i;
            }
        }
        i++;
    }
    char algoritmo[20];
    strcpy(algoritmo,cajita[posicion].algoritmoPlanificacion);
    agregarSegunAlgoritmoEnTiempo(&cajita[posicion].filita,cliente,algoritmo, tiempo);
    return posicion;
}

void agregarPrioridadesAEnTiempo(Fila * filita,persona a,int tiempo)
{
    nodo * aux;
    aux=filita->primero;
    while (0<tiempo)
    {
        if (aux->cliente.cantArticulos<=tiempo)
        {
            tiempo=tiempo-aux->cliente.cantArticulos;
            filita->primero=borrarPrimero(filita->primero);
        }
        else
        {
            aux->cliente.cantArticulos=aux->cliente.cantArticulos-tiempo;
            tiempo=0;
        }
    }
    agregarPrioridadesA(filita,a);
    tiempo_de_espera_fila(filita);
}


void agregarPrioridadesNAEnTiempo(Fila * filita,persona a,int tiempo)
{
    nodo * aux;
    aux=filita->primero;
    while (0<tiempo)
    {
        if (aux->cliente.cantArticulos<=tiempo)
        {
            tiempo=tiempo-aux->cliente.cantArticulos;
            filita->primero=borrarPrimero(filita->primero);
        }
        else
        {
            aux->cliente.cantArticulos=aux->cliente.cantArticulos-tiempo;
            tiempo=0;
        }
    }
    Fila * filosa=aux->siguiente;
    agregarPrioridadesNA(&filosa,a);
    tiempo_de_espera_fila(filita);
}

void agregarSRTFEnTiempo(Fila * filita, persona a,int tiempo)
{
    nodo * aux;
    aux=filita->primero;
    while (0<tiempo)
    {
        if (aux->cliente.cantArticulos<=tiempo)
        {
            tiempo=tiempo-aux->cliente.cantArticulos;
            filita->primero=borrarPrimero(filita->primero);
        }
        else
        {
            aux->cliente.cantArticulos=aux->cliente.cantArticulos-tiempo;
            tiempo=0;
        }
    }
    agregarSRTF(filita,a);
    tiempo_de_espera_fila(filita);
}

void agregarSJFEnTiempo(Fila * filita,persona a,int tiempo)
{
    nodo * aux;
    aux=filita->primero;
    while (0<tiempo)
    {
        if (aux->cliente.cantArticulos<=tiempo)
        {
            tiempo=tiempo-aux->cliente.cantArticulos;
            filita->primero=borrarPrimero(filita->primero);
        }
        else
        {
            aux->cliente.cantArticulos=aux->cliente.cantArticulos-tiempo;
            tiempo=0;
        }
    }
    Fila * filosa=aux->siguiente;
    agregarSJF(&filosa,a);
    tiempo_de_espera_fila(filita);
}

void agregarFIFOEnTiempo(Fila * filita, persona a, int tiempo)
{
    nodo * aux;
    aux=filita->primero;
    while (0<tiempo)
    {
        if (aux->cliente.cantArticulos<=tiempo)
        {
            tiempo=tiempo-aux->cliente.cantArticulos;
            filita->primero=borrarPrimero(filita->primero);
        }
        else
        {
            aux->cliente.cantArticulos=aux->cliente.cantArticulos-tiempo;
            tiempo=0;
        }
    }
    agregar(filita,a);
    tiempo_de_espera_fila(filita);
}

void agregarRREnTiempo(Fila * filita,persona a,int tiempo)
{
    nodo * aux;
    aux=filita->primero;
    while (0<tiempo)
    {
        if (aux->cliente.cantArticulos<=tiempo)
        {
            tiempo=tiempo-aux->cliente.cantArticulos;
            filita->primero=borrarPrimero(filita->primero);
        }
        else
        {
            aux->cliente.cantArticulos=aux->cliente.cantArticulos-tiempo;
            tiempo=0;
        }
    }
    Fila * filosa=aux->siguiente;
    agregar(&filosa,a);
    tiempo_de_espera_fila(filita);
}


void agregarSegunAlgoritmoEnTiempo(Fila * filita, persona a, char algoritmo[], int tiempo)
{
    char fifo[]= {"FIFO"};
    char prioridadesa[]= {"PRIORIDADES A"};
    char prioridadesna[]= {"PRIORIDADES NA"};
    char srtf[]= {"SRTF"};
    char sjf[]= {"SJF"};
    char rr[]= {"RR"};

    if (strcmp(algoritmo,fifo)==0)
    {
        agregarFIFOEnTiempo(filita,a,tiempo);
    }
    else if (strcmp(algoritmo,prioridadesa)==0)
    {
        agregarPrioridadesAEnTiempo(filita,a,tiempo);
    }
    else if (strcmp(algoritmo,prioridadesna)==0)
    {
        agregarPrioridadesNAEnTiempo(filita,a,tiempo);
    }
    else if (strcmp(algoritmo,srtf)==0)
    {
        agregarSRTFEnTiempo(filita,a,tiempo);
    }
    else if (strcmp(algoritmo,sjf)==0)
    {
        agregarSJFEnTiempo(filita,a,tiempo);
    }
    else if (strcmp(algoritmo,rr)==0)
    {
        /// no se agregarRREnTiempo(filita,a,tiempo);
    }


}

void vaciar_cajas (caja cajita[], int validos)
{
    int i=0;
    while(i<validos)
    {
        vaciar_fila(cajita[i],0);
        i++;
    }
}

void vaciar_fila(caja cajita[], int op)
{
    Fila * filita;
    while (filaVacia(&cajita.filita)==1)
    {
        filita=(&cajita.filita);
        if (op==1)
        {

            mostrar(filita->primero);
            atenderClientes(cajita);
        }
        filita->primero=borrarPrimero(&cajita.filita->primero);
    }
}

void promedioCajas (caja cajita[],int validos, float promediosE[], float promediosR)
{
    int promedio=0;
    int cant=0;
    int sumaE=0;
    int sumaR=0;
    atenderClientes(cajita);
    Fila * filita;
    nodo * aux;
    int i=0;

    while (i<validos)
    {
        filita=cajita[i].filita;
        aux=filita->primero;
        while (aux!=NULL)
        {
            sumaR=sumaR+aux->cliente.tiempoProcesado;
            sumaE=sumaE+aux->cliente.tiempoDeEspera;
            cant++;
            aux=aux->siguiente;

        }


        i++;
    }
}

