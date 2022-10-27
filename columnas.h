#ifndef COLUMNAS_H
#define COLUMNAS_H

#include "columnaSingular.h"
#include "define.h"


typedef struct nodo_columnas * columnas;

// TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// crea una columna dentro de una tabla.
// pre: tiene que existir una tabla.
// pre: no puede haber otra columna con el mismo nombre.
// pre: no puede haber 2 primary key

columnas crearColumnas();

columnas crearColumnasNULL();

char * getColumnaSingularNombre_Columnas(columnas col);

columnas getColumnaSig_Columnas(columnas col);

void crearColumSingular_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol);


char * getColumnaSingularTipoDato_Columnas(columnas col);

char * getColumnaSingularCalificador_Columnas(columnas col);

bool isColumnasEmpty_Columnas(columnas col);

bool compararNombreColumnaSingular_Columnas(columnas col, char * nombreC);

bool isColumnasSingularEmpty_Columnas(columnas col);

TipoRet crearColumnaSingular_Columnas(columnas col, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);




#endif