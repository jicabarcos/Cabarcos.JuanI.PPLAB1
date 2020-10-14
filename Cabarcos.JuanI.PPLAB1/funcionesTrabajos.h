#ifndef FUNCIONESTRABAJOS_H_INCLUDED
#define FUNCIONESTRABAJOS_H_INCLUDED

#include "funcionesAutos.h"
#include "funcionesColores.h"
#include "funcionesMarcas.h"
#include "funcionesServicios.h"
#include "fecha.h"

typedef struct{

    int id;
    char patente[6];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // FUNCIONESTRABAJOS_H_INCLUDED


int inicializarTrabajos(eTrabajo trabajos[], int tamT);

int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, int id);

int buscarTrabajoLibre(eTrabajo trabajos[], int tamT);

int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS);

void mostrarTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS);
