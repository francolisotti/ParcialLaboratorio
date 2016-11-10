#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"



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

void pasarDeArchiAcaja (char archiCajas[], caja cajita[])
{
    FILE * archi=fopen(archiCajas, "rb");
    int i=0;
    if (archi!=NULL)
    {
        while(fread(&cajita[i],sizeof(caja),1,archi)>0)
        {
            i++;
        }
    }
    fclose(archi);

}


void agregarClientePreorden(nodoArbol * arbol, caja cajita)
{
    if(arbol!=NULL)
    {

        agregar(&cajita.filita,arbol->p);
        agregarClientePreorden(arbol->izq,cajita);
        agregarClientePreorden(arbol->der,cajita);
    }
}

void agregarClienteInorden(nodoArbol * arbol, caja cajita)
{
    if(arbol!=NULL)
    {
        agregarClienteInorden(arbol->izq,cajita);
        agregar(&cajita.filita,arbol->p);
        agregarClienteInorden(arbol->der,cajita);
    }
}

void agregarClientePostorden(nodoArbol * arbol, caja cajita)
{
    if(arbol!=NULL)
    {
        agregarClientePostorden(arbol->izq,cajita);
        agregarClientePostorden(arbol->der,cajita);
        agregar(&cajita.filita,arbol->p);
    }
}



caja agregarClienteACaja (caja cajita[], nodoArbol * raiz)
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
        agregarClientePreorden(raiz,cajita[]);
    }
    else if (recorrido==2)
    {
        agregarClienteInorden(raiz,cajita[]);
    }
    else
    {
        agregarClientePostorden(raiz,cajita[]);
    }
    return cajita;
}

