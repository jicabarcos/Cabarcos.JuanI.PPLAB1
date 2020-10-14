#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

typedef struct{

    int id;
    char descripcion[25];
    float precio;

}eServicio;

#endif // FUNCIONESSERVICIOS_H_INCLUDED

void mostrarServicios(eServicio servicios[], int tamS);

void mostrarServicio(eServicio servicio);

int cargarDescripcionServicioParaTrabajo(eServicio servicios[], int tamS, int id, char descripcionS[]);
