#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED

typedef struct{

    int id;
    char descripcion[25];
    float precio;

}eServicio;

#endif // FUNCIONESSERVICIOS_H_INCLUDED


/** \brief lista todos los servicios
 *
 * \param servicios array de servicios
 * \param tamS tamaño del array de servicios
 * \return void
 *
 */
void mostrarServicios(eServicio servicios[], int tamS);


/** \brief muestra un servicio
 *
 * \param servicio un elemento del array de servicios
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);


/** \brief relaciona las estructuras servicio y trabajo
 *
 * \param servicios array de servicios
 * \param tamS tamaño del array de servicios
 * \param id identificador del servicio
 * \param descripcionS descripcion del servicio
 * \return error verifica funcionamiento
 *
 */
int cargarDescripcionServicioParaTrabajo(eServicio servicios[], int tamS, int id, char descripcionS[]);
