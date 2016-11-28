#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string.h>

typedef struct persona
{
    char nombreApellido [40];
    int cantArticulos; // es el tiempo de ejecución
    int tiempoDeEspera; // es el tiempo de respuesta
    int tiempoProcesado; // es el tiempo que ya fue procesado en la línea de caja
    int tipo_cliente; // prioridad (1: embarazada, 2: jubilado y 3: normal)
    int tipo_pago; // 1 efectivo, 2 crédito o débito, 3 todos
} persona;

persona nuevo_Persona();
persona crearPersona (char nombreApellido[], int cantArticulos,int tipo_Cliente,int tipo_Pago);
void cargarPersona (char nombreDelArchivo[]);
void mostrarPersona(persona aux);
#endif // PERSONA_H_INCLUDED
