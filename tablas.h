// #ifndef TABLAS_H
// #define TABLAS_H

// #include "tabla.h"
// #include "define.h"

// typedef struct nodo_tablas * tablas;

// tablas crearTablas();
// // Crea el conjunto de tablas vacio.

// TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla);
// // Crea la tabla de nombre "nombreTabla" en tablas.

// void imprimirTablas(tablas ts);
// // Imprime las tablas de manera ordenada.

// tabla getT(tablas ts);


// #endif

#ifndef TABLAS_H
#define TABLAS_H

#include "tabla.h"
#include "define.h"

typedef struct nodo_tablas * tablas;

tablas crearTablas();
// Crea el conjunto de tablas vacio.

TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla);
// Crea la tabla de nombre "nombreTabla" en tablas.

void imprimirTablas(tablas ts);
// Imprime las tablas de manera ordenada.

TipoRet crearColumSingular_Columnas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// crea una columna dentro de una tabla.
// pre: tiene que existir una tabla.
// pre: no puede haber otra columna con el mismo nombre.
// pre: no puede haber 2 primary key

char * getColumnaSingularNombre_Tablas(tablas & ts);

bool isTablasEmpty_Tablas(tablas & ts);

bool isColumnasEmpty_Tablas(tablas & ts);

// tabla crearColumSingular_Tablas(char *NombreCol, char *tipoCol, char *calificadorCol);
void crearColumSingular_Tablas(tablas & ts, char *NombreCol, char *tipoCol, char *calificadorCol);

tablas crearColumnas_Tablas(tablas & ts);





#endif