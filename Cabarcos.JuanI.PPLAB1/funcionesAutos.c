#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funcionesAutos.h"
#include "validaciones.h"

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
        printf(">> I) Listar trabajos\n\n");
        printf(">> J) Informes\n\n");
        printf("\nElija la opcion deseada: ");
        fflush(stdin);
        opcionMenu = toupper(getchar());
        while((opcionMenu < 65) || (opcionMenu > 74)){

                printf("Debe elegir una opcion valida, entre 'A' y 'J'. Vuelva a ingresar: ");
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
        while((opcionMenu < 65) || (opcionMenu > 66)){

                printf("Debe elegir una opcion valida, entre 'A' y 'B'. Vuelva a ingresar: ");
                fflush(stdin);
                opcionMenu = toupper(getchar());

        }

    }
    else if(tipoDeMenu == 2){

        system("cls");
        printf("\n *** MENU DE INFORMES ***\n\n");
        printf(">> A) Mostrar autos de un color\n\n");
        printf(">> B) Mostrar autos de una marca\n\n");
        printf(">> C) Informar el/los auto/s mas viejo/s\n\n");
        printf(">> D) Listar autos separados por marca\n\n");
        printf(">> E) Cantidad de autos de un color y de una marca\n\n");
        printf(">> F) Mostrar la/s marca/s mas elegida/s\n\n");
        printf("Elija la opcion deseada: ");
        fflush(stdin);
        opcionMenu = toupper(getchar());
        while((opcionMenu < 65) || (opcionMenu > 70)){

                printf("Debe elegir una opcion valida, entre 'A' y 'F'. Vuelva a ingresar: ");
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
    int idColorValido;
    int modeloAux;
    int modeloValido;
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
                        do{

                            idColorValido = getValidInt("\nElija el id del nuevo color:\n", "Debe ser un ID valido, entre 5000 y 5004, vuelva a ingresar.\n", &idColorAux, 5000, 5004, 1);

                        }while(idColorValido == -1);
                        break;

                    case 'B':

                        do{

                            modeloValido = getValidInt("\nElija nuevo modelo:\n", "Solo puede ingresar numeros enteros, vuelva a ingresar.\n", &modeloAux, 1900, 2020, 1);

                        }while(modeloValido == -1);
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

int ordenarPorMarcaYPatente(eAuto autos[], int tamA, int ordenPatente, int ordenMarca){

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

int mostrarAutosPorColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int flag = 0;
    int idColorABuscar;
    int idColorValido;

    if((autos != NULL) && (tamA > 0)){

        mostrarColores(colores, tamC);
        do{

            idColorValido = getValidInt("\nElija el ID del color del cual quiere mostrar los autos: ", "Debe ser un valor entre 5000 y 5004, vuelva a intentar.", &idColorABuscar, 5000, 5004, 1);


        }while(idColorValido == -1);

        printf("     ***  LISTADO DE AUTOS POR COLOR  ***\n\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idColor == idColorABuscar)){

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

int mostrarAutosPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int flag = 0;
    int idMarcaABuscar;
    int idMarcaValido;

    if((autos != NULL) && (tamA > 0)){

        mostrarMarcas(marcas, tamM);
        do{

            idMarcaValido = getValidInt("\nElija el ID de la marca de la cual quiere mostrar los autos: ", "Debe ser un valor entre 1000 y 1004, vuelva a intentar.", &idMarcaABuscar, 1000, 1004, 1);


        }while(idMarcaValido == -1);

        printf("      ***  LISTADO DE AUTOS POR MARCA ***\n\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == idMarcaABuscar)){

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

int buscarAutoMasViejo(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int flag = 0;
    int j = 0;
    eAuto autosViejos[tamA];

    if((autos != NULL) && (tamA > 0)){

        inicializarAutos(autosViejos, tamA);

        for(int i = 0; i < tamA; i++){

            if((flag == 0) || (autos[i].modelo < autosViejos[j].modelo) ){

                autosViejos[j] = autos[i];
                autosViejos[j].isEmpty = 0;
                flag = 1;

            }
            else if(autos[i].modelo == autosViejos[j].modelo){

                j++;
                autosViejos[j] = autos[i];
                autosViejos[j].isEmpty = 0;

            }

        }

    printf("El/Los auto/s mas viejo/s es/son:\n\n");
    mostrarAutos(autosViejos, tamA, marcas, tamM, colores, tamC);
    error = 0;

    }

    return error;

}

int mostrarAutosSeparadosPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int flag0 = 0;
    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    int flag4 = 0;

    if((autos != NULL) && (tamA > 0)){

        printf("      ***  LISTADO DE AUTOS SEPARADOS POR MARCA ***\n\n");
        printf(">>> RENAULT\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == 1000)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag0 = 1;

            }

        }
        if(!flag0){

            printf("   No hay autos en la lista.\n");

        }

        printf("\n>>> FIAT\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == 1001)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag1 = 1;

            }

        }
        if(!flag1){

            printf("   No hay autos en la lista.\n");

        }

        printf("\n>>> FORD\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == 1002)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag2 = 1;

            }

        }
        if(!flag2){

            printf("   No hay autos en la lista.\n");

        }

        printf("\n>>> CHEVROLET\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == 1003)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag3 = 1;

            }

        }
        if(!flag3){

            printf("   No hay autos en la lista.\n");

        }

        printf("\n>>> PEUGEOT\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == 1004)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag4 = 1;

            }

        }
        if(!flag4){

            printf("   No hay autos en la lista.\n");

        }

        error = 0;

    }

    return error;


}

int cantidadAutosColorYMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int idColorABuscar;
    int idColorValido;
    int idMarcaABuscar;
    int idMarcaValido;
    int contador = 0;
    int flag = 0;

    if((autos != NULL) && (tamA > 0)){

        mostrarMarcas(marcas, tamM);
        do{

            idMarcaValido = getValidInt("\nElija el ID de la marca de la cual quiere mostrar los autos: ", "Debe ser un valor entre 1000 y 1004, vuelva a intentar.", &idMarcaABuscar, 1000, 1004, 1);


        }while(idMarcaValido == -1);
        mostrarColores(colores, tamC);
        do{

            idColorValido = getValidInt("\nElija el ID del color del cual quiere mostrar los autos: ", "Debe ser un valor entre 5000 y 5004, vuelva a intentar.", &idColorABuscar, 5000, 5004, 1);


        }while(idColorValido == -1);

        printf("  ***  LISTADO DE AUTOS POR MARCA Y COLOR  ***\n\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == idMarcaABuscar) && (autos[i].idColor == idColorABuscar)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag = 1;
                contador++;

            }

        }

        if(!flag){

            printf("   No hay autos en la lista.\n");

        }
        else{

            printf("\n\n");

        }

        printf("Hay %d autos de la marca y color elegidos.", contador);
        error = 0;


    }

    return error;

}

int marcaMasElegida(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC){

    int error = 1;
    int contadores[5] = {0};
    int flag = 0;
    int mayor;
    int marcaMayor;
    int cantidad = 0;
    char descripcionMarca[20];

    if((autos != NULL) && (tamA > 0)){

        for(int i = 0; i < tamA; i++){

            if(autos[i].idMarca == 1000){

                contadores[0]++;

            }
            else if(autos[i].idMarca == 1001){

                contadores[1]++;

            }
            else if(autos[i].idMarca == 1002){

                contadores[2]++;

            }
            else if(autos[i].idMarca == 1003){

                contadores[3]++;

            }
            else if(autos[i].idMarca == 1004){

                contadores[4]++;

            }

        }

        for(int i = 0; i < tamA; i++){

            if((flag == 0) || (contadores[i] > mayor) ){

                mayor = contadores[i];
                flag = 1;

            }

        }

        if(mayor == contadores[0]){

            marcaMayor = 1000;

        }
        else if(mayor == contadores[1]){

            marcaMayor = 1001;

        }
        else if(mayor == contadores[2]){

            marcaMayor = 1002;

        }
        else if(mayor == contadores[3]){

            marcaMayor = 1003;

        }
        else if(mayor == contadores[4]){

            marcaMayor = 1004;

        }

        printf("***  LISTADO DE AUTOS DE LA MARCA MAS ELEGIDA  ***\n\n");
        printf("  ID     Patente     Marca     Color     Modelo\n");
        printf("-----------------------------------------------\n");
        for(int i = 0; i < tamA; i++){

            if((autos[i].isEmpty == 0) && (autos[i].idMarca == marcaMayor)){

                mostrarAuto(autos[i], marcas, tamM, colores, tamC);
                flag = 1;
                cantidad++;

            }

        }

        cargarDescripcionMarca(marcas, tamM, marcaMayor, descripcionMarca);
        printf("La marca mas elegida es %s.", descripcionMarca);

        error = 0;

    }

    return error;

}
