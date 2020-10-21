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


/** \brief setea los isEmpty en 1
 *
 * \param trabajos array de trabajos
 * \param tamT tamaño del array de trabajos
 * \return
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tamT);


/** \brief da de alta un trabajo
 *
 * \param trabajos array de trabajos
 * \param tamT tamaño del array de trabajos
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \param servicios array de servicios
 * \param tamS tamaño del array de servicios
 * \param id identificador de trabajos
 * \return error verifica funcionamiento
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eServicio servicios[], int tamS, int id);


/** \brief busca el primer trabajo cuyo isEmpty este en 1
 *
 * \param trabajos array de trabajos
 * \param tamT tamaño del array de trabajos
 * \return indice ubicacion en el array
 *
 */
int buscarTrabajoLibre(eTrabajo trabajos[], int tamT);


/** \brief lista todos los trabajos realizados
 *
 * \param trabajos array de trabajos
 * \param tamT tamaño del array de trabajos
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param servicios array de servicios
 * \param tamS tamaño del array de servicios
 * \return error verifica funcionamiento
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS);


/** \brief muestra un trabajo
 *
 * \param unTrabajo un elemento del array trabajos
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param servicios array de servicios
 * \param tamS tamaño del array de servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamA, eServicio servicios[], int tamS);
