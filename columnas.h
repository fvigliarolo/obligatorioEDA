#ifndef COLUMNAS_H
#define COLUMNAS_H

#include "columnaSingular.h"
#include "define.h"


typedef struct nodo_columnas * columnas;


columnas crearColumnas();

columnas crearColumnasNULL();

void crearColumnaSingularVOID_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol);

bool isColumnasEmpty_Columnas(columnas col);

TipoRet crearColumnaSingular_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol);
// Agrega una columna nueva a la tabla.

TipoRet estructuraTablas_Columnas(columnas & col, char *nombreTabla);
// Devuelve la estructura de las columnas de la tabla.

TipoRet InsertInto_Columnas(columnas & col, char *columnasTupla, char *valoresTupla);
// Intenta realizar una insercion de datos en la tabla indicada por el usuario.

bool existeColumnaSingular(columnaSingular cs, char * NombreCol);

TipoRet EliminarColumnaSing_columnas(columnas & Colum, char *NombreColS);

TipoRet printdatatable_columna(columnas col, char *NombreTabla);



#endif