#include "columnaSingular.h"
#include "define.h"
#include "atributo_simple.h"
#include <string.h>
#include <iostream>


using namespace std;

struct nodo_columnaSingular{
	char * nombre;
	char * tipo_dato; 
	char * calificador;
	atributo_simple atr_simple;
	columnaSingular sig;	
};

// columnaSingular crearColumSingular(char *NombreCol, char *tipoCol, char *calificadorCol){

// 	cout << "nombre" << NombreCol << endl;
// 	cout << "tipocol" << tipoCol << endl;
// 	cout << "calificadorCol" << calificadorCol << endl;
// 	nodo_columnaSingular *columna_singular = new(nodo_columnaSingular);
// 	// 	asigna nombre
// 	columna_singular->nombre = new char[MAX_NOMBRE];
// 	strcpy(columna_singular->nombre, NombreCol);
// 	// asigna tipo
// 	columna_singular->tipo_dato = new char[MAX_NOMBRE];
// 	strcpy(columna_singular->tipo_dato, tipoCol);
// 	//
// 	columna_singular->calificador = calificadorCol;


// 	return columna_singular;
// }

// columnaSingular columnaSingularNull(){
// 	return NULL;
// }


columnaSingular columnaSingularNull(){
	return new(nodo_columnaSingular);
}


void crearColumSingular(columnaSingular cs, char *NombreCol, char *tipoCol, char *calificadorCol){

	// cout << cs;
	// cout << NombreCol;
	// cout << tipoCol;
	// cout << calificadorCol;

	// 	asigna nombre
	cs->nombre = new char[MAX_NOMBRE];
	strcpy(cs->nombre, NombreCol);

	// asigna tipo
	cs->tipo_dato = new char[MAX_NOMBRE];
	strcpy(cs->tipo_dato, tipoCol);
	//
	cs->calificador = calificadorCol;

	cout << "nombre: " << cs->nombre << "\n";
	cout << "tipo: " << cs->tipo_dato << "\n";
	cout << "calificador: " << cs->calificador << "\n";
}


char * getColumnaSingularNombre(columnaSingular columna_singular){
	columnaSingular cs = new(nodo_columnaSingular);
	cs->nombre = "tablita";
	return cs->nombre;
}

