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
	// cout << "estoy volviendo del llamado getColumnaSig_Columnas \n";
	return t;
}

void crearColumSingular_Tabla(tabla t, char *NombreCol, char *tipoCol, char *calificadorCol){
	crearColumSingular_Columnas(t->colums, NombreCol, tipoCol, calificadorCol);
}

bool compararNombreColumnaSingular_Tabla(tabla t, char * nombreC){
	return compararNombreColumnaSingular_Columnas(t->colums, nombreC);
}

bool isColumnasSingularEmpty_Tabla(tabla t){
	return isColumnasSingularEmpty_Columnas(t->colums);
}
 TipoRet dropTable_Tabla(tabla & PEPE, char *nombreTabla){
		delete PEPE;
	 	//TENGO QUE APUNTAR PEPE A NULL
	 	PEPE = NULL; //TENGO QUE APUNTARLO A NULL 
		return OK;
 }

 TipoRet crearColumnaSingular_Tabla(tabla t, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){

	if (nombreTabla != t->nombre){
		cout << "No existe la tabla " << nombreTabla << "\n";
		return ERROR;
	}else{
		if(isColumnasEmpty_Columnas(t->colums)){
			crearColumnas_Tabla(t); // Creamos un new(nodo_tablas)
			crearColumSingular_Columnas(t->colums, NombreCol, tipoCol, calificadorCol);
			return OK;
		}else{
		return crearColumnaSingular_Columnas(t->colums, nombreTabla, NombreCol, tipoCol, calificadorCol);
	}

		// if(isColumnasEmpty_Tabla(ts)){
		// 	crearColumnas_Tablas(ts); // Creamos un new(nodo_tablas)
		// 	crearColumSingular_Tablas(ts, NombreCol, tipoCol, calificadorCol);

		// 	return OK;
		// }else{
		// 	bool aux = true;
		// 	do{
		// 		if(compararNombreColumnaSingular_Tablas(ts, NombreCol)){
		// 			cout << "Imposible Crear Columna. Ya existe una columna con el nombre\n";
		// 			aux = false;
		// 			return ERROR;
		// 		}else{
		// 			if(isColumnasSingularEmpty_Tablas(getColumnaSig_Tablas(ts))){
		// 				//si col siguiente no es null, seguimos comparando
		// 				ts = getColumnaSig_Tabl	as(ts);
		// 				// cout << getColumnaSig_Tablas(ts);
						
		// 			}else{
		// 				//si el siguiente es null, ya se compararon todas las colums y no hay repetido.
		// 				crearColumSingular_Tablas(ts, nombreTabla, tipoCol, calificadorCol);
		// 				aux = false;
		// 				return OK;
		// 			}
		// 		}
		// 	}while(aux);
		// }

 }

