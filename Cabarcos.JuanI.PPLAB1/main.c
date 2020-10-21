#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesAutos.h"
#include "funcionesColores.h"
#include "funcionesMarcas.h"
#include "funcionesServicios.h"
#include "funcionesTrabajos.h"

#define TAM_MARCA 5
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_AUTO 5
#define TAM_TRABAJO 5
#define ASC 1
#define DESC 0

int main()
{

    // VARIABLES
    eAuto listaAutos[TAM_AUTO];
    eTrabajo listaTrabajos[TAM_TRABAJO];
    char eleccionMenuPrincipal;
    int flagAltaAuto = 0;
    int flagAltaTrabajo = 0;
    int proximoIdAuto = 1;
    int proximoIdTrabajo = 1;
    char eleccionMenuInformes;
    char salida;

    // HARDCODE
    eMarca listaMarcas[TAM_MARCA] = {{1000, "Renault"}, {1001, "Fiat"}, {1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    eColor listaColores[TAM_COLOR] = {{5000, "Negro"}, {5001, "Blanco"}, {5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eServicio listaServicios[TAM_SERVICIO] = {{20000, "Lavado  ", 250}, {20001, "Pulido  ", 300}, {20002, "Encerado", 400}, {20003, "Completo", 600}};

    if((!inicializarAutos(listaAutos, TAM_AUTO)) && (!inicializarTrabajos(listaTrabajos, TAM_TRABAJO))){

        printf("Preparando programa...\n\n");

    }
    else{

        printf("Error al iniciar programa.\n\n");

    }

    system("pause");

    do{

        eleccionMenuPrincipal = menuDeOpciones(0);

        switch(eleccionMenuPrincipal){

            case 'A':
                // ALTA
                if(!altaAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR, proximoIdAuto)){

                    printf("Alta exitosa!\n\n");
                    proximoIdAuto++;
                    flagAltaAuto = 1;

                }
                else{

                    printf("No se pudo dar de alta.\n\n");

                }
                break;

            case 'B':
                // MODIFICAR
                if(flagAltaAuto){

                    if(modificarAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR) == 0){

                        printf("Modificacion exitosa!!\n\n");

                    }
                    else if(modificarAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR) == 1){

                        printf("Error al intentar modificar.\n\n");

                    }
                    else{

                        printf("Modificacion cancelada por el usuario.\n\n");

                    }
                }
                else{

                    printf("\nAntes de intentar modificar, tiene que dar de alta al menos un auto!\n");

                }
                break;

            case 'C':
                // BAJA
                if(flagAltaAuto){

                    if(bajaAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR) == 0){

                        printf("Baja exitosa!!\n\n");

                    }
                    else if(bajaAuto(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR) == 1){

                        printf("Error al intentar dar la baja.\n\n");

                    }
                    else{

                        printf("Baja cancelada por el usuario.\n\n");

                    }

                }
                else{

                    printf("\nAntes de intentar dar de baja, tiene que dar de alta al menos un auto!\n");

                }
                break;

            case 'D':
                // LISTAR AUTOS
                if(flagAltaAuto){

                    system("cls");
                    ordenarPorMarcaYPatente(listaAutos, TAM_AUTO, ASC, DESC);
                    mostrarAutos(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);

                }
                else{

                    printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                }
                break;

            case 'E':
                // LISTAR MARCAS
                system("cls");
                mostrarMarcas(listaMarcas, TAM_MARCA);
                break;

            case 'F':
                // LISTAR COLORES
                system("cls");
                mostrarColores(listaColores, TAM_COLOR);
                break;

            case 'G':
                // LISTAR SERVICIOS
                system("cls");
                mostrarServicios(listaServicios, TAM_SERVICIO);
                break;

            case 'H':
                // ALTA TRABAJO
                if(flagAltaAuto){

                    if(!altaTrabajo(listaTrabajos, TAM_TRABAJO, listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR, listaServicios, TAM_SERVICIO, proximoIdTrabajo)){

                        printf("Alta realizada con exito!\n\n");
                        proximoIdTrabajo++;
                        flagAltaTrabajo = 1;

                    }
                    else{

                        printf("No se pudo dar de alta.\n");

                    }


                }
                else{

                    printf("\nAntes de intentar realizar un trabajo, tiene que dar de alta al menos un auto!\n");

                }
                break;

            case 'I':
                // LISTAR TRABAJOS
                if(flagAltaTrabajo){

                    system("cls");
                    mostrarTrabajos(listaTrabajos, TAM_TRABAJO, listaAutos, TAM_AUTO, listaServicios, TAM_SERVICIO);

                }
                else{

                    printf("\nAntes de intentar listar los trabajos, se tiene que realizar al menos uno!\n");

                }
                break;

            case 'J':
                // INFORMES
                eleccionMenuInformes = menuDeOpciones(2);

                switch(eleccionMenuInformes){

                    case 'A':
                        // LISTAR AUTOS DE DETERMINADO COLOR
                        if(flagAltaAuto){

                            system("cls");
                            mostrarAutosPorColor(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);

                        }
                        else{

                            printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                        }
                        break;

                    case 'B':
                        // LISTAR AUTOS DE DETERMINADA MARCA
                        if(flagAltaAuto){

                            system("cls");
                            mostrarAutosPorMarca(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);

                        }
                        else{

                            printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                        }
                        break;

                    case 'C':
                        // INFORMAR AUTO/S MAS VIEJO/S
                        if(flagAltaAuto){

                            system("cls");
                            buscarAutoMasViejo(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);

                        }
                        else{

                            printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                        }
                        break;

                    case 'D':
                        // LISTADO DE AUTOS SEPARADOS POR MARCA
                        if(flagAltaAuto){

                            system("cls");
                            mostrarAutosSeparadosPorMarca(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);


                        }
                        else{

                            printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                        }
                        break;

                    case 'E':
                        // CANTIDAD DE AUTOS DE DETERMINADOS COLOR Y MARCA
                        if(flagAltaAuto){

                            system("cls");
                            cantidadAutosColorYMarca(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);

                        }
                        else{

                            printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                        }
                        break;

                    case 'F':
                        // MARCA/S MAS ELEGIDA/S
                        if(flagAltaAuto){

                            system("cls");
                            marcaMasElegida(listaAutos, TAM_AUTO, listaMarcas, TAM_MARCA, listaColores, TAM_COLOR);

                        }
                        else{

                            printf("\nAntes de intentar listar, tiene que dar de alta al menos un auto!\n");

                        }
                        break;

                }

        }

        printf("\n\nPresione 'X' para salir, otro caracter para continuar trabajando.");
        fflush(stdin);
        salida = toupper(getchar());



    }while(salida != 'X');

    printf("Gracias por usar el programa!!\n\n");

    return 0;

}
