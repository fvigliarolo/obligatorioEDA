#include "tabla.h"
#include <string.h>
#include <iostream>
// #include <stdbool.h> // para bool


using namespace std;

struct nodo_tabla{
	char * nombre;
	columnas colums;
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->colums = crearColumnasNULL();
	return t;
}

tabla crearColumnas_Tabla(tabla & t){
	t->colums = crearColumnas(); 
	return t;
}


char * nombreTabla(tabla t){
	return t->nombre;
}

columnas getColumnas(tabla t){
	return t->colums;
}

bool isColumnasEmpty_Tabla(tabla t){
	return isColumnasEmpty_Columnas(t->colums);
}

char * getColumnaSingularNombre_Tabla(tabla t){
	return getColumnaSingularNombre_Columnas(t->colums);
}

char * getColumnaSingularTipoDato_Tabla(tabla t){
	return getColumnaSingularTipoDato_Columnas(t->colums);
}

char * getColumnaSingularCalificador_Tabla(tabla t){
	return getColumnaSingularCalificador_Columnas(t->colums);
}

tabla getColumnaSig_Tabla(tabla t){
    t->colums = getColumnaSig_Columnas(t->colums);
	return t;
}

void crearColumSingular_Tabla(tabla t, char *NombreCol, char *tipoCol, char *calificadorCol){
	crearColumSingular_Columnas(t->colums, NombreCol, tipoCol, calificadorCol);
}

bool compararNombreColumnaSingular_Tabla(tabla t, char * nombreC){
	return compararNombreColumnaSingular_Columnas(t->colums, nombreC);
}
