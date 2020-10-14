#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesMarcas.h"

void mostrarMarcas(eMarca marcas[], int tamM){

    if((marcas != NULL) && (tamM > 0)){

        printf("  ***  MARCAS DE AUTOS  ***  \n\n");
        printf("       ID      Descripcion\n");
        printf("    -----------------------\n");
        for(int i = 0; i < tamM; i++){

            mostrarMarca(marcas[i]);

        }

    }
    printf("\n\n");

}

void mostrarMarca(eMarca marca){

    printf("      %d       %s\n", marca.id, marca.descripcion);

}

int cargarDescripcionMarca(eMarca marcas[], int tamM, int id, char descripcionM[]){

    int error = 1;

    if(marcas != NULL && tamM > 0 && id > 0 && descripcionM != NULL){

        for(int i = 0; i < tamM; i++){

            if(marcas[i].id == id){

                strcpy(descripcionM, marcas[i].descripcion);
                error = 0;
                break;

            }

        }

    }
    return error;

}
