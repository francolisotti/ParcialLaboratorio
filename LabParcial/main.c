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

    Mostrar_Archivos(archi_cliente,archi_caja);



    caja cajita[12];
    nodoArbol * cliente=inicArbol();

    int cantidadDeCajas=pasarDeArchiAcaja_yContar(archi_caja,cajita);
    cliente=ArchiToArbol(archi_cliente,cliente);


    int menu=15;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int posicion=-1;
    while (menu!=0)
    {
        printf("\nMENU:\n");
        printf("1) Carga de los clientes según metodo de recorrido y se muestran como quedan las cajas");
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
            posicion=opcion3(cajita);
            flag2++;
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
                }
            }
        }


    }
    return 0;
}
