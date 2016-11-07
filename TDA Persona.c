#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "persona.h"

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

void cargarPersona (char nombreDelArchivo[])
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
}

void mostrarPersona(persona aux)
{
    printf("\nNombre y Apellido: %s", aux.nombreApellido);
    printf("\nCantidad de articulos: %d", aux.cantArticulos);
    printf("\nTiempo de espera: %d", aux.tiempoDeEspera);
    printf("\nTiempo de procesado: %d", aux.tiempoProcesado);
    printf("\nTipo de cliente (prioridad 1: embarazada, 2: jubilado y 3: normal): %d", aux.tipo_cliente);
    printf("\nTipo pago (1 efectivo, 2 crédito o débito, 3 todos): %d", aux.tipo_pago);

}

