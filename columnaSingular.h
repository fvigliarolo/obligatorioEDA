#ifndef ATRIBUTOSINGULAR_H
#define ATRIBUTOSINGULAR_H

#include "atributo_simple.h"
#include "define.h"

typedef struct nodo_columnaSingular * columnaSingular;

columnaSingular columnaSingularNull();

columnaSingular columnaSingularNULL();

void crearColumSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol);

bool isColumnaSingularEmpty(columnaSingular cs);

bool compararNombreColumnaSingular(columnaSingular cs, char * nombreC);

TipoRet crearColumnaSingular_ColumnasSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol);
// Agrega una columna nueva a la tabla.

TipoRet estructuraTablas_Columnasingular(columnaSingular & cs, char *nombreTabla);
// Devuelve la estructura de las columnas de la tabla.

void imprimirColumnaSingular(columnaSingular & cs);
// Imprime datos de columna singular.

columnaSingular primerPosicion(columnaSingular cs);

columnaSingular igualarCSaColumna(columnaSingular cs, char *dato);

TipoRet InsertInto_ColumnasSingular(columnaSingular & cs, char *columnasTupla, char *valoresTupla, int lenghtColumnasTupla, int lenghtValoresTupla);

columnaSingular eliminarColumnaSing(columnaSingular & cs,char *NombreColumnaSingular);

void eliminarC(columnaSingular & cs, char *NombreColumnaSingular);

bool verificaTipoDato(columnaSingular cs, char *dato, char *columna);

void imprimircs(columnaSingular cs);

int RandomString(int ch);


#endif