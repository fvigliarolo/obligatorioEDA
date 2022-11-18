#ifndef TABLA_H
#define TABLA_H

#include "columnas.h"
#include "define.h"

typedef struct nodo_tabla * tabla;

tabla crearTabla(char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

tabla eliminarTabla(tabla & t, char * nombreTabla);
//elimina la tabla y sus tuplas
//pre: la tabla a eliminar existe

// bool compararNombreTabla_tablas(tablas ts, char * nombreTabla); 
//Deberia funcionar bien, pues me compila

tabla crearColumnas_Tabla(tabla & t);

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

columnas getColumnas(tabla t);
// Retorna la estructura columnas de la tabla.

TipoRet crearColumnaSingular_Tabla(tabla t, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// crea una columna dentro de una tabla.
// pre: tiene que existir una tabla.
// pre: no puede haber otra columna con el mismo nombre.
// pre: no puede haber 2 primary key

TipoRet EliminarColumnaSing_tabla(tabla & t, char *nombreTabla, char *nombreColumS);
// Eliminar columna sing

TipoRet estructuraTablas_tabla(tabla & t, char *nombreTabla);
// Devuelve la estructura de las columnas de la tabla.

TipoRet InsertInto_Tabla(tabla & t, char *nombreTabla, char *columnasTupla, char *valoresTupla);
// Intenta realizar una insercion de datos en la tabla indicada por el usuario.


TipoRet printdatatable_tabla(tabla t, char *NombreTabla);

#endif
