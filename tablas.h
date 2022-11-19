#ifndef TABLAS_H
#define TABLAS_H

#include "tabla.h"
#include "define.h"

typedef struct nodo_tablas * tablas;

bool isTablasEmpty_Tablas(tablas & ts);
// Devuelve true si ts es NULL.

void imprimirTablas(tablas ts);

tablas crearTablas();
// Crea el conjunto de tablas vacio.

TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla);
// Crea la tabla de nombre "nombreTabla" en tablas.

TipoRet EliminarTabla_tablas(tablas & ts, char *nombreTabla);
// llama a la funcion eliminartabla 

TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// crea una columna dentro de una tabla.
// pre: tiene que existir una tabla.
// pre: no puede haber otra columna con el mismo nombre.
// pre: no puede haber 2 primary key

tablas crearColumnas_Tablas(tablas & ts);
// Agrega una columna nueva a la tabla.

TipoRet InsertInto_Tablas(tablas & ts, char *nombreTabla, char *columnasTupla, char *valoresTupla);
// Intenta realizar una insercion de datos en la tabla indicada por el usuario.

TipoRet estructuraTablas_tablas(tablas & ts, char *nombreTabla);
// Devuelve la estructura de las columnas de la tabla.

TipoRet EliminarColumnaSing_tablas(tablas & ts, char *nombreTabla, char *nombreColS);
// elimina columna singular

// TipoRet eliminarTabla_Tablas(tablas & ts, char *nombreTabla);

TipoRet printdatatable_tablas(tablas ts, char *NombreTabla);



#endif
