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
int menuGeneral ();
int menu_archivo ();
void subMenu_archivo_opcion1 (char nombre_archi_cliente[]);
void subMenu_archivo_opcion2 (char nombre_archi_cajas[]);
int menu_arbol ();
nodoArbol * subMenu_arbol_opcion1(char nombre_archi[], nodoArbol * arbol);
void subMenu_arbol_opcion2(nodoArbol * arbol);
int menu_cajas();
int subMenu_caja_opcion1(caja cajita[]);
int subMenu_caja_opcion2(caja cajita[]);
int subMenu_caja_opcion3(caja cajita[], nodoArbol * arbol);
void subMenu_caja_opcion4(caja cajita[]);
void subMenu_caja_opcion5(caja cajita[]);
void subMenu_caja_opcion6(caja cajita[], int cantidadDeCajas);
void subMenu_caja_opcion7(caja cajita[], int cantidadDeCajas);











#endif // MENU_H_INCLUDED
