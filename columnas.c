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
	// cout << "columna previa: " << col->columna_singular << "\n" << endl; 
	col->columna_singular = getColumnaSig_ColumnaSingular(col->columna_singular);
	cout << "columna: " << col->columna_singular << "\n" << endl; 
	return col;
}

bool isColumnasEmpty_Columnas(columnas col){
	return (col == NULL);
}


void crearColumSingular_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol){
	col->columna_singular = columnaSingularNull();
	crearColumSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol);
}

bool compararNombreColumnaSingular_Columnas(columnas col, char * nombreC){
	return compararNombreColumnaSingular(col->columna_singular, nombreC);
}

bool isColumnasSingularEmpty_Columnas(columnas col){
	return isColumnasSingularEmpty_ColumnasSingular(col->columna_singular);
}


