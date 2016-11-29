#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


void nombreArchivoPersona (char nombre[])///obtiene el nombre del archivo cargado con los clientes
{///nos sirve en caso de utilizar archivos externos
    char supuestoNombre[40];
    FILE * archi;

    printf("\nIngrese el nombre del archivo cargado con personas (y extension): ");
    fflush(stdin);
    gets(&supuestoNombre);
    archi=fopen(supuestoNombre, "rb");///abrimos en modo lectura
    while (archi==NULL)///esto lo hacemos para comprobar que no haya ingresado un nomber incorrecto
    {
        printf("\nERROR:");
        printf("\nNo existe un archivo con tal nombre");
        printf("\nPor favor, ingrese otro nombre: ");
        gets(&supuestoNombre);
        archi=fopen(supuestoNombre, "rb");
    }
    fclose(archi);///cerramos el archivo
    strcpy(nombre,supuestoNombre);///copiamos en nombre el nuevo nombre del archivo (al ser un arreglo de caracteres no hace falta un return)
}

void nombreArchivoCaja (char nombre[])///lo mismo que con nombreArchivoPersona pero para el archivo de caja
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

/*void mostrar_todas_las_cajas (caja cajita[])
{
    int i=0;
    caja cajaAux;
///    while (i<validos)
    {
        cajaAux=cajita[i];
        printf("\n-----------------------\n");
        mostrarCaja(cajaAux);
        printf("\n-----------------------\n");
        printf("\nPresione cualquier tecla para continuar\n");
        getch();

        i++;
    }
}*/


void Mostrar_Archivos (char archi_cliente[], char archi_caja[])
{
    char controlArchivoCliente;
    printf("\nDesea ver el archivo con los clientes? s/n: ");
    fflush(stdin);
    scanf("%c", &controlArchivoCliente);
    if (controlArchivoCliente=='s')
    {
        mostrarArchiPersona(archi_cliente);
    }
    char controlArchivoCaja;
    printf("\nDesea ver el archivo con las cajas? s/n: ");
    fflush(stdin);
    scanf("%c", &controlArchivoCaja);
    if (controlArchivoCaja=='s')
    {
        mostrarArchiCaja(archi_caja);
    }
}

int menuGeneral ()
{
    int opcion;
    system("cls");
    printf("\nMENU GENERAL:\n ");
    printf("\n[1] Acceder al menu de archivos.");
    printf("\n[2] Acceder al menu de arbol.");
    printf("\n[3] Acceder al menu de cajas.");
    printf("\n");
    printf("\n[0] Salir del programa.");
    printf("\nIngrese un numero: ");
    scanf("%d", &opcion);
    while (opcion<0 || opcion>3)///comprobamos que se introdusca una opcion correcta
    {
        printf("\nERROR, ingrese opcion nuevamente: ");
        scanf("%d", &opcion);
    }
    return opcion;///retornamos esa opcion para manejarnos en el main
}

int menu_archivo ()
{
    system("cls");
    int control;
    printf("MENU DE ARCHIVOS\n");
    printf("\n[1] Mostrar Archivo de clientes");
    printf("\n[2] Mostrar Archivo de cajas");
    printf("\n");
    printf("\n[0] Volver al menu general");
    printf("\nIngrese un numero: ");
    scanf("%d",&control);
    while (control<0 || control>2)
    {///comprobamos que la opcion sea correcta
        printf("Opcion incorrecta, ingrese nuevamente:");///controlamos que la opcion sea correcta
        scanf("%d",&control);
    }
    return control;///esto nos redireccionara a las distintas opciones a seguir
}

void subMenu_archivo_opcion1 (char nombre_archi_cliente[])
{
    system("cls");
    mostrarArchiPersona(nombre_archi_cliente);
}

void subMenu_archivo_opcion2 (char nombre_archi_cajas[])
{
    system("cls");
    mostrarArchiCaja(nombre_archi_cajas);
}


int menu_arbol ()
{
    int control;
    system("cls");
    printf("\nMENU DE ARBOL\n");
    printf("\n[1] Pasar archivo de clientes a arbol");
    printf("\n[2] Mostrar arbol de clientes en orden que pida");
    printf("\n");
    printf("\n[0] Volver al menu general");
    printf("\nIngrese un numero: ");
    fflush(stdin);
    scanf("%d",&control);
    while (control<0 || control>2)///comprobamos que la opcion sea correcta
    {///comprobamos que la opcion sea correcta
        printf("Opcion incorrecta, ingrese nuevamente: ");
        scanf("%d",&control);
    }
    return control;///esto nos redireccionara a las distintas opciones a seguir
}

nodoArbol * subMenu_arbol_opcion1(char nombre_archi[], nodoArbol * arbol)
{
    arbol=ArchiToArbol(nombre_archi,arbol);///se pasan al arbol los clientes del archivo
}

void subMenu_arbol_opcion2(nodoArbol * arbol)
{
    system("cls");
    int orden;
    printf("En que orden desea mostrar el arbol");
    printf("\n[1] Preorden");
    printf("\n[2] Inorden");
    printf("\n[3] Postorden");
    printf("\nIngrese un numero: ");
    scanf("%d",&orden);
    while (orden<1 || orden>3)
    {///comprobamos que la opcion sea correcta
        printf("\nERROR, ingrese un orden valido: ");
        scanf("%d", &orden);
    }
    mostrarArbol(arbol,orden);///se muestra como quedo el arbol segun el orden elegido
}

int menu_cajas()
{
    system("cls");
    int control;
    printf("\nMENU DE CAJAS\n");
    printf("\n[1] Abrir o cerrar una o todas las cajas");
    printf("\n[2] Mostrar las cajas");
    printf("\n[3] Pasar clientes del arbol a cajas");
    printf("\n[4] Atender clientes");
    printf("\n[5] Agregar en tiempo determinado");
    printf("\n[6] Vaciar una o todas las cajas");
    printf("\n[7] Calcular tiempos promedios");
    printf("\n");
    printf("\n[0] Volver al menu general");
    printf("\nIngrese un numero: ");
    scanf("%d",&control);
    while (control<0 || control>7)
    {///comprobamos que la opcion sea correcta
        printf("Opcion incorrecta, ingrese nuevamente: ");
        scanf("%d",&control);
    }
    return control;///esto nos redireccionara a las distintas opciones a seguir
}

int subMenu_caja_opcion1(caja cajita[], int cantidadDeCajas)
{
    system("cls");
    int control,i,d,numCaja;
    printf("\n[1] Abrir todas las cajas");
    printf("\n[2] Cerrar todas las cajas");
    printf("\n[3] Abrir de a una caja");
    printf("\n[4] Cerrar de a una caja");
    printf("\n");
    printf("\n[0] Volver al menu de caja");
    printf("\nIngrese un numero: ");
    scanf("%d",&control);
    while (control<0 || control>4)
    {///comprobamos que la opcion sea correcta
        printf("Opcion incorrecta, ingrese nuevamente: ");
        scanf("%d",&control);
    }
    if (control==1)
    {
        i=0;
        while(i<cantidadDeCajas)///mientras no se supere la cantidad de cajas
        {
            if (cajita[i].abiertaOcerrada==0)///si la caja estaba cerrada
            {///se abrira
                cajita[i]=abrirOcerrarCaja(cajita[i]);
            }
            i++;///recorremos la caja
        }
        printf("\nCajas abiertas exitosamente");
        printf("\nPresione cualquier tecla para continuar");
        getch();
    }
    if (control==2)
    {
        d=0;
        while(d<cantidadDeCajas)///mientras no se supere la cantidad de cajas
        {
            if (cajita[d].abiertaOcerrada==1)
            {///si la caja estaba abierta se cerrara
                cajita[d]=abrirOcerrarCaja(cajita[d]);
            }
            d++;
        }
        printf("\nCajas cerradas exitosamente");
        printf("\nPresione cualquier tecla para continuar");
        getch();
    }
    char flag='s';
    char flag2='s';
    if (control==3)
    {
        while (flag=='s')
        {
            printf("\nIngrese el numero de caja que quiere abrir: ");
            scanf("%d", &numCaja);
            while (numCaja<1 || numCaja>cantidadDeCajas)///comprobamos que la opcion sea correcta
            {
                printf("\nERROR, la caja no existe, ingrese nuevemente: ");
                scanf("%d", &numCaja);
            }
            printf("\n-----------------------\n");
            mostrarCaja(cajita[numCaja-1]);///usamos -1 ya que el arreglo de cajas empieza en 0 pero la gente suele pensa que empieza en 1
            printf("\n-----------------------\n");
            if (cajita[numCaja-1].abiertaOcerrada==1)///se compueba si estaba abierta
            {
                printf("\nEsa caja ya esta abierta");
                printf("\nIngrese cualquier tecla para continuar");
                getch();
            }
            else///sino se abre
            {
                cajita[numCaja-1]=abrirOcerrarCaja(cajita[numCaja-1]);
                printf("\nCaja abierta exitosamente");
            }
            printf("\nDesea abrir otra caja? s/n: ");
            fflush(stdin);
            scanf("%c", &flag);
        }
    }
    if (control==4)///igual que arriba pero cerrando en vez de abriendo
    {
        while (flag2=='s')
        {
            printf("\nIngrese el numero de caja que quiere cerrar: ");
            scanf("%d", &numCaja);
            while (numCaja<1 || numCaja>cantidadDeCajas)
            {
                printf("\nERROR, la caja no existe, ingrese nuevemente: ");
                scanf("%d", &numCaja);
            }
            printf("\n-----------------------\n");
            mostrarCaja(cajita[numCaja-1]);
            printf("\n-----------------------\n");
            if (cajita[numCaja-1].abiertaOcerrada==0)
            {
                printf("\nEsa caja ya esta cerrada");
                printf("\nIngrese cualquier tecla para continuar");
                getch();
            }
            else
            {
                cajita[numCaja-1]=abrirOcerrarCaja(cajita[numCaja-1]);
                printf("\nCaja cerrada exitosamente");
            }
            printf("\nDesea cerrar otra caja? s/n: ");
            fflush(stdin);
            scanf("%c", &flag2);
        }
    }
    return control;
}

int subMenu_caja_opcion2(caja cajita[], int cantidadDeCajas)
{
    int opcion;
    int i=0;
    int numCaja;
    char control='s';
    system("cls");
    printf("\n[1] Mostrar todas las cajas");
    printf("\n[2] Mostrar una caja especifica");
    printf("\n");
    printf("\n[0] Volver al menu de cajas");
    printf("\nIngrese una opcion: ");
    scanf("%d", &opcion);
    while (opcion>2 || opcion<0)
    {///comprobamos que la opcion sea correcta
        printf("\nERROR, ingrese opcion nuevamente: ");
        scanf("%d", &opcion);
    }
    if (opcion==1)
    {
        while (i<cantidadDeCajas)///mientras no se supere la cantidad de cajas
        {///mostramos todas las cajas
            printf("\n-----------------------\n");
            mostrarCaja(cajita[i]);
            i++;
        }
        printf("\nPresione cualquier tecla para continuar\n");
        getch();
    }
    else if (opcion==2)
    {
        while (control=='s' )
        {///mostramos sola la caja que nos indique
            printf("\nIngrese el numero de la caja que desea mostrar: ");
            scanf("%d", &i);
            printf("\n-----------------------\n");
            mostrarCaja(cajita[i-1]);///usamos -1 por que suponemos que el usuario empezara a contar desde 1 y no de 0
            printf("\nDesea mostrar otra caja? s/n: ");
            fflush(stdin);
            scanf("%c", &control);
        }
        printf("\nPresione cualquier tecla para continuar\n");
        getch();
    }
    return opcion;
}

int subMenu_caja_opcion3(caja cajita[], nodoArbol * arbol, int cantidadDeCajas)
{
    int i=0;
    int cantidadclientes=0;
    int flag=0;
    while (i<cantidadDeCajas)///mientras no se supere la cantidad de cajas
    {
        if(cajita[i].abiertaOcerrada==1)
        {
            flag=1;
        }
        i++;
    }
    if (flag==0)
    {
        printf("\nERROR, todas las cajas estan cerradas");
    }
    else///si al menos hay una caja abierta
    {///se agregan los clientes a la fila de las cajas y se los cuenta
        cantidadclientes=agregarClienteACaja(cajita,arbol);
        printf("\nClientes cargados exitosamente: se han cargado %d de 35 clientes", cantidadclientes);
    }
    printf("\nPresione cualquier tecla para continuar");
    getch();

    return cantidadclientes;
}

void subMenu_caja_opcion4(caja cajita[])
{
    atenderClientes(cajita);///calcula los tiempos de espera y procesado
}

void subMenu_caja_opcion5(caja cajita[])
{
    int tiempo;
    int posicion;
    printf("\nEn que tiempo desea cargar su cliente: ");
    scanf("%d", &tiempo);///ingresamos un nuevo cliente en un tiempo determinado
    posicion=agregarClienteACajaEnTiempoDeterminado(cajita,tiempo);
    printf("\n-----------------------\n");
    mostrarCaja(cajita[posicion]);///mostramos como quedo ahora la caja en la que fue agregado el nuevo cliente
    printf("\n-----------------------\n");

}

void subMenu_caja_opcion6(caja cajita[], int cantidadDeCajas)
{
    system("cls");
    int opcion;
    int i=0;
    char control='s';
    char control2;
    printf("\n[1] Vaciar de a una caja por vez");
    printf("\n[2] Vaciar todas las cajas");
    printf("\n");
    printf("\n[0] Volver al menu caja");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    while (opcion<0 || opcion>2)
    {///comprobamos que la opcion sea correcta
        printf("\nERROR, ingrese opcion nuevamente: ");
        scanf("%d", &opcion);
    }
    system("cls");///limpiamos la pantalla
    if (opcion==1)
    {
        while (control=='s')
        {
            printf("\nIngrese el numero de caja que desea vaciar: ");
            scanf("%d",&i);
            while(i<1 && i>cantidadDeCajas)///mientras no se supere la cantidad de cajas
            {
                printf("\nERROR, ingrese opcion nuevamente");
                scanf("%d",&i);
            }
            printf("\n-----------------------\n");
            mostrarCaja(cajita[i-1]);
            printf("\n-----------------------\n");
            printf("\nDesea vaciar esta caja? s/n: ");///por si se equivoco de caja
            fflush(stdin);
            scanf("%c", &control2);
            if (control2=='s')
            {
                quitar(&cajita[i-1].filita);
                cajita[i-1].abiertaOcerrada=0;
            }
            printf("\nDesea vaciar otra caja? s/n: ");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
    else if (opcion==2)
    {
        for (i=0;i<cantidadDeCajas;i++)///mientras no se supere la cantidad de cajas
        {
            system("cls");
            printf("\nA continuacion se mostrara la caja a vaciar\n\n");
            mostrarCaja(cajita[i]);
            quitar(&cajita[i].filita);
        }
        printf("\nCajas vaciadas exitosamente");
        printf("\nPresione cualquier tecla para continuar\n");
        getch();

    }
}

void subMenu_caja_opcion7(caja cajita[], int cantidadDeCajas)
{
    int z=0;
    float promediosE[cantidadDeCajas];
    float promediosR[cantidadDeCajas];
    char mander='s';
    promedioCajas(cajita,cantidadDeCajas,promediosE,promediosR);
    printf("\nDesea mostrar los promedios de cada caja? s/n: ");
    fflush(stdin);
    scanf("%c",&mander);
    if (mander=='s')
    {
        while(z<cantidadDeCajas)///mientras no se supere la cantidad de cajas
        {
            printf("\n-----------------------\n");
            mostrarCaja(cajita[z]);
            printf("\nPromedio de tiempo de espera: %.2f",promediosE[z]);
            printf("\nPromedio de tiempo de procesado: %.2f",promediosR[z]);
            printf("\nPromedio de ambos es: %.2f\n",((promediosE[z]+promediosR[z])/2));
            z++;
            printf("-----------------------\n");
        }
    }
    else
    {
        printf("\nNo hay ninguna caja abierta para promediar");
    }
}
