#ifndef ATRIBUTOSINGULAR_H
#define ATRIBUTOSINGULAR_H

#include "atributo_simple.h"
#include "define.h"

typedef struct nodo_columnaSingular * columnaSingular;

void crearColumSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol);

char * getColumnaSingularNombre(columnaSingular &columna_singular);

columnaSingular columnaSingularNull();

char * getColumnaSingularTipoDato(columnaSingular cs);

char * getColumnaSingularCalificador(columnaSingular cs);

bool compararNombreColumnaSingular(columnaSingular cs, char * nombreC);

columnaSingular getColumnaSig_ColumnaSingular(columnaSingular columna_singular);

bool isColumnasSingularEmpty_ColumnasSingular(columnaSingular cs);

#endif