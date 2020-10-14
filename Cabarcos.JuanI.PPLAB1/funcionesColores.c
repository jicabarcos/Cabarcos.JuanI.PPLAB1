#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesColores.h"

void mostrarColores(eColor colores[], int tamC){

    if((colores != NULL) && (tamC > 0)){

        printf("       ***  COLORES  ***  \n\n");
        printf("       ID      Descripcion\n");
        printf("    -----------------------\n");
        for(int i = 0; i < tamC; i++){

            mostrarColor(colores[i]);

        }

    }
    printf("\n\n");

}

void mostrarColor(eColor color){

    printf("      %d       %s\n", color.id, color.nombreColor);

}

int cargarDescripcionColor(eColor colores[], int tamC, int id, char descripcionC[]){

    int error = 1;

    if(colores != NULL && tamC > 0 && id > 0 && descripcionC != NULL){

        for(int i = 0; i < tamC; i++){

            if(colores[i].id == id){

                strcpy(descripcionC, colores[i].nombreColor);
                error = 0;
                break;

            }

        }

    }
    return error;

}
