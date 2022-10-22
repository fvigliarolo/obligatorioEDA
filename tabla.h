// #ifndef TABLA_H
// #define TABLA_H

// #include "define.h"

// typedef struct nodo_tabla * tabla;

// tabla crearTabla(char * nombreTabla);
// // Crea una tabla de nombre "nombreTabla".

// tabla eliminarTabla(char * nombreTabla);
// //elimina la tabla y sus tuplas
// //pre: la tabla a eliminar existe


// char * nombreTabla(tabla t);
// // Retorna el nombre de t.
// // Pre: t creada previamente.

// // columnas getColumnas(tabla t);

// #endif

#ifndef TABLA_H
#define TABLA_H

#include "columnas.h"
#include "define.h"

typedef struct nodo_tabla * tabla;

tabla crearTabla(char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

tabla eliminarTabla(char * nombreTabla);
//elimina la tabla y sus tuplas
//pre: la tabla a eliminar existe

tabla crearColumnas_Tabla();

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

columnas getColumnas(tabla t);

char * getColumnaSingularNombre_Tabla(tabla t);

bool isColumnasEmpty_Tabla(tabla t);

// columnas crearColumSingular_Tabla(char *NombreCol, char *tipoCol, char *calificadorCol);
void crearColumSingular_Tabla(tabla t, char *NombreCol, char *tipoCol, char *calificadorCol);





#endif