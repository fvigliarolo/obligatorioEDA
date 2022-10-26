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

tabla crearColumnas_Tabla(tabla & t);

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

columnas getColumnas(tabla t);

char * getColumnaSingularNombre_Tabla(tabla t);

bool isColumnasEmpty_Tabla(tabla t);

void crearColumSingular_Tabla(tabla t, char *NombreCol, char *tipoCol, char *calificadorCol);

char * getColumnaSingularTipoDato_Tabla(tabla t);

char * getColumnaSingularCalificador_Tabla(tabla t);

tabla getColumnaSig_Tabla(tabla t);

bool compararNombreColumnaSingular_Tabla(tabla t, char * nombreC);

bool isColumnasSingularEmpty_Tabla(tabla t);

TipoRet dropTable_Tabla(tabla & PEPE, char *nombreTabla);

#endif