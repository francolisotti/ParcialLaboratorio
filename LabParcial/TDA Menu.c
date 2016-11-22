#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Arbol.h"
#include "Caja.h"
#include "Fila.h"
#include "Lista.h"
#include "Persona.h"


void nombreArchivoPersona (char nombre[])
{
    char supuestoNombre[40];
    FILE * archi;

    printf("\nIngrese el nombre del archivo cargado con personas (y extension): ");
    fflush(stdin);
    gets(&supuestoNombre);
    archi=fopen(supuestoNombre, "rb");
    while (archi==NULL)
    {
        printf("\nERROR:");
        printf("\nNo existe un archivo con tal nombre");
        printf("\nPor favor, ingrese otro nombre: ");
        gets(&supuestoNombre);
        archi=fopen(supuestoNombre, "rb");
    }
    fclose(archi);
    strcpy(nombre,supuestoNombre);
}

void nombreArchivoCaja (char nombre[])
{
    char supuestoNombre[40];
    FILE * archi;

    printf("\nIngrese el nombre del archivo cargado con cajas (y extension): ");
    fflush(stdin);
    gets(&supuestoNombre);
    archi=fopen(supuestoNombre, "rb");
    while (archi==NULL)
    {
        printf("\nERROR:");
        printf("\nNo existe un archivo con tal nombre");
        printf("\nPor favor ingrese otro nombre: ");
        gets(&supuestoNombre);
        archi=fopen(supuestoNombre, "rb");
    }
    fclose(archi);
    strcpy(nombre,supuestoNombre);
}

void mostrar_todas_las_cajas (caja cajita[], int validos)
{
    int i=0;
    caja cajaAux;
    while (i<validos)
    {
        cajaAux=cajita[i];
        mostrarCaja(cajaAux);
        printf("\nPresione cualquier tecla para continuar\n");
        getch();

        i++;
    }
}


void Mostrar_Archivos (char archi_cliente[], char archi_caja[])
{
    char controlArchivoCliente;
    printf("\nDesea ver el archivo con los clientes? s/n: ");
    fflush(stdin);
    scanf("%c", &controlArchivoCliente);
    {
        if (controlArchivoCliente=='s')
        {
            mostrarArchiPersona(archi_cliente);
        }
    }

    char controlArchivoCaja;
    printf("\nDesea ver el archivo con las cajas? s/n: ");
    fflush(stdin);
    scanf("%c", &controlArchivoCaja);
    {
        if (controlArchivoCaja=='s')
        {
            mostrarArchiCaja(archi_caja);
        }
    }
}

void opcion1 (caja cajita[],nodoArbol * cliente, int validos)
{
    abrir_cajas_(cajita);
    agregarClienteACaja(cajita,cliente);
    mostrar_todas_las_cajas(cajita,validos);
}

void opcion2 (caja cajita[], int validos)
{
    atenderClientes(cajita);
    mostrar_todas_las_cajas(cajita,validos);
}

int opcion3 (caja cajita[])
{
    int tiempo;
    printf("\nElija el tiempo en el que quiere ingresar al nuevo cliente: ");
    scanf("%d", &tiempo);
    int posicion=agregarClienteACajaEnTiempoDeterminado(cajita,tiempo);
    return posicion;
}

void opcion4(caja cajita[], int posicion)
{
    atenderClientes(cajita);
    mostrarCaja(cajita[posicion]);

}

void opcion5(caja cajita[],int validos)
{
    int i=0;
    while (i<validos)
    {
        while (filaVacia(&cajita[i].filita)==1)
        {
            quitar(&cajita[i].filita);
        }
        printf("\nTERMINO LA CAJA");
        i++;

    }
}

void opcion6(caja cajita[], int validos)
{
    printf("\nDesea vaciar alguna caja? s/n: ");
    char control;
    char contro2;
    fflush(stdin);
    scanf("%c", &control);
    int i=0;
    if (control=='s')
    {
        while (i<validos)
        {
            mostrarCaja(cajita[i]);
            printf("\nDesea vaciar esta caja, y cerrarla? s/n: ");
            fflush(stdin);
            scanf("%c",&contro2);
            if (contro2=='s')
            {
                while (filaVacia(&cajita[i].filita)==1)
                {
                    quitar(&cajita[i].filita);
                    atenderClientes(cajita);
                    mostrar(&cajita[i].filita);
                    cajita[i].abiertaOcerrada=0;
                }
            }
            i++;
        }
    }
}























