#include "columnas.h"
#include <string.h>
#include <iostream>
#include <stdbool.h> // para bool

using namespace std;

struct nodo_columnas{
  	columnaSingular columna_singular;
};

columnas crearColumnas(){
	return new(nodo_columnas);
}

columnas crearColumnasNULL(){
	return NULL;
}

bool isColumnasEmpty_Columnas(columnas col){
	return (col == NULL);
}

//addColumn
TipoRet crearColumnaSingular_Columnas(columnas col, char *NombreCol, char *tipoCol, char *calificadorCol, bool primerCol){
	if (col->columna_singular == NULL){
		col->columna_singular = columnaSingularNull();
		return crearColumnaSingular_ColumnasSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol, primerCol);
	}else{
		return crearColumnaSingular_ColumnasSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol, primerCol);
	}
}

// PrintMetaData()
TipoRet estructuraTablas_Columnas(columnas col, char *nombreTabla){
	return estructuraTablas_Columnasingular(col->columna_singular, nombreTabla);
}

TipoRet InsertInto_Columnas(columnas & col, char *nombreTabla, char *columnasTupla, char *valoresTupla){

		bool aux1 = true;
		
		char * param1, * param2;
		int errores = 0;
		param1 = strtok (columnasTupla, ":");

		while(param1 != NULL){

			if (existeColumnaSingular(col->columna_singular, param1)){
				cout << "Existe el atributo: " << param1 << endl ;
			}else{
				cout << "No existe el atributo: " << param1 << endl ;
			}
			param1 = strtok (NULL, ":");

		// 	do{
		// 		if(getColumnaSingularNombre_Tabla(ts) == param1 ){
		// 			// existe la columna singular == param1. 
		// 			aux = false;
		// 		}else{insertInto(Personas, CI:Apellido:Nombre:teta 3333333:Gonzalez:Maria)

		// 				// si el siguiente es distinto de null, movemos a la siguiente columna_singular

		// 			}

		}
			// if (errores == 0){
			// 	InsertInto_ColumnasSingular()
			// }
		// 	}while(aux);
			
		// 	param1 = strtok (NULL, ":");
		// 	// obtenemos el siguiente parametro.
		// }

		// // if (errores){
		// // 	cout << "verifique las columnas";
		// // 	return ERROR;
		// // }else{
		// // 	//insertar bajo la columna_singular correspondiente
		// // 	param1 = strtok (columnasTupla, ":");
		// // 	while (parm1 != NULL){
		// // 		insertar_tabla(parm1);
		// // 		param1 = strtok (NULL, ":");

		// 	}
			return OK;
		}

// 	}
// }

