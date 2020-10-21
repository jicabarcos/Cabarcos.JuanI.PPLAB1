#ifndef FUNCIONESMARCAS_H_INCLUDED
#define FUNCIONESMARCAS_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

}eMarca;

#endif // FUNCIONESMARCAS_H_INCLUDED


/** \brief lista las marcas
 *
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \return void
 *
 */
void mostrarMarcas(eMarca marcas[], int tamM);


/** \brief muestra una sola marca
 *
 * \param marca un elemento del array marcas
 * \return void
 *
 */
void mostrarMarca(eMarca marca);


/** \brief relaciona la estructura marcas con la estructura autos
 *
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param id identificador de marca
 * \param descripcionM descripcion de marca
 * \return error verifica funcionamiento
 *
 */
int cargarDescripcionMarca(eMarca marcas[], int tamM, int id, char descripcionM[]);
