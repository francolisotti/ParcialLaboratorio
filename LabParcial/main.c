#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"


int main()
{
    system("color 3");

    char archi_cliente[25];
    char archi_caja[25];
    int control;
    printf("Bienvenido a U.T.N mart\n\n\n");
    puts("------------------------------");
    printf("\nDesea usar los archivos locales(1), o utilizar uno externo(2): ");
    scanf("%d",&control);
    while ((control<1) || (control>2))
    {
        printf("\nERROR\nIngrese una opcion valida");
        printf("\nUsar los archivos locales(1), o utilizar uno externo(2):");
        scanf("%d",&control);
    }
    if(control==1)
    {
        strcpy(archi_cliente,"cliente.bin");
        strcpy(archi_caja,"caja.bin");

    }
    else if (control==2)
    {
        nombreArchivoCaja(archi_caja);
        nombreArchivoPersona(archi_cliente);
    }
    caja cajita[12];
    nodoArbol * arbol=inicArbol();

    int cantidadDeCajas=pasarDeArchiAcaja_yContar(archi_caja,cajita);
    int opcion=-1;
    int opcionArchi;
    int opcionArbol;
    int opcionCaja;
    int flagArbol=0;
    int controlOpcion1Caja;
    int controlOpcion2Caja;
    int flagCajaConClientes=0;
    while (opcion!=0)
    {
        opcion=menuGeneral();
        if (opcion==1)
        {
            opcionArchi=menu_archivo();
            while (opcionArchi>0)
            {
                if (opcionArchi==1)
                {
                    subMenu_archivo_opcion1(archi_cliente);
                }
                else if (opcionArchi==2)
                {
                    subMenu_archivo_opcion2(archi_caja);
                }
                system("cls");
                opcionArchi=menu_archivo();
            }
        }
        else if (opcion==2)
        {
            opcionArbol=menu_arbol();
            while(opcionArbol>0)
            {
                if (opcionArbol==1)
                {
                    arbol=subMenu_arbol_opcion1(archi_cliente,arbol);
                    printf("\nArbol cargado exitosamente");
                    printf("\nPresione cualquier tecla para continuar");
                    getch();
                    flagArbol=1;
                }
                else if (opcionArbol==2)
                {
                    if (flagArbol==1)
                    {
                        subMenu_arbol_opcion2(arbol);
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }
                    else
                    {
                        printf("\nERROR, primero debe pasar al arbol los clientes del archivo");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }
                }
                opcionArbol=menu_arbol();
            }

        }
        else if (opcion==3)
        {
            system("cls");
            opcionCaja=menu_cajas();
            while (opcionCaja>0)
            {
                if (opcionCaja==1)
                {
                    controlOpcion1Caja=subMenu_caja_opcion1(cajita);
                    while (controlOpcion1Caja>0)
                    {
                        controlOpcion1Caja=subMenu_caja_opcion1(cajita);
                    }

                }
                else if (opcionCaja==2)
                {
                    controlOpcion2Caja=subMenu_caja_opcion2(cajita);
                    while (controlOpcion2Caja>0)
                    {
                        controlOpcion2Caja=subMenu_caja_opcion2(cajita);
                    }
                }
                else if (opcionCaja==3)
                {
                    if (flagArbol==1)
                    {
                        subMenu_caja_opcion3(cajita,arbol);
                        flagCajaConClientes=1;
                    }
                    else
                    {
                        printf("\nERROR, el arbol esta vacio");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }
                }
                else if (opcionCaja==4)
                {
                    if (flagCajaConClientes==1)
                    {

                        subMenu_caja_opcion4(cajita);
                        printf("\nClientes atendidos correctamente");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }
                    else
                    {
                        printf("\nLas cajas estan vacias");
                    }
                }
                else if (opcionCaja==5)
                {
                    subMenu_caja_opcion5(cajita);
                    printf("\nPresione cualquier tecla para continuar");
                    getch();
                }
                opcionCaja=menu_cajas();

            }
        }

    }

/*
    int menu=15;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;
    int k=0;
    int posicion=-1;
    while (menu!=0)
    {
        printf("\nMENU:\n");
        printf("1) Carga de los clientes segun metodo de recorrido y se muestran como quedan las cajas");
        printf("\n2) Calcular y mostrar los tiempos segun Algoritmos de Planificacion");
        printf("\n3) Ingresar cliente en tiempo determinado");
        printf("\n4) Ejecutar y mostrar tiempos nuevos con el cliente agregado");
        printf("\n5) Repetir");
        printf("\n6) Vaciar una caja, mostrando proceso a proceso");
        printf("\n7) Recorrer cajas y calcular tiempos de espera promedios");
        printf("\n");
        printf("\n0) Salir");
        printf("\n\nIngrese un numero: ");
        scanf("%d", &menu);
        if (menu==1)
        {
            opcion1(cajita,cliente,cantidadDeCajas);
            flag1++;
        }
        if (menu==2)
        {
            if(flag1==1)
            {
                opcion2(cajita,cantidadDeCajas);
            }
            else
            {
                printf("\nEs necesario que primero se llame a la opcion 1\nYa que no hay clientes en las cajas");
            }
        }
        if (menu==3)
        {
            if (flag1==1)
            {
                posicion=opcion3(cajita);
                flag2++;
            }
            else
            {
                printf("No hay clientes en las cajas.")
            }
        }
        if (menu==4)
        {
            if (flag2==1)
            {
                opcion4(cajita,posicion);
                flag3++;
            }
            else
            {
                printf("\nEs necesario que primero se llame a la opcion 3\nYa que aun no se agrego un cliente nuevo");
            }
        }
        if (menu==5)
        {
            if (flag3==1)
            {
                opcion5(cajita,cantidadDeCajas);
            }
            else
            {
                printf("\nEs necesario que primero se llame a la opcion 4\nYa que aun no hay clientes que quitar");
            }
        }
        if (menu==6)
        {
            opcion6(cajita,cantidadDeCajas);
        }
        if (menu==7)
        {
            while (k<cantidadDeCajas)
            {
                if (cajita[k].abiertaOcerrada==1)
                {
                    flag4=1;

                }
                k++;
            }
            if (flag4==1)
            {
                int z=0;
                float promediosE[12];
                float promediosR[12];
                char mander='s';
                promedioCajas(cajita,cantidadDeCajas,promediosE,promediosR);
                printf("\nDesea mostrar los promedios de cada caja? S/N: ");
                fflush(stdin);
                scanf("%c",&mander);
                if (mander=='s')
                {
                    while(z<cantidadDeCajas)
                    {
                        mostrarCaja(cajita[z]);
                        printf("\nPromedio de tiempo de espera : %f",promediosE[z]);
                        printf("\nPromedio de tiempo de procesado : %f",promediosR[z]);
                        printf("\nPromedio de ambos es : %f\n\n",((promediosE[z]+promediosR[z])/2));
                        z++;
                        printf("\nPromedio de tiempo de espera : %f\n",promediosE[z]);
                        printf("\nPromedio de tiempo de procesado : %f\n",promediosR[z]);
                        printf("\nPromedio de ambos es : %f",((promediosE[z]+promediosR[z])/2));
                    }
                }
            }
            else
            {
                printf("\nNo hay ninguna caja abierta para promediar");
            }

        }
    }*/
    return 0;
}
