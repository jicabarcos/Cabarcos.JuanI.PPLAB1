#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesServicios.h"

void mostrarServicios(eServicio servicios[], int tamS){

    if((servicios != NULL) && (tamS > 0)){

        printf("       ***  SERVICIOS  ***  \n\n");
        printf("   ID      Descripcion     Precio\n");
        printf("---------------------------------\n");
        for(int i = 0; i < tamS; i++){

            mostrarServicio(servicios[i]);

        }

    }
    printf("\n\n");

}

void mostrarServicio(eServicio servicio){

    printf("  %d       %s    %.2f\n", servicio.id, servicio.descripcion, servicio.precio);

}
