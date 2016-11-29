#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

///A LAS CAJAS. EN MOSTRAR RR MOSTRAR QUANTUM A QUANTUM.
int main()
{
    system("color 3");///cambio a color amigable de fondo y fuente

    char archi_cliente[25];
    char archi_caja[25];
    int control;
    printf("Bienvenido a U.T.N Mart.\n\n");
    printf("MENU INICIAL\n");
    printf("\n[1] Usar archivos locales");
    printf("\n[2] Usar archivos externos");
    printf("\nIngrese un numero: ");
    scanf("%d",&control);
    while ((control<1) || (control>2))
    {
        printf("\nERROR\nIngrese una opcion valida");///verificamos que ingrese una opcion valida
        scanf("%d",&control);
    }
    if(control==1)///si usamos los archivos locales estos son sus nombres
    {
        strcpy(archi_cliente,"cliente.bin");
        strcpy(archi_caja,"caja.bin");

    }
    else if (control==2)///sino debemos obtenerlos
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
                    if (flagArbol==0)///esto es para comprobar que el arbol no se cargue de mas
                    {
                        arbol=subMenu_arbol_opcion1(archi_cliente,arbol);
                        printf("\nArbol cargado exitosamente");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                        flagArbol=1;
                    }
                    else
                    {
                        printf("\nERROR, el arbol ya ha sido cargado");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }

                }
                else if (opcionArbol==2)
                {
                    if (flagArbol==1)///nos sirce para comprobar que primero haya pasado al arbol los clientes del archivo
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
                    controlOpcion1Caja=subMenu_caja_opcion1(cajita,cantidadDeCajas);
                    while (controlOpcion1Caja>0)
                    {
                        controlOpcion1Caja=subMenu_caja_opcion1(cajita,cantidadDeCajas);
                    }

                }
                else if (opcionCaja==2)
                {
                    controlOpcion2Caja=subMenu_caja_opcion2(cajita,cantidadDeCajas);
                    while (controlOpcion2Caja>0)
                    {
                        controlOpcion2Caja=subMenu_caja_opcion2(cajita,cantidadDeCajas);
                    }
                }
                else if (opcionCaja==3)
                {
                    if (flagArbol==1)
                    {
                        if (flagCajaConClientes==0)
                        {
                            subMenu_caja_opcion3(cajita,arbol,cantidadDeCajas);
                            flagCajaConClientes=1;
                        }
                        else
                        {
                            printf("\nERROR, las cajas ya han sido cargadas");
                            printf("\nPresione cualquier tecla para continuar");
                            getch();

                        }

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
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }
                }
                else if (opcionCaja==5)
                {
                    if (flagCajaConClientes==1)
                    {
                        subMenu_caja_opcion5(cajita);
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }
                    else
                    {
                        printf("\nPimero deberia cargar las cajas");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }

                }
                else if (opcionCaja==6)
                {
                    if (flagCajaConClientes==1)
                    {
                        subMenu_caja_opcion6(cajita,cantidadDeCajas);
                        flagCajaConClientes=0;
                    }
                    else
                    {
                        printf("\nPrimero debe cargar las cajas");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }

                }
                else if (opcionCaja==7)
                {
                    if (flagCajaConClientes==1)
                    {
                        subMenu_caja_opcion7(cajita,cantidadDeCajas);
                    }
                    else
                    {
                        printf("\nPrimero debe cargar las cajas");
                        printf("\nPresione cualquier tecla para continuar");
                        getch();
                    }

                }
                opcionCaja=menu_cajas();
            }
        }
    }
    return 0;
}
