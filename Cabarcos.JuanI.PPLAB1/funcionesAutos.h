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


/** \brief setea los isEmpty en 1
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \return error verifica funcionamiento
 *
 */
int inicializarAutos(eAuto autos[], int tamA);


/** \brief abre los distintos menues
 *
 * \param tipoDeMenu para cambiar entre los menues
 * \return opcionMenu la eleccion del usuario
 *
 */
char menuDeOpciones(int tipoDeMenu);


/** \brief da de alta un auto
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \param id numero identificador del auto en el listado
 * \return error verifica funcionamiento
 *
 */
int altaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, int id);


/** \brief busca el primer auto cuyo isEmpty este en 1
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \return indice ubicacion del auto en el array
 *
 */
int buscarAutoLibre(eAuto autos[], int tamA);


/** \brief modifica algun/os campo/s de un elemento del array
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \param id numero identificador del auto en el listado
 * \return error verifica funcionamiento
 *
 */
int modificarAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief ubica un auto que corresponda a la patente ingresada
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param patente dato a buscar, ingresado por el usuario
 * \return retorno indice del array en el que esta el auto
 *
 */
int buscarAutoPorPatente(eAuto autos[], int tamA, char patente[]);


/** \brief muestra listado de todos los autos
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int mostrarAutos(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief muestra un auto
 *
 * \param unAuto un elemento del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return void
 *
 */
void mostrarAuto(eAuto unAuto, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief da de baja un auto de la lista (baja logica con isEmpty)
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int bajaAuto(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief ordena el listado de autos
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param ordenPatente criterio de ordenamiento
 * \param ordenMarca criterio de ordenamiento
 * \return error verifica funcionamiento
 *
 */
int ordenarPorMarcaYPatente(eAuto autos[], int tamA, int ordenPatente, int ordenMarca);


/** \brief muestra autos de un determinado color
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int mostrarAutosPorColor(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief muestra autos de una determinada marca
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int mostrarAutosPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief busca el auto con el modelo mas antiguo
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int buscarAutoMasViejo(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief muestra listado de autos que pertenecen a cada marca
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int mostrarAutosSeparadosPorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief cuenta los autos que hay de cierto color y marca
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int cantidadAutosColorYMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);


/** \brief informa cual es la marca con mas autos
 *
 * \param autos array de autos
 * \param tamA tamaño del array de autos
 * \param marcas array de marcas
 * \param tamM tamaño del array de marcas
 * \param colores array de colores
 * \param tamC tamaño del array de colores
 * \return error verifica funcionamiento
 *
 */
int marcaMasElegida(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
