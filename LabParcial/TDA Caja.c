#include <stdio.h>
#include <stdlib.h>
#include "Caja.h"


void abrir_cajas_(caja cajita[])
{
    char opcion;
    char opcion2;
    int i=0;
    printf("\nDesea abrir todas las cajas? s/n: ");
    fflush(stdin);
    scanf("%c",&opcion);
<<<<<<< HEAD
    /*while ((opcion != 's') || (opcion!= 'n'))
=======
<<<<<<< HEAD
    /* while (opcion != 's' || opcion!= 'n')
     {
         printf("\nERROR:");
         printf("\nIngrese s(si) o n(no): ");
         fflush(stdin);
         scanf("%c", &opcion);
     }*/
=======
    while ((opcion != 's') || (opcion!= 'n'))
>>>>>>> origin/master
    {
        printf("\nERROR:");
        printf("\nIngrese s(si) o n(no): ");
        fflush(stdin);
        scanf("%c", &opcion);
<<<<<<< HEAD
    }*/
=======
    }
>>>>>>> origin/master
>>>>>>> origin/master
    if (opcion=='s')
    {
        for (i=0; i<12; i++)
        {
            cajita[i].abiertaOcerrada=1;
<<<<<<< HEAD
            cajita[i].filita=inicFila(cajita[i].filita);
=======
<<<<<<< HEAD
//            cajita[i].filita=inicFila(cajita[i].filita);
=======
            //cajita[i].filita=inicFila(cajita[i].filita);
>>>>>>> origin/master
>>>>>>> origin/master
        }
    }

    else
    {
        printf("\nDesea abrir alguna caja s/n: ");
        fflush(stdin);
        scanf("%c", &opcion);
        /*while (opcion !='s' || opcion!='n')
        {
            printf("\nERROR:");
            printf("\nIngrese s(sí) o n(no): ");
            fflush(stdin);
            scanf("%c", &opcion);
        }*/
        if (opcion=='s')
        {
            for (i=0; i<12; i++)
            {
                mostrarCaja(cajita[i]);
                printf("\nDesea abrir esta caja: s/n: ");
                fflush(stdin);
                scanf("%c",&opcion2);
                /*while (opcion2 !='s' || opcion2!='n')
                {
                    printf("\nERROR:");
                    printf("\nIngrese s(sí) o n(no): ");
                    fflush(stdin);
                    scanf("%c", &opcion2);
                }*/
                if (opcion2=='s')
                {
                    cajita[i].abiertaOcerrada=1;
                    //cajita[i].filita=inicFila(cajita[i].filita);
                }
            }
        }

    }
}

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

int contarClientesCaja (Fila * filita)
{
printf("contarClientesCaja \n");
    nodo * aux=filita->primero;
    int cont=0;
    if (aux)
    {
        while (aux!=NULL)
        {
            printf("%d",aux->cliente.cantArticulos);
            aux=aux->siguiente;
            cont++;
        }
    }
     printf("contarClientesCaja %d\n",cont);
    return cont;
}

void mostrarCaja(caja cajita)
{
   /* if((cajita.nro_de_caja>0) && (cajita.nro_de_caja<=12))
    {*/
        puts("------------------------------------------");
        if(cajita.abiertaOcerrada==1)
        {
            printf("Caja abierta");
        }
        else
        {
            printf("Caja cerrada");
        }
        printf("\nSalgortmo de planificacion: %s",cajita.algoritmoPlanificacion);
        printf("\nCajero: %s",cajita.nombreCajero);
        printf("\nCaja numero: %d",cajita.nro_de_caja);
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
        char control= 's';
        puts("\n------------------------------------------");
        printf("\nDesea mostrar la fila? s/n: ");
        fflush(stdin);
        scanf("%c",&control);
        if(control == 's')
        {
<<<<<<< HEAD
            puts("\n------------------------------------------");
            printf("\nDesea mostrar la fila? s/n: ");
            fflush(stdin);
            scanf("%c",&control);
            if(control == 's' )
            {
                mostrar(&cajita.filita);
            }
            puts("\n------------------------------------------");
        }

   /* }
=======
            mostrar(&cajita.filita);
        }
        puts("\n------------------------------------------");
    }
>>>>>>> origin/master
    else
        printf("\nla caja no existe");*/
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
        if ((cajita[i].tipo_pago==tipopago) || (cajita[i].tipo_pago==3))//&& cajita[i].abiertaOcerrada==1)
        {
            aux[u]=cajita[i];
            /*strcpy(aux[u].nombreCajero,cajita[i].nombreCajero);
            aux[u].tipo_pago=cajita[i].tipo_pago;
            strcpy(aux[u].algoritmoPlanificacion,cajita[i].algoritmoPlanificacion);*/
            u++;
        }
        i++;

    }

    return u;
}

void agregarClientePreorden(nodoArbol * arbol, caja cajita[])
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
        tipopago=arbol->p.tipo_pago;
        cantsub=Subarreglo(&(cajita),&(aux),tipopago);
        printf("El problema esta en la primera vez que se llama a si misma");

        cantsub=Subarreglo(cajita,aux,tipopago);
        printf("\n---%s---",aux[0].algoritmoPlanificacion);
        menor=contarClientesCaja(&(aux[i]).filita);
        printf("\n---%s---",aux[0].algoritmoPlanificacion);

        posmenor=i;
        i++;
        while (i<cantsub)
        {
            cantclientes=contarClientesCaja(&(aux[i]).filita);
            if (cantclientes<menor)
            {
                menor=cantclientes;
                posmenor=i;
            }
            i++;
        }

        agregar(&aux[posmenor].filita,arbol->p);
        agregarClientePreorden(arbol->izq,&cajita);
        agregarClientePreorden(arbol->der,&cajita);
        pasarAuxACaja(aux,cajita);
    }


}



void agregarClienteInorden(nodoArbol * arbol, caja cajita[])
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
        menor=contarClientesCaja(&(aux[i]).filita);
        posmenor=i;
        while (i<cantsub)
        {
            cantclientes=contarClientesCaja(&(aux[i]).filita);
            if (cantclientes<menor)
            {
                menor=cantclientes;
                posmenor=i;
            }
            i++;
        }
        agregar(&aux[posmenor].filita,arbol->p);
        agregarClienteInorden(arbol->der,cajita);
        pasarAuxACaja(aux,(&cajita));
        printf("ACAESTAELPROBLEMA");

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
        menor=contarClientesCaja(&(aux[i]).filita);
        posmenor=i;
        i++;
        while (i<cantsub)
        {
            cantclientes=contarClientesCaja(&(aux[i]).filita);
            if (cantclientes<menor)
            {
                menor=cantclientes;
                posmenor=i;
            }
            i++;
        }
        agregar(&aux[posmenor].filita,arbol->p);
        pasarAuxACaja(aux,(&cajita));
        printf("ACAESTAELPROBLEMA");
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
    return(*cajita);
}

void pasarAuxACaja (caja aux, caja cajita[])
{
    int i=0,flag=0;
    printf("principiooo");
    while (i<12 && flag==0)
    {
        printf("while \n");
        //aux tiene basura
        if (strcmp(aux.nombreCajero,cajita[i].nombreCajero)==0)
        {
            printf("hola ");
            cajita[i]=aux;
            flag=1;
        }
        else
        {
            printf("chau");
        }
        i++;
    }
}
