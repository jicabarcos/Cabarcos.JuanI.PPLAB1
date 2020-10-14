#ifndef FUNCIONESAUTOS_H_INCLUDED
#define FUNCIONESAUTOS_H_INCLUDED

typedef struct{

    int id;
    char patente[6];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

#endif // FUNCIONESAUTOS_H_INCLUDED

#include "funcionesColores.h"
#include "funcionesMarcas.h"

int inicializarAutos(eAuto autos[], int tamA);

char menuDeOpciones(int tipoDeMenu);

int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int id);

int buscarAutoLibre(eAuto autos[], int tamA);

int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int buscarAutoPorPatente(eAuto autos[], int tamA, char patente[]);

int mostrarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamM, eColor colores[], int tamC);

int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);

int ordenarPorMarcaYPatente(eAuto autos[], int tamA, int ordenPatente, int ordenMarca);

