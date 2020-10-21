#ifndef FUNCIONESCOLORES_H_INCLUDED
#define FUNCIONESCOLORES_H_INCLUDED

typedef struct{

    int id;
    char nombreColor[20];

}eColor;

#endif // FUNCIONESCOLORES_H_INCLUDED


/** \brief lista los colores
 *
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return void
 *
 */
void mostrarColores(eColor colores[], int tamC);


/** \brief muestra un solo color
 *
 * \param color un elemento del array colores
 * \return void
 *
 */
void mostrarColor(eColor color);


/** \brief relaciona la estructura colores con la estructura autos
 *
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \param id identificador de color
 * \param descripcionM descripcion de color
 * \return error verifica funcionamiento
 *
 */
int cargarDescripcionColor(eColor colores[], int tamC, int id, char descripcionC[]);
