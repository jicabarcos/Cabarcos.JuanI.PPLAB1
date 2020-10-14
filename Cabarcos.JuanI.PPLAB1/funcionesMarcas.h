#ifndef FUNCIONESMARCAS_H_INCLUDED
#define FUNCIONESMARCAS_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

}eMarca;

#endif // FUNCIONESMARCAS_H_INCLUDED

void mostrarMarcas(eMarca marcas[], int tamM);

void mostrarMarca(eMarca marca);

int cargarDescripcionMarca(eMarca marcas[], int tamM, int id, char descripcionM[]);
