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
		if (crearColumnaSingular_ColumnasSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol, primerCol) == ERROR){
			cout << "comparo bien" << endl ;
			return ERROR;
		}else{
			cout << "comparo mal" << endl ;
			return ERROR;
		}
	}else{
		return crearColumnaSingular_ColumnasSingular(col->columna_singular, NombreCol, tipoCol, calificadorCol, primerCol);
	}
}

// PrintMetaData()
TipoRet estructuraTablas_Columnas(columnas col, char *nombreTabla){
	return estructuraTablas_Columnasingular(col->columna_singular, nombreTabla);
}

TipoRet InsertInto_Columnas(columnas & col, char *columnasTupla, char *valoresTupla){

	char * param1;
	char * param2;

	char * param1Copia = new char[1000];
	strcpy(param1Copia, columnasTupla);

	char * param2Copia = new char[1000];
	strcpy(param2Copia, valoresTupla);

	int lenghtParm1 = 0;
	int lenghtParm2 = 0;
	int errores = 0;

	param1 = strtok(columnasTupla, ":");
	while(param1 != NULL){
	// cuento el largo del futuro array, y de paso verifica si existen las columnas
		if (!existeColumnaSingular(col->columna_singular, param1)){
			errores += 1;
			cout << "No existe el atributo: " << param1 << endl ;
		}
		lenghtParm1 += 1;
		param1 = strtok(NULL, ":");

	}
	param2 = strtok(valoresTupla, ":");
	while(param2 != NULL){
	// cuenta el largo del futuro array
		lenghtParm2 += 1;
		param2 = strtok(NULL, ":");

	}

	if (errores != 0){
		return ERROR;
	}else{
		if(lenghtParm1 == lenghtParm2){
			return InsertInto_ColumnasSingular(col->columna_singular, param1Copia, param2Copia, lenghtParm1, lenghtParm2);
		}else{
			return ERROR;
		}
	}

}

//Eliminar columna Singular
TipoRet EliminarColumnaSing_columnas(columnas Colum, char *NombreColS){
	if (!existeColumnaSingular(Colum->columna_singular, NombreColS)){
		cout << "No existe la columna " << NombreColS <<endl;
		return ERROR;
	}else{
		
		// if(colum->columnaSingular == NULL)
		// 	colum->columnaSingular = NULL;
		return eliminarColumnaSing(Colum->columna_singular, NombreColS);
	}

}