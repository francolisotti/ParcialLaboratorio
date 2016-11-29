#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"

caja abrirOcerrarCaja (caja cajita)
{
    if (cajita.abiertaOcerrada == 1)///si la caja estaba abierta la cierra
    {
        cajita.abiertaOcerrada= 0;
    }
    else///sino la abre
    {
        cajita.abiertaOcerrada= 1;
    }
    return cajita;///retorna la caja ya que aca no la recive como puntero en tonces no se modificaria
}

caja buscarCaja(caja A[], int buscada)
{
    int i=0;
    if((A[i].nro_de_caja!=buscada) && (buscada<=12))///corroboramos que no este buscando un numero de caja que no pueda existir
    {
        while (A[i].nro_de_caja!=buscada)
        {
            i++;///aumentamos i mientras que no encontremos la caja buscada
        }
    }
    return A[i];///debolbemos la caja buscada
}

void mostrarArchiCaja (char archi_Caja[])
{
    FILE * archi=fopen(archi_Caja, "rb");///abrimos el archivo en modo lectura
    caja aux;///creamos una caja auxiliar que tenga los datos que iremos leyendo del archivo, se pisara a si misma
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(caja),1,archi)>0)///mientras que el archivo no este vacio
        {
            inicFila(&(aux.filita));
            puts("\n------------------------------------------");
            mostrarCaja(aux);
            printf("\nPrecione cualquier tecla para continuar");
            getch();///esto lo hacemos para que no muestre todo de golpe y poder leer mejor cada dato
        }
    }
    else
    {
        printf("\nERROR, archivo no encontrado");
    }
    fclose(archi);///cerramos el archivo
}


void mostrarCaja(caja cajita)
{
    char rr[]= {"RR"}; ///esto lo necesitaremos ya que las de tipo round robin se muestran de forma diferente
    if((cajita.nro_de_caja>0) && (cajita.nro_de_caja<=12))
    {
        printf("Caja numero: %d",cajita.nro_de_caja);
        if(cajita.abiertaOcerrada==1)///para no mostrar caja: 1 o 0 si esta abierta o cerrada
        {
            ///lo evaluamos y el usuario solo lee Caja abierta o cerrada
            printf("\nCaja abierta");
        }
        else
        {
            printf("\nCaja cerrada");
        }
        printf("\nalgoritmo de planificacion: %s",cajita.algoritmoPlanificacion);
        printf("\nCajero: %s",cajita.nombreCajero);

        if (cajita.tipo_pago==1)///aca hacemos lo mismo que con caja abierta o cerrada
        {
            printf("\nPago: Efectivo");
        }
        else if (cajita.tipo_pago==2)///evaluamos el tipo de pago
        {
            printf("\nPago: debito/credito");///y lo mostramos con palabras
        }
        else
        {
            printf("\nPago: todos");
        }
        int contador=1;
        int flag=0;
        if (filaVacia(&cajita.filita)==1)///si la fila no esta vacia
        {
            char control='s';
            printf("\nDesea mostrar la fila? s/n: ");///preguntamos si desea mostrarla
            fflush(stdin);
            scanf("%c", &control);

            if(control == 's')///si desea mostrarla
            {
                if (strcmp(cajita.algoritmoPlanificacion,rr)==0)///si es round robin
                {
                    Fila * filita=&cajita.filita;
                    nodo * aux=filita->primero;
                    while (flag==0 && filaVacia(aux)==1)///mientras la fila no este vacia
                    {
                        printf("\nFila:\n");
                        system("cls");
                        nodo * aux=filita->primero;

                        mostrarLista(filita->primero);
                        aux->cliente.tiempoProcesado=(filita->primero->cliente.tiempoProcesado)+6;
                        aux->cliente.tiempoDeEspera=contador*6;

                        if ((filita->primero->cliente.tiempoProcesado)>=(filita->primero->cliente.cantArticulos))
                        {
                            extraer(&cajita.filita);
                            contador++;
                        }
                        else
                        {
                            if (aux->siguiente==NULL)
                            {
                                inicFila(&filita);
                                flag=1;
                                printf("\nLa fila se ha vaciado.");
                                printf("\nPresione cualquier tecla.");
                                getch();

                            }
                            else
                            {
                                agregar(&cajita.filita,aux->cliente);
                                extraer(&cajita.filita);
                                printf("\nPresione cualquier tecla para sumar un quantum de 6 (seis)");
                                getch();
                            }

                            contador++;
                        }

                    }

                }
                else///si no es round robin
                {
                    printf("\nFila:\n");
                    mostrar(&cajita.filita);///mostramos la fila
                }
            }
        }
    }
    else///si la el numero de caja no es apropiado
    {
        printf("\nLa caja no existe");///le advertimos que la caja no existe
    }
}

int pasarDeArchiAcaja_yContar (char archiCajas[], caja cajita[])
{
    FILE * archi=fopen(archiCajas,"rb");///abrimos el archivo en modo lectura
    int i=0;
    caja aux;///creamos una caja aux para "guardar" los datos mientras pasamos todos los datos del archivo
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(caja),1,archi)>0)///mientras que no se termine el archivo
        {
            cajita[i]=aux;///guardamos en cajita[i] lo que tenemos en aux (es decir los datos del arvhico)
            inicFila(&(cajita[i].filita));///inicializamos la fila para que no se cargue basura
            i++;///aumentamos i para que no se picen los datos del arreglo de cajas
        }
    }
    fclose(archi);///cerramos el archivo
    return i;///retornamos la cantidad de cajas pasadas
}

int contarClientesCaja (caja cajita)
{
    int cont=0;
    Fila seg=cajita.filita;///copiamos en una variable seguidora la fila en donde estan los clientes que queremos contar
    nodo * aux;
    if (filaVacia(&seg)==1)///si la fila no esta vacia
    {
        aux=seg.primero;
        while (aux->siguiente!=NULL)
        {
            aux=aux->siguiente;///recorremos la fila y contamos los clientes
            cont++;
        }
    }
    return cont;///retornamos la cantidad de clientes
}

int evaluar_caja_con_menos_clientes (caja  cajita[], int tipoPago)
{
    ///buscaremos la caja con menos clientes, dentro de las que tengan el tipo de pago correspondiente
    int i=0;
    int flag=0;
    int menor=0;
    int posmenor=-1;

    while (flag==0 && i<12)
    ///el flag indica que ya encontro la primer caja correspondiente
    ///ya que esta se comparara con las siguientes del mismo tipo de pago
    {
        ///mientras que no se supere el limite de cajas
        if ((cajita[i].tipo_pago==tipoPago) && (cajita[i].abiertaOcerrada==1))
        {
            ///si el tipo de pago coincide y la caja esta abierta
            flag=1;
            posmenor=i;
            menor=contarClientesCaja(cajita[posmenor]);
        }
        i++;
    }
    while (i<12)
    {
        ///seguimos comparando con las del mismo pago
        if ((cajita[i].tipo_pago==tipoPago) && (cajita[i].abiertaOcerrada==1))
        {
            if (menor>contarClientesCaja(cajita[i]))
            {
                menor=contarClientesCaja(cajita[i]);
                posmenor=i;
            }

        }
        i++;
    }
    return posmenor;///retornamos la poscicion de la caja con ese tipo de pago y menos clientes
}

int agregarClienteACaja (caja cajita[], nodoArbol * raiz)
{
    int recorrido;
    int cantidadclientes=0;
    printf("En que orden desea recorrer el arbol");
    printf("\n[1] Preorden");
    printf("\n[2] Inorden");
    printf("\n[3] Postorden");
    printf("\nIngrese un numero: ");
    scanf("%d", &recorrido);
    while (recorrido>3 || recorrido<1)///comprobamos que no introdusca una opcion incorrecta
    {
        printf("\nERROR, algoritmo no existente, ingrese nuevamente: ");
        scanf("%d", &recorrido);
    }
    if (recorrido==1)///vemos el recorrido que eligio y lo agregamos segun ese orden
    {
        cantidadclientes=agregarClientePreorden(raiz,cajita,cantidadclientes);
    }
    else if (recorrido==2)
    {
        cantidadclientes=agregarClienteInorden(raiz,cajita,cantidadclientes);
    }
    else
    {
        cantidadclientes=agregarClientePostorden(raiz,cajita,cantidadclientes);
    }
    return cantidadclientes;///retornamos la cantidad de clientes
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
    ///ahora veremos que tipo de algoritmo eligio el usuario y agregaremos teniendo en cuenta eso
    if (strcmp(algoritmo,fifo)==0)
    {
        agregar(filita,a);///en orden fde llegada
    }
    else if (strcmp(algoritmo,prioridadesa)==0)
    {
        agregarPrioridadesA(filita,a);///por prioridades apropiativo
    }
    else if (strcmp(algoritmo,prioridadesna)==0)
    {
        agregarPrioridadesNA(filita,a);///por prioridades no apropiativo
    }
    else if (strcmp(algoritmo,srtf)==0)
    {
        agregarSRTF(filita,a);///por menor cantidad de articulos apropiativo
    }
    else if (strcmp(algoritmo,sjf)==0)
    {
        agregarSJF(filita,a);///por menor cantidad de articulos no apropiativo
    }
    else if (strcmp(algoritmo,rr)==0)
    {
        agregar(filita,a);///round robin es fifo
    }
}

int agregarClientePreorden(nodoArbol * arbol, caja cajita[],int contadorclientes)
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
        if (pos_menor>=0)
        {
            agregarSegunAlgoritmo(&cajita[pos_menor].filita,aux,cajita[pos_menor].algoritmoPlanificacion);
            contadorclientes++;
        }
        contadorclientes=agregarClientePreorden(arbol->izq,cajita,contadorclientes);
        contadorclientes=agregarClientePreorden(arbol->der,cajita,contadorclientes);
    }
    return contadorclientes;
}

int agregarClienteInorden(nodoArbol * arbol, caja cajita[],int contadorclientes)
{
    int tipoPago;
    int pos_menor;
    persona aux;
    if (arbol==NULL)
    {
    }
    else
    {

        contadorclientes=agregarClienteInorden(arbol->izq,cajita,contadorclientes);
        aux=arbol->p;
        tipoPago=aux.tipo_pago;
        pos_menor=evaluar_caja_con_menos_clientes(cajita,tipoPago);
        if (pos_menor>=0)
        {
            agregarSegunAlgoritmo(&cajita[pos_menor].filita,aux,cajita[pos_menor].algoritmoPlanificacion);
            contadorclientes++;
        }
        contadorclientes=agregarClienteInorden(arbol->der,cajita,contadorclientes);
    }
    return contadorclientes;
}

int agregarClientePostorden(nodoArbol * arbol, caja cajita[],int contadorclientes)
{
    int tipoPago;
    int pos_menor;
    persona aux;
    if (arbol==NULL)
    {
    }
    else
    {
        contadorclientes=agregarClientePreorden(arbol->izq,cajita,contadorclientes);
        contadorclientes=agregarClientePreorden(arbol->der,cajita,contadorclientes);
        aux=arbol->p;
        tipoPago=aux.tipo_pago;
        pos_menor=evaluar_caja_con_menos_clientes(cajita,tipoPago);
        if (pos_menor>=0)
        {
            agregarSegunAlgoritmo(&cajita[pos_menor].filita,aux,cajita[pos_menor].algoritmoPlanificacion);
            contadorclientes++;
        }
    }
    return contadorclientes;
}

void atenderClientes(caja cajita[])///calcula los tiempos de espera y procesado
{
    int i=0;
    char rr[]= {"RR"};
    while (i<12)
    {
        if (strcmp(cajita[i].algoritmoPlanificacion,rr)!=0)///las que no son round robin
        {
            tiempo_de_espera_fila(&cajita[i].filita);///el round robin se calcula en el momento de mostrar la fila
        }
        i++;
    }
}

int agregarClienteACajaEnTiempoDeterminado(caja cajita[], int tiempo)
{
    persona cliente;
    cliente=nuevo_Persona();
    int tipodepago=cliente.tipo_pago;
    int posicion;

    posicion=evaluar_caja_con_menos_clientes(cajita,tipodepago);
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
    agregarSJF(&aux->siguiente,a);
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
    agregarSJF(&aux->siguiente,a);
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
    agregarSJF(&aux->siguiente,a);
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
    quitar(&cajita[validos-1].filita);
}

void promedioCajas (caja cajita[],int validos, float promediosE[], float promediosR[])
{
    float cant=0;
    float sumaE=0;
    float sumaR=0;
    atenderClientes(cajita);
    Fila * filita;
    nodo * aux;
    int i=0;

    while (i<validos)
    {
        if (cajita[i].abiertaOcerrada==1)
        {
            filita=&cajita[i].filita;
            aux=filita->primero;
            while (aux!=NULL)
            {
                sumaR=sumaR+aux->cliente.tiempoProcesado;
                sumaE=sumaE+aux->cliente.tiempoDeEspera;
                cant++;
                aux=aux->siguiente;
            }
            promediosE[i]=sumaE/cant;
            promediosR[i]=sumaR/cant;
        }
        i++;
    }
}

