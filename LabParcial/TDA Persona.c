#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

persona nuevo_Persona()///crearemos una nueva persona
{
    char nombreApellido[40];
    int cantArticulos,tipo_Cliente,tipo_Pago;
    persona nuevo;
///obtenemos los datos de la persona
    printf("\nNombre y Apellido: ");
    fflush(stdin);
    gets(&nombreApellido);
    printf("\nCantidad de articulos: ");
    scanf("%d", &cantArticulos);
    printf("\nTipo de cliente (1: embarazada, 2: jubilado y 3: normal): ");
    scanf("%d", &tipo_Cliente);
    printf("\nTipo de pago (1 efectivo, 2 credito o debito, 3 todos): ");
    scanf("%d", &tipo_Pago);

    nuevo=crearPersona(nombreApellido,cantArticulos,tipo_Cliente,tipo_Pago);
///creamos la nueva persona
    return nuevo;///y la retornamos
}

persona crearPersona (char nombreApellido[], int cantArticulos,int tipo_Cliente,int tipo_Pago)
{
    persona aux;

    strcpy(aux.nombreApellido,nombreApellido);
    aux.cantArticulos=cantArticulos;
    aux.tipo_cliente=tipo_Cliente;
    aux.tipo_pago=tipo_Pago;

    aux.tiempoDeEspera=0;
    aux.tiempoProcesado=0;///le asignamos espera y procesado 0 ya que todabia no fueron atendidas

    return aux;///retornamos la nueva persona
}

void mostrarPersona(persona aux)
{
    printf("\n    Nombre y Apellido: %s", aux.nombreApellido);///mosrtamos cada dato
    printf("\nCantidad de articulos: %d", aux.cantArticulos);
    printf("\n     Tiempo de espera: %d", aux.tiempoDeEspera);
    printf("\n  Tiempo de procesado: %d", aux.tiempoProcesado);
    if(aux.tipo_cliente==1)///para no mostrar tipo de cliente:1/2/3
    {
        printf("\n      Tipo de cliente: Embarazada");///leemos el tipo de cliente y lo mostramos en palabras
    }
    else if (aux.tipo_cliente==2)
    {
        printf("\n      Tipo de cliente: Jubilado");
    }
    else
    {
        printf("\n      Tipo de cliente: Normal");
    }
    if (aux.tipo_pago==1)
    {
        printf("\n            Tipo pago: Efectivo");///tambien con el tipo de pago
    }
    else if (aux.tipo_pago==2)
    {
        printf("\n            Tipo pago: Debito/Credito");
    }
    else
    {
        printf("\n            Tipo pago: Todos los metodos");
    }
    printf("\n-----------------------\n");///linea divisoria para emprolijar
}

void mostrarArchiPersona (char archi_persona[])///sirve para comprobar si el archivo no esta dañado
{
    FILE * archi=fopen(archi_persona, "rb");///abrimos el archivo en modo lectura
    persona aux;
    if (archi!=NULL)///si el archivo no esta vacio
    {
        while (fread(&aux,sizeof(persona),1,archi)>0)///mientras no se llegue al final
        {
            mostrarPersona(aux);///mostramos los atributos de la persona
            printf("\nPrecione cualquier tecla para continuar");
            getch();///asi resulta mas comodo leer el archivo
        }
    }
    else///sino se informa del error
    {
        printf("\nERROR, archivo no encontrado");
    }
    fclose(archi);///cerramos el archivo
}




