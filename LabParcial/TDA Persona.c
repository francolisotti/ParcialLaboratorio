#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"




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

void mostrarPersona(persona aux)
{

    printf("\n    Nombre y Apellido: %s", aux.nombreApellido);
    printf("\nCantidad de articulos: %d", aux.cantArticulos);
    printf("\n     Tiempo de espera: %d", aux.tiempoDeEspera);
    printf("\n  Tiempo de procesado: %d", aux.tiempoProcesado);
    if(aux.tipo_cliente==1)
    {
        printf("\n      Tipo de cliente: embarazada");
    }
    else if (aux.tipo_cliente==2)
    {
        printf("\n      Tipo de cliente: jubilado");
    }
    else
    {
        printf("\n      Tipo de cliente: normal");
    }
    if (aux.tipo_pago==1)
    {
        printf("\n            Tipo pago: Efectivo");
    }
    else if (aux.tipo_pago==2)
    {
        printf("\n            Tipo pago: Debito/Credito");
    }
    else
    {
        printf("\n            Tipo pago: Todos los metodos");
    }
    puts("\n------------------------------------------");
}

void mostrarArchiPersona (char archi_persona[])
{
    FILE * archi=fopen(archi_persona, "rb");
    persona aux;
    if (archi!=NULL)
    {
        while (fread(&aux,sizeof(persona),1,archi)>0)
        {
            mostrarPersona(aux);
            printf("\n::::");
            getch();
        }
        printf("\n se termino aca perrin");
    }
    else
    {
        printf("\nERROR archivo no encontrado");
    }
    fclose(archi);

}




