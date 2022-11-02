#include "tabla.h"
#include <string.h>
#include <iostream>
// #include <stdbool.h> // para bool


using namespace std;

struct nodo_tabla{
	char * nombre;
	columnas colums;
	tabla iz;
	tabla der;
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

//addColumn
 TipoRet crearColumnaSingular_Tabla(tabla t, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if (strcasecmp (nombreTabla, t->nombre) != 0){
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR;
	}else{
		bool primerCol;
		if(isColumnasEmpty_Columnas(t->colums)){
			primerCol = true;
			t->colums = crearColumnas(); // Creamos un new(nodo_columnas)
			crearColumnaSingular_Columnas(t->colums, NombreCol, tipoCol, calificadorCol, primerCol);
			return OK;
		}else{
			primerCol = false;
			return crearColumnaSingular_Columnas(t->colums, NombreCol, tipoCol, calificadorCol, primerCol);
		}		
	}
 }

// PrintMetaData()
TipoRet estructuraTablas_tabla(tabla t, char *nombreTabla){
	if (strcasecmp (nombreTabla, t->nombre) == 0){
		return estructuraTablas_Columnas(t->colums, nombreTabla);
	}else{
		cout << "La tabla no existe" << endl ;
		return ERROR;
	}
}


TipoRet InsertInto_Tabla(tabla & t, char *nombreTabla, char *columnasTupla, char *valoresTupla){
// buscar si existe la tabla
	return InsertInto_Columnas(t->colums, nombreTabla, columnasTupla, valoresTupla);
//else

}



