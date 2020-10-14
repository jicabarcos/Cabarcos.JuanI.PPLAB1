#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesAutos.h"

int inicializarAutos(eAuto autos[], int tamA){

    int error = 1;

    if((autos != NULL) && (tamA > 0)){

        for(int i = 0; i < tamA; i++){

            autos[i].isEmpty = 1;

        }

        error = 0;

    }

    return error;

}

char menuDeOpciones(int tipoDeMenu){

    char opcionMenu;

    if(tipoDeMenu == 0){

        system("cls");
        printf(" *** MENU PRINCIPAL ***\n\n");
        printf(">> A) Alta auto\n\n");
        printf(">> B) Modificar auto\n\n");
        printf(">> C) Baja auto\n\n");
        printf(">> D) Listar autos\n\n");
        printf(">> E) Listar marcas\n\n");
        printf(">> F) Listar colores\n\n");
        printf(">> G) Listar servicios\n\n");
        printf(">> H) Alta trabajo\n\n");
        printf(">> I) Listar trabajos\n\n\n");
        printf("Elija la opcion deseada: ");
        fflush(stdin);
        opcionMenu = toupper(getchar());
        while((opcionMenu < 65) && (opcionMenu > 73)){

                printf("Debe elegir una opcion valida, entre 'A' e 'I'. Vuelva a ingresar: ");
                fflush(stdin);
                opcionMenu = toupper(getchar());

        }

    }
    else if(tipoDeMenu == 1){

        printf(" *** MENU DE MODIFICACIONES ***\n\n");
        printf(">> A) Color\n\n");
        printf(">> B) Modelo\n\n");
        printf("Elija la opcion deseada: ");
        fflush(stdin);
        opcionMenu = toupper(getchar());
        while((opcionMenu < 65) && (opcionMenu > 66)){

                printf("Debe elegir una opcion valida, entre 'A' y 'B'. Vuelva a ingresar: ");
                fflush(stdin);
                opcionMenu = toupper(getchar());

        }

    }

    return opcionMenu;

}

int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int id){

    int error = 1;
    int indice;
    eAuto nuevoAuto;

    if((autos != NULL) && (tamA > 0) && (id > 0)){

        system("cls");
        indice = buscarAutoLibre(autos, tamA);
        if(indice == -1){

            printf("No pueden ingresarse mas autos.\n");

        }
        else{

            printf("*** ALTA AUTO ***\n\n");
            // INGRESO DATOS AUTO
            nuevoAuto.id = id;

            nuevoAuto.isEmpty = 0;

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(nuevoAuto.patente);

            mostrarMarcas(marcas, tamA);
            printf("Ingrese ID marca: ");
            scanf("%d", &nuevoAuto.idMarca);
            while(nuevoAuto.idMarca < 1000 || nuevoAuto.idMarca > 1004){

                printf("Debe ser un ID valido, entre 1000 y 1004. Vuelva a ingresar:\n");
                scanf("%d", &nuevoAuto.idMarca);

            }

            mostrarColores(colores, tamC);
            printf("Ingrese ID color: ");
            scanf("%d", &nuevoAuto.idColor);
            while(nuevoAuto.idColor < 5000 || nuevoAuto.idColor > 5004){

                printf("Debe ser un ID valido, entre 5000 y 5004. Vuelva a ingresar:\n");
                scanf("%d", &nuevoAuto.idColor);

            }

            printf("Ingrese modelo: ");
            scanf("%d", &nuevoAuto.modelo);

            autos[indice] = nuevoAuto;

            error = 0;

        }

    }

    return error;

}

int buscarAutoLibre(eAuto autos[], int tamA){

    int indice = -1;

    for(int i = 0; i < tamA; i++){

        if(autos[i].isEmpty){

            indice = i;
            break;

        }

    }

    return indice;

}



int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){  // 0 baja exitosa; 1 hubo problema; 2 cancelado

    int error = 1;
    int indice;
    char patente[6];
    char eleccionMenu;
    int idColorAux;
    int modeloAux;
    char salida;
    char confirma;

    if((autos != NULL) && (tamA > 0)){

        system("cls");
        printf("*** MODIFICAR AUTO ***\n\n");
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("Ingrese patente: ");
        fflush(stdin);
        gets(patente);

        indice = buscarAutoPorPatente(autos, tamA, patente);

        idColorAux = autos[indice].idColor;
        modeloAux = autos[indice].modelo;

        if(indice == -1){

            printf("No hay ningun auto ingresado con esa patente.\n\n");

        }
        else{

            printf("Auto seleccionado:\n");
            mostrarAuto(autos[indice], marcas, tamM, colores, tamC);
            printf("\nQue desea modificar?\n\n");

            do{

                eleccionMenu = menuDeOpciones(1);

                switch(eleccionMenu){

                    case 'A':

                        printf("\n");
                        mostrarColores(colores, tamC);
                        printf("Elija el id del nuevo color:\n");
                        scanf("%d", &idColorAux);
                        while(idColorAux < 5000 || idColorAux > 5004){

                            printf("Debe ser un ID valido, entre 5000 y 5004. Vuelva a ingresar:\n");
                            scanf("%d", &idColorAux);

                        }
                        break;

                    case 'B':

                        printf("Ingrese nuevo modelo:\n");
                        scanf("%d", &modeloAux);
                        break;

                }

                printf("Ingrese 'S' para realizar otro cambio u otro caracter para finalizar.\n");
                fflush(stdin);
                salida = toupper(getchar());

            }while(salida == 'S');

            printf("Ingrese 'S' para confirmar las modificaciones u otro caracter para cancelar.\n");
            fflush(stdin);
            confirma = toupper(getchar());

            if((confirma == 'S')){

                if(autos[indice].idColor != idColorAux){

                    autos[indice].idColor = idColorAux;

                }
                if(autos[indice].modelo != modeloAux){

                    autos[indice].modelo = modeloAux;

                }
                error = 0;

            }
            else{

                error = 2;

            }

        }

    }

    return error;

}

int buscarAutoPorPatente(eAuto autos[], int tamA, char patente[]){

    int retorno = -1;

    for(int i = 0; i < tamA; i++){

        if((!strcmp(autos[i].patente, patente)) && (!autos[i].isEmpty)){

            retorno = i;
            break;

        }

    }

    return retorno;

}

int mostrarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int flag = 0;

    if((autos != NULL) && (tamA > 0)){

        printf("           ***  LISTADO DE AUTOS  ***\n\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if(autos[i].isEmpty == 0){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag = 1;

            }

        }

        if(!flag){

            printf("   No hay autos en la lista.\n");

        }
        else{

            printf("\n\n");

        }

        error = 0;

    }

    return error;

}

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamM, eColor colores[], int tamC){

    char descripcionMarca[20];
    char descripcionColor[20];

    if((!cargarDescripcionMarca(marcas, tamM, unAuto.idMarca, descripcionMarca)) && (!cargarDescripcionColor(colores, tamC, unAuto.idColor, descripcionColor))){

        printf(" %4d  %10s  %7s  %7s      %4d\n", unAuto.id, unAuto.patente, descripcionMarca, descripcionColor, unAuto.modelo);

    }
    else{

        printf("Problema para recuperar descripcion del auto.\n\n");

    }

}

int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int indice;
    char patente[6];
    char confirma;

    if((autos != NULL) && (tamA > 0)){

        system("cls");
        printf("*** BAJA AUTO ***\n\n");
        mostrarAutos(autos, tamA, marcas, tamM, colores, tamC);
        printf("\nIngrese patente del auto a dar de baja: ");
        fflush(stdin);
        gets(patente);

        indice = buscarAutoPorPatente(autos, tamA, patente);

        if(indice == -1){

            printf("\nNo hay ningun auto ingresadp con esa patente.\n\n");

        }
        else{

            printf("Auto seleccionado:\n");
            mostrarAuto(autos[indice], marcas, tamM, colores, tamC);
            printf("\nConfirma la baja? 'S' para confirmar, otro caracter para rechazar\n");
            fflush(stdin);
            confirma = toupper(getchar());
            printf("\n");
            if(confirma == 'S'){

                autos[indice].isEmpty = 1;
                error = 0;

            }
            else{

                error = 2;

            }

        }

    }

    return error;

}

int ordenarPorMarcaYPatente(eAuto autos[], int tamA, int ordenPatente, int ordenMarca){ // me quedo al revez, ordena primero por edad y dsp tipo

    int error = 1;
    int i;
    int j;
    eAuto autoAux;

    if(autos != NULL && tamA > 0 && ordenMarca >= 0 && ordenMarca <= 1 && ordenPatente >= 0 && ordenPatente <= 1){

        for(i = 0; i < tamA - 1; i++){

            for(j = i + 1; j < tamA; j++){

                // CRITERIOS DE ORDENAMIENTO
                if((ordenMarca && (autos[i].idMarca > autos[j].idMarca)) ||
                ((!ordenMarca) && (autos[i].idMarca < autos[j].idMarca)) ||
                (((autos[i].idMarca == autos[j].idMarca)) && ((strcmp(autos[i].patente, autos[j].patente) == 1) && ordenPatente)) ||
                ((autos[i].idMarca == autos[j].idMarca) && ((strcmp(autos[i].patente, autos[j].patente) == -1) && !ordenPatente))){

                    // SWAP / BURBUJEO
                    autoAux = autos[i];
                    autos[i] = autos[j];
                    autos[j] = autoAux;

                }

            }

        }

        error = 0;

    }

    return error;

}



