#include "columnaSingular.h"
#include <string.h>
#include <iostream>
#include <stdbool.h> // para bool



using namespace std;

struct nodo_columnaSingular{
	char * nombre;
	char * tipo_dato; 
	char * calificador;
	atributo_simple atr_simple;
	columnaSingular sig;	
};

columnaSingular columnaSingularNull(){
	return new(nodo_columnaSingular); //aca no tendri que ser return null?

}
// osea arriba creamos el nodo (el cual no sabemos si esta vacio) y luego lo dejamos null 

columnaSingular columnaSingularNULL(){
	return NULL;	
}

char * getColumnaSingularNombre(columnaSingular columna_singular){
	return columna_singular->nombre;

}

char * getColumnaSingularTipoDato(columnaSingular cs){
	return cs->tipo_dato;
}

char * getColumnaSingularCalificador(columnaSingular cs){
	return cs->calificador;
}

columnaSingular & getColumnaSig_ColumnaSingular(columnaSingular &columna_singular){
	return columna_singular->sig;
}


void crearColumSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol){

	// 	asigna nombre
	cs->nombre = new char[MAX_NOMBRE];
	strcpy(cs->nombre, NombreCol);

	// asigna tipo
	cs->tipo_dato = new char[MAX_NOMBRE];
	strcpy(cs->tipo_dato, tipoCol);
	//
	cs->calificador = calificadorCol;
}


bool compararNombreColumnaSingular(columnaSingular cs, char * nombreC){
	if (strcasecmp(nombreC, cs->nombre) == 0){
		return true;
	}else{
		return false;
	}
}



