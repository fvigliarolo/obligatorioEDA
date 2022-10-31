#include "columnas.h"
#include <string.h>
#include <iostream>
#include <stdbool.h> // para bool

using namespace std;

struct nodo_columnas{
  	columnaSingular columna_singular;
	// columnas sig;
};


columnas crearColumnas(){
	return new(nodo_columnas);
}

columnas crearColumnasNULL(){
	return NULL;
}

char * getColumnaSingularNombre_Columnas(columnas col){
	return getColumnaSingularNombre(col->columna_singular);
}

char * getColumnaSingularTipoDato_Columnas(columnas col){
	return getColumnaSingularTipoDato(col->columna_singular);
}

char * getColumnaSingularCalificador_Columnas(columnas col){
	return getColumnaSingularCalificador(col->columna_singular);
}

columnas getColumnaSig_Columnas(columnas col){
	col->columna_singular = getColumnaSig_ColumnaSingular(col->columna_singular);
	return col;
}

bool isColumnasEmpty_Columnas(columnas col){
	return (col == NULL);
}


// void crearColumnaSingularVOID_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol){
// }

bool compararNombreColumnaSingular_Columnas(columnas col, char * nombreC){
	return compararNombreColumnaSingular(col->columna_singular, nombreC);
}

bool isColumnasSingularEmpty_Columnas(columnas col){
	return isColumnasSingularEmpty_ColumnasSingular(col->columna_singular);
}


TipoRet crearColumnaSingular_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol){
	if (col->columna_singular == NULL){
		col->columna_singular = columnaSingularNull();
		return crearColumnaSingular_ColumnasSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol, primerCol);
	}else{
		return crearColumnaSingular_ColumnasSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol, primerCol);
	}
}

TipoRet estructuraTablas_Columnas(columnas col, char *nombreTabla){
	return estructuraTablas_Columnasingular(col->columna_singular, nombreTabla);
}


