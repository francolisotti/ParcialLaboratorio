#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "Arbol.h"
#include "Lista.h"
#include "Caja.h"
#include "Fila.h"

void nombreArchivoPersona (char nombre[]);
void nombreArchivoCaja (char nombre[]);
void mostrar_todas_las_cajas (caja cajita[], int validos);
void Mostrar_Archivos (char archi_cliente[], char archi_caja[]);
void opcion1 (caja cajita[],nodoArbol * cliente, int validos);
void opcion2 (caja cajita[], int validos);
int opcion3 (caja cajita[]);
void opcion4(caja cajita[], int posicion);
void opcion5(caja cajita[],int validos);
void opcion6(caja cajita[], int validos);








#endif // MENU_H_INCLUDED
