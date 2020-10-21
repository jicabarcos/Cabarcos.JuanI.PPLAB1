#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesTrabajos.h"
#include "funcionesServicios.h"
#include "validaciones.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamT){

    int error = 1;

    if((trabajos != NULL) && (tamT > 0)){

        for(int i = 0; i < tamT; i++){

            trabajos[i].isEmpty = 1;

        }

        error = 0;

    }

    return error;

}

int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, int id){

    int error = 1;
    int indiceLibre;
    int indicePatente;
    eTrabajo nuevoTrabajo;
    char patente[6];
    int servicioValido;
    int diaValido;
    int mesValido;
    int anioValido;

    if((trabajos != NULL) && (tamT > 0) && (id > 0)){

        system("cls");
        indiceLibre = buscarTrabajoLibre(trabajos, tamT);
        if(indiceLibre == -1){

            printf("No hay cupo para realizar mas trabajos.\n");

        }
        else{

            printf("*** ALTA TRABAJO ***\n\n");
            // INGRESO DATOS TRABAJO
            nuevoTrabajo.id = id;

            nuevoTrabajo.isEmpty = 0;

            mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
            printf("Elija la patente del auto al que desea realizarle un trabajo: \n");
            fflush(stdin);
            gets(patente);

            indicePatente = buscarAutoPorPatente(autos, tamA, patente);

            if(indicePatente == -1){

                printf("No hay ningun auto ingresado con esa patente.\n");

            }
            else{

                strcpy(nuevoTrabajo.patente, patente);
                printf("Auto seleccionado:\n");
                mostrarAuto(autos[indicePatente], marcas, tamM, colores, tamC);
                printf("\n\n");
                mostrarServicios(servicios, tamS);
                do{

                    servicioValido = getValidInt("Ingrese ID del servicio a realizar:\n", "Debe estar entre 20000 y 20003. Vuelva a ingresar.\n", &nuevoTrabajo.idServicio, 20000, 20003, 1);

                }while(servicioValido == -1);
                printf("Ingrese fecha:\n");
                do{

                    diaValido = getValidInt("Dia: ", "Debe estar entre 1 y 31. Vuelva a ingresar.\n", &nuevoTrabajo.fecha.dia, 1, 31, 1);

                }while(diaValido == -1);
                do{

                    mesValido = getValidInt("Mes: ", "Debe estar entre 1 y 12. Vuelva a ingresar: ", &nuevoTrabajo.fecha.mes, 1, 12, 1);

                }while(mesValido == -1);
                do{

                    anioValido = getValidInt("Anio: ", "Debe estar entre 1990 y 2020. Vuelva a ingresar: ", &nuevoTrabajo.fecha.anio, 1990, 2020, 1);

                }while(anioValido == -1);

            }

            trabajos[indicePatente] = nuevoTrabajo;
            error = 0;

        }

    }

    return error;

}

int buscarTrabajoLibre(eTrabajo trabajos[], int tamT){

    int indice = -1;

    for(int i = 0; i < tamT; i++){

        if(trabajos[i].isEmpty){

            indice = i;
            break;

        }

    }

    return indice;

}

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS){

    int error = 1;
    int flag = 0;

    if((trabajos != NULL) && (tamT > 0)){

        printf("          *** LISTADO DE TRABAJOS ***\n\n");
        printf("    ID    Patente      Servicio      Fecha\n");
        printf("----------------------------------------------\n");
        for(int i = 0; i < tamT; i++){

            if(trabajos[i].isEmpty == 0){

                mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS);
                flag = 1;

            }

        }
        if(!flag){

            printf("No hay trabajos en la lista.\n");

        }
        else{

            printf("\n\n");

        }

        error = 0;

    }

    return error;

}

void mostrarTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS){

    char descripcionServicio[20];

    if(!cargarDescripcionServicioParaTrabajo(servicios, tamS, unTrabajo.idServicio, descripcionServicio)){

        printf(" %4d  %10s  %10s        %d/%d/%d\n", unTrabajo.id, unTrabajo.patente, descripcionServicio, unTrabajo.fecha, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);

    }
    else{

        printf("Problema para recuperar descripcion del trabajo.");

    }


}
